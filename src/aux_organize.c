/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_organize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:02:48 by liferrei          #+#    #+#             */
/*   Updated: 2025/10/15 15:13:32 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	max_pos(t_list **b, int max_index, int size)
{
	t_list	*p;
	int		index;
	int		found;

	index = 0;
	found = 0;
	p = *b;
	while (p && !found)
	{
		if (p->index == max_index)
			found = 1;
		else
			index++;
		p = p->next;
	}
	if (index < size / 2 + size % 2)
		return (0);
	else
		return (1);
}

int	min_pos(t_list **a, int min, int size)
{
	t_list	*p;
	int		min_index;
	int		found;

	min_index = 0;
	found = 0;
	p = *a;
	while (p != NULL && !found)
	{
		if (p->number == min)
			found = 1;
		else
			min_index++;
		p = p->next;
	}
	if (min_index < size / 2 + size % 2)
		return (0);
	else
		return (1);
}

void	ft_set_index(t_list **a)
{
	t_list	*current;
	t_list	*comparer;
	int		index;

	current = *a;
	while (current)
	{
		comparer = *a;
		index = 0;
		while (comparer)
		{
			if (current->number > comparer->number)
				index++;
			comparer = comparer->next;
		}
		current->index = index;
		current = current->next;
	}
}

void	ft_organize_pa(t_list **a, t_list **b)
{
	while (*b != NULL)
	{
		int max = ft_index_max(b);
		int size_b = lst_size(*b);

		if ((*b)->index != max)
		{
			if (!max_pos(b, max, size_b))
				rb(b);
			else
				rrb(b);
		}
		else
			pa(a, b);
	}
}
