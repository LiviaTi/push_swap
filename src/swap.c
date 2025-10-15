/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:31:28 by liferrei          #+#    #+#             */
/*   Updated: 2025/10/15 17:08:47 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second ->next;
	second->next = first;
	*stack = second;
}

void	sa(t_list **tower_a)
{
	ft_swap(tower_a);
	write(1, "sa\n", 3);
}

void	sb(t_list **tower_b)
{
	ft_swap(tower_b);
	write(1, "sb\n", 3);
}

void	ss(t_list **tower_a, t_list **tower_b)
{
	ft_swap(tower_a);
	ft_swap(tower_b);
	write(1, "ss\n", 3);
}
