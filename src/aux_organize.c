/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_organize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:02:48 by liferrei          #+#    #+#             */
/*   Updated: 2025/10/11 16:38:27 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_max_pos(t_list **b, int max_index, int size)
{
	t_list	*n;
	int		index;
	int		found;

	index = 0;
	found = 0;
	n = *b;
	while (n && !found)
	{
		if (n->index == max_index)
			found = 1;
		else
			index++;
		n = n->next;
	}
	if (index < size / 2 + size % 2)
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