/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 09:07:50 by liferrei          #+#    #+#             */
/*   Updated: 2025/10/17 14:11:32 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				number;
	int				index;
	struct s_list	*next;
}					t_list;

void	ft_error_exit(void);
int		ft_parse_input(int argc, char **argv, t_list **a);
int		ft_parse_number(const char *str);
void	ft_check_rep(t_list **a);
int		ft_fill_tower(char **args, t_list **a);

void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **list_a, t_list **list_b);

void	pa(t_list **list_a, t_list **list_b);
void	pb(t_list **list_a, t_list **list_b);

void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **list_a, t_list **list_b);

void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **list_a, t_list **list_b);

void	ft_lst_add_back(t_list **a, t_list *new_node);
int		lst_size(t_list *list);
void	ft_cleanup(t_list **a, t_list **b);
void	ft_free_stack(t_list **stack);
void	ft_free_split(char **args);

int		ft_is_organize(t_list **a);
void	ft_organize(t_list **a, t_list **b, int size);
void	ft_organize_2(t_list **a);
void	ft_organize_3(t_list **a);
void	ft_organize_4_5(t_list **a, t_list **b, int size);
void	ft_organize_big(t_list **a, t_list **b, int chunk_size);

void	ft_set_index(t_list **a);
int		max_pos(t_list **b, int max_index, int size);
int		min_pos(t_list **a, int min, int size);
void	ft_organize_pa(t_list **a, t_list **b);

int		n_min(t_list **a);
int		n_max(t_list **a);
int		ft_index_max(t_list **a);

#endif