#!/usr/bin/env bash
# push_swap test suite (sem bônus): correção, contagem de movimentos e valgrind
# Uso: ./valgrind_test.sh [--quick]
# --quick: reduz número de rodadas para execução mais rápida

set -euo pipefail

# =========================
# Config
# =========================
PUSH_SWAP="./push_swap"
VALGRIND_OPTS="--leak-check=full --show-leak-kinds=all --error-exitcode=1"
RANDOM_RANGE_SMALL="0-100"
RANDOM_RANGE_BIG="0-9999"

# Alvos do enunciado (nota máxima)
MAX_OPS_100=700
MAX_OPS_500=5500

# Alvos mínimos alternativos (qualquer combinação válida já passa)
MIN_OPS_100_A=1100; MIN_OPS_500_A=8500
MIN_OPS_100_B=700;  MIN_OPS_500_B=11500
MIN_OPS_100_C=1300; MIN_OPS_500_C=5500

# Rodadas
ROUNDS_SMALL=10   # casos com 3 e 5 números
ROUNDS_20=10      # casos com 20 números
ROUNDS_100=5      # casos com 100 números
ROUNDS_500=2      # casos com 500 números
VALGRIND_SAMPLES=3

if [[ "${1-}" == "--quick" ]]; then
  ROUNDS_SMALL=3
  ROUNDS_20=3
  ROUNDS_100=2
  ROUNDS_500=1
  VALGRIND_SAMPLES=1
fi

# =========================
# Dependências
# =========================
need() { command -v "$1" >/dev/null 2>&1 || { echo "Falta a dependência: $1"; exit 1; }; }
need awk
need shuf
need valgrind
[[ -x "$PUSH_SWAP" ]] || { echo "Binário não encontrado: $PUSH_SWAP"; exit 1; }

# =========================
# Checker interno (awk)
# Aplica as operações em pilhas a/b e verifica se a fica ordenada e b vazia
# =========================
ps_awk_checker() {
  awk '
  function push(arr, n,   i){i=++arr["n"]; arr[i]=n}
  function pop(arr,   n, i){i=arr["n"]; if(i<1) return ""; n=arr[i]; delete arr[i]; arr["n"]=i-1; return n}
  function top(arr){return arr[arr["n"]]}
  function rotate_up(arr,   i,n,tmp){n=arr["n"]; if(n<2) return; tmp=arr[1]; for(i=1;i<n;i++) arr[i]=arr[i+1]; arr[n]=tmp}
  function rotate_down(arr, i,n,tmp){n=arr["n"]; if(n<2) return; tmp=arr[n]; for(i=n;i>1;i--) arr[i]=arr[i-1]; arr[1]=tmp}
  function swap_top(arr,   n,tmp){n=arr["n"]; if(n<2) return; tmp=arr[n]; arr[n]=arr[n-1]; arr[n-1]=tmp}
  function is_sorted(arr,   i,n){n=arr["n"]; for(i=n;i>1;i--) if(arr[i]<arr[i-1]) return 0; return 1}
  BEGIN{
    # carrega pilha a a partir dos ARGV (números)
    a["n"]=0; b["n"]=0
    for(i=1;i<ARGC;i++) push(a, ARGV[i])
    # lê operações de stdin e aplica
    while((getline op)>0){
      if(op=="sa") swap_top(a)
      else if(op=="sb") swap_top(b)
      else if(op=="ss"){swap_top(a); swap_top(b)}
      else if(op=="pa"){x=pop(b); if(x!="") push(a,x)}
      else if(op=="pb"){x=pop(a); if(x!="") push(b,x)}
      else if(op=="ra") rotate_up(a)
      else if(op=="rb") rotate_up(b)
      else if(op=="rr"){rotate_up(a); rotate_up(b)}
      else if(op=="rra") rotate_down(a)
      else if(op=="rrb") rotate_down(b)
      else if(op=="rrr"){rotate_down(a); rotate_down(b)}
      else if(op=="") { /* ignora linhas vazias */ }
      else { print "Error"; exit 2 } # instrução inválida
    }
    if(is_sorted(a) && b["n"]==0){ print "OK"; exit 0 } else { print "KO"; exit 1 }
  }' "$@"
}

# =========================
# Helpers
# =========================
rand_unique() { # rand_unique N RANGE (ex: rand_unique 5 0-100)
  local n="$1" range="$2"
  shuf -i "$range" -n "$n"
}

run_case() { # run_case "arg list"
  local args="$1"
  local ops count res
  ops="$("$PUSH_SWAP" $args)"
  count=$(printf "%s\n" "$ops" | sed '/^$/d' | wc -l)
  res=$(printf "%s\n" "$ops" | ps_awk_checker $args || true)
  if [[ "$res" == "OK" ]]; then
    echo "OK ($count ops)"
    return 0
  elif [[ "$res" == "KO" ]]; then
    echo "KO ($count ops)"
    return 1
  else
    echo "Error ($count ops)"
    return 2
  fi
}

run_valgrind_case() { # run_valgrind_case "arg list"
  local args="$1"
  # roda valgrind contra o push_swap (sem pipe)
  valgrind $VALGRIND_OPTS "$PUSH_SWAP" $args >/dev/null
}

banner() { echo -e "\n==== $* ===="; }

# =========================
# Testes
# =========================
fail=0
pass_ops_100=0
pass_ops_500=0
min_combo_A=0
min_combo_B=0
min_combo_C=0

banner "Smoke tests (comportamento básico)"
# Sem argumentos -> sem saída
out=$("$PUSH_SWAP" || true)
[[ -z "$out" ]] && echo "OK: sem argumentos não imprime nada" || { echo "FAIL: sem args imprimiu algo"; fail=1; }

