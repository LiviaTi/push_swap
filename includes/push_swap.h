/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 09:07:50 by liferrei          #+#    #+#             */
/*   Updated: 2025/10/11 15:39:47 by liferrei         ###   ########.fr       */
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

void	sa(t_list **list_a);
void	sb(t_list **list_b);
void	ss(t_list **list_a, t_list **list_b);

void	pa(t_list **list_a, t_list **list_b);
void	pb(t_list **list_a, t_list **list_b);

void	ra(t_list **list_a);
void	rb(t_list **list_b);
void	rr(t_list **list_a, t_list **list_b);



#endif
