/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 15:41:53 by liferrei          #+#    #+#             */
/*   Updated: 2025/10/15 17:08:04 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_reverse_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = NULL;
	last = *stack;
	while (last->next)
	{
		first = last;
		last = last->next;
	}
	last->next = *stack;
	*stack = last;
	first->next = NULL;
}

void	rra(t_list **tower_a)
{
	ft_reverse_rotate(tower_a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **tower_b)
{
	ft_reverse_rotate(tower_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **tower_a, t_list **tower_b)
{
	ft_reverse_rotate(tower_a);
	ft_reverse_rotate(tower_b);
	write(1, "rrr\n", 4);
}