# Inputs inválidos
for bad in "0 one 2 3" "1 1 2" "2147483648 1" "-2147483649 2" ""; do
  set +e
  "$PUSH_SWAP" $bad >/dev/null 2>err || true
  set -e
  if grep -qx "Error" err; then echo "OK: erro detectado para: [$bad]"; else echo "FAIL: não detectou erro em: [$bad]"; fail=1; fi
done
rm -f err

banner "Casos pequenos (3 e 5 números) – $ROUNDS_SMALL rodadas cada"
for n in 3 5; do
  for ((i=1;i<=ROUNDS_SMALL;i++)); do
    args="$(rand_unique "$n" "$RANDOM_RANGE_SMALL" | xargs)"
    echo -n "$n nums: $args -> "
    run_case "$args" || fail=1
  done
done

banner "Casos médios (20 números) – $ROUNDS_20 rodadas"
for ((i=1;i<=ROUNDS_20;i++)); do
  args="$(rand_unique 20 "$RANDOM_RANGE_SMALL" | xargs)"
  echo -n "20 nums: -> "
  run_case "$args" || fail=1
done

banner "Benchmarks (100 números) – $ROUNDS_100 rodadas"
for ((i=1;i<=ROUNDS_100;i++)); do
  args="$(rand_unique 100 "$RANDOM_RANGE_BIG" | xargs)"
  ops="$("$PUSH_SWAP" $args)"
  count=$(printf "%s\n" "$ops" | sed '/^$/d' | wc -l)
  res=$(printf "%s\n" "$ops" | ps_awk_checker $args || true)
  if [[ "$res" == "OK" ]]; then
    status="OK"
    [[ "$count" -lt "$MAX_OPS_100" ]] && pass_ops_100=$((pass_ops_100+1))
    [[ "$count" -lt "$MIN_OPS_100_A" ]] && aOK=1 || aOK=0
  else
    status="$res"
    fail=1
  fi
  echo "100 nums: $status ($count ops)"
  # guarda contagem para combos mínimos
  counts100+=("$count")
done

banner "Benchmarks (500 números) – $ROUNDS_500 rodadas"
for ((i=1;i<=ROUNDS_500;i++)); do
  args="$(rand_unique 500 "$RANDOM_RANGE_BIG" | xargs)"
  ops="$("$PUSH_SWAP" $args)"
  count=$(printf "%s\n" "$ops" | sed '/^$/d' | wc -l)
  res=$(printf "%s\n" "$ops" | ps_awk_checker $args || true)
  if [[ "$res" == "OK" ]]; then
    status="OK"
    [[ "$count" -le "$MAX_OPS_500" ]] && pass_ops_500=$((pass_ops_500+1))
  else
    status="$res"
    fail=1
  fi
  echo "500 nums: $status ($count ops)"
  counts500+=("$count")
done

# Avaliação por combos mínimos (qualquer combinação válida já passa)
# A ideia aqui é: se TODAS as rodadas de 100 ficaram abaixo de X e TODAS as de 500 abaixo de Y, marca combo.
combo_all_below() { # thresh counts...
  local th="$1"; shift
  for v in "$@"; do [[ "$v" -lt "$th" ]] || return 1; done
  return 0
}
if [[ "${#counts100[@]:-0}" -gt 0 && "${#counts500[@]:-0}" -gt 0 ]]; then
  combo_all_below "$MIN_OPS_100_A" "${counts100[@]}" && \
  combo_all_below "$MIN_OPS_500_A" "${counts500[@]}" && min_combo_A=1 || true

  combo_all_below "$MIN_OPS_100_B" "${counts100[@]}" && \
  combo_all_below "$MIN_OPS_500_B" "${counts500[@]}" && min_combo_B=1 || true

  combo_all_below "$MIN_OPS_100_C" "${counts100[@]}" && \
  combo_all_below "$MIN_OPS_500_C" "${counts500[@]}" && min_combo_C=1 || true
fi

banner "Valgrind (amostras aleatórias) – $VALGRIND_SAMPLES rodadas"
for ((i=1;i<=VALGRIND_SAMPLES;i++)); do
  args="$(rand_unique 5 "$RANDOM_RANGE_SMALL" | xargs)"
  echo -n "valgrind 5 nums: $args -> "
  if run_valgrind_case "$args"; then echo "OK (sem leaks)"; else echo "FAIL (leak/erro de memória)"; fail=1; fi
done

banner "Resumo"
echo "100 nums < $MAX_OPS_100 ops (nota máxima) : $pass_ops_100 / $ROUNDS_100 rodadas atingiram"
echo "500 nums <= $MAX_OPS_500 ops (nota máxima): $pass_ops_500 / $ROUNDS_500 rodadas atingiram"
echo "Combos mínimos aceitos pelo enunciado:"
echo " - 100 < $MIN_OPS_100_A e 500 < $MIN_OPS_500_A : $([[ $min_combo_A -eq 1 ]] && echo PASS || echo FAIL)"
echo " - 100 < $MIN_OPS_100_B e 500 < $MIN_OPS_500_B : $([[ $min_combo_B -eq 1 ]] && echo PASS || echo FAIL)"
echo " - 100 < $MIN_OPS_100_C e 500 < $MIN_OPS_500_C : $([[ $min_combo_C -eq 1 ]] && echo PASS || echo FAIL)"

if [[ "$fail" -eq 0 ]]; then
  echo -e "\n✅ RESULTADO GERAL: PASS (correto, sem leaks e dentro dos limites em parte dos testes)"
else
  echo -e "\n❌ RESULTADO GERAL: FAIL (veja mensagens acima)"
  exit 1
fi
