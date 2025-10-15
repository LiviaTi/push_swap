/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 09:21:33 by liferrei          #+#    #+#             */
/*   Updated: 2025/10/15 18:05:57 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	n_min(t_list **n)
{
	int		min;
	t_list	*list;

	if (!n || !*n)
		return (0); 
	min = (*n)->number;
	list = (*n)->next;
	while (list != NULL)
	{
		if (list->number < min)
			min = list->number;
		list = list->next;
	}
	return (min);
}

int	n_max(t_list **n)
{
	int		max;
	t_list	*list;

	if (!n || !*n)
		return (0);
	max = (*n)->number;
	list = (*n)->next;
	while (list)
	{
		if (list->number > max)
			max = list->number;
		list = list->next;
	}
	return (max);
}

int	ft_index_max(t_list **n)
{
	int		max;
	t_list	*list;

	list = *n;
	max = list->index;
	list = list->next;
	while (list)
	{
		if (list->index > max)
			max = list->index;
		list = list->next;
	}
	return (max);
}

int	ft_is_organize(t_list **n)
{
	t_list		*tmp;

	if (!n || !*n)
		return (1);
	tmp = *n;
	while (tmp && tmp->next)
	{
		if (tmp->number > tmp->next->number)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
