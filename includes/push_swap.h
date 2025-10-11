/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 09:07:50 by liferrei          #+#    #+#             */
/*   Updated: 2025/10/11 16:52:30 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>


void	ft_error_exit(void);
int		ft_parse_input(int argc, char **argv, t_list **tower_a);
int		ft_parse_number(const char *str);
void	ft_check_rep(t_list **n);

int		ft_n_min(t_list **n);
int		ft_n_max(t_list **n);
int		ft_index_max(t_list **n);
int		ft_is_chosen(t_list **n);

void	sa(t_list **tower_a);
void	sb(t_list **tower_b);
void	ss(t_list **tower_a, t_list **tower_b);

void	pa(t_list **tower_a, t_list **tower_b);
void	pb(t_list **tower_a, t_list **tower_b);

void	ra(t_list **tower_a);
void	rb(t_list **tower_b);
void	rr(t_list **tower_a, t_list **tower_b);

void	rra(t_list **tower_a);
void	rrb(t_list **tower_b);
void	rrr(t_list **tower_a, t_list **tower_b);

void	ft_organize(t_list **a, t_list **b, int size);
void	ft_organize_2(t_list **a);
void	ft_organize_3(t_list **a);
void	ft_organize_4_5(t_list **a);
void	ft_organize_big(t_list **a, t_list **b, int size_chunk);

void	ft_set_index(t_list **a);
int		ft_max_pos(t_list **b, int max, int size);
int		ft_min_pos(t_list **a, int min, int size);
void	ft_organize_pa(t_list **a, t_list **b);

#endif
