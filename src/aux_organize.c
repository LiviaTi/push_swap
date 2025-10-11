/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_organize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:02:48 by liferrei          #+#    #+#             */
/*   Updated: 2025/10/11 16:52:23 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_max_pos(t_list **b, int max, int size)
{
	t_list	*n;
	int		max_index;
	int		found;

	max_index = 0;
	found = 0;
	n = *b;
	while (n && !found)
	{
		if (n->index == max)
			found = 1;
		else
			max_index++;
		n = n->next;
	}
	if (max_index < size / 2 + size % 2)
		return (0);
	else
		return (1);
}

int		ft_min_pos(t_list **a, int min, int size)
{
	t_list	*n;
	int		min_index;
	int		found;

	min_index = 0;
	found = 0;
	n = *a;
	while (n && !found)
	{
		if (n->index == min)
			found = 1;
		else
			min_index++;
		n = n->next;
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
	
	index = 0;
	current = *a;
	while (current)
	{
		comparer = *a;
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
	int		max;
	int		size;
	
	max = 0;
	size = 0;
	while(*b)
	{
		max = ft_index_max(b); 
		size = ft_lst_size(b);

		if ((*b)->index != max)
		{
			if (!ft_max_pos(b, max, size))
				rb(b);
			else
				rrb(b);
		}
		else
			pa(a, b);
	}
}