/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 15:18:45 by liferrei          #+#    #+#             */
/*   Updated: 2025/10/15 17:08:33 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_list **tower_a)
{
	ft_rotate(tower_a);
	write(1, "ra\n", 3);
}

void	rb(t_list **tower_b)
{
	ft_rotate(tower_b);
	write(1, "rb\n", 3);
}

void	rr(t_list **tower_a, t_list **tower_b)
{
	ft_rotate(tower_a);
	ft_rotate(tower_b);
	write(1, "rr\n", 3);
}
