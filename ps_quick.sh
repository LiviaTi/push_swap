#!/usr/bin/env bash
# Teste simples: push_swap + checker (sem valgrind e sem limites)
# Uso:
#   ./ps_quick.sh                # bateria padrão
#   ./ps_quick.sh --quick        # menos casos (mais rápido)
#   CHECKER=./checker_OS ./ps_quick.sh   # escolher checker específico

set -euo pipefail

PUSH_SWAP="./push_swap"
CHECKER="${CHECKER-}"

# Detecta checker automaticamente se não for informado
if [[ -z "${CHECKER}" ]]; then
  if [[ -x ./checker ]]; then
    CHECKER=./checker
  elif [[ -x ./checker_OS ]]; then
    CHECKER=./checker_OS
  else
    echo "❌ Nenhum checker encontrado aqui. Defina a var CHECKER ou coloque ./checker(_OS) na pasta."
    echo "   Ex.: CHECKER=/caminho/para/checker ./ps_quick.sh"
    exit 1
  fi
fi

need() { command -v "$1" >/dev/null 2>&1 || { echo "Falta: $1"; exit 1; }; }
need shuf

ROUNDS_SMALL=10   # 3 e 5 números
ROUNDS_20=10      # 20 números
ROUNDS_100=3      # 100 números

if [[ "${1-}" == "--quick" ]]; then
  ROUNDS_SMALL=3
  ROUNDS_20=3
  ROUNDS_100=1
fi

run_one () { # args -> imprime "OK/KO/Error (N ops) | args"
  local args="$1"
  local ops count res
  ops="$("$PUSH_SWAP" $args)"
  count=$(printf "%s\n" "$ops" | sed '/^$/d' | wc -l)
  res=$(printf "%s\n" "$ops" | "$CHECKER" $args || true)
  echo "$res ($count ops) | $args"
}

echo "==== Casos fixos ===="
run_one "2 1 3 6 5 8"
run_one "3 2 1"
run_one "1 5 2 4 3"

echo
echo "==== Inválidos (devem imprimir Error) ===="
for bad in "0 one 2 3" "1 1 2" "2147483648 1" "-2147483649 2" ""; do
  out="$("$PUSH_SWAP" $bad 2>&1 || true)"
  # Normalmente o checker não é chamado para inválidos, só mostramos saída do push_swap
  printf "[%s] -> %s\n" "$bad" "${out:-<no output>}"
done

echo
echo "==== Aleatórios: 3 e 5 números (${ROUNDS_SMALL} rodadas cada) ===="
for n in 3 5; do
  for ((i=1;i<=ROUNDS_SMALL;i++)); do
    args="$(shuf -i 0-100 -n $n | xargs)"
    run_one "$args"
  done
done

echo
echo "==== Aleatórios: 20 números (${ROUNDS_20} rodadas) ===="
for ((i=1;i<=ROUNDS_20;i++)); do
  args="$(shuf -i 0-500 -n 20 | xargs)"
  run_one "$args"
done

echo
echo "==== Aleatórios: 100 números (${ROUNDS_100} rodadas) ===="
for ((i=1;i<=ROUNDS_100;i++)); do
  args="$(shuf -i 0-9999 -n 100 | xargs)"
  run_one "$args"
done
