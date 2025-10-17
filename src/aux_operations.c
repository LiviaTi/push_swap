/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 09:21:33 by liferrei          #+#    #+#             */
/*   Updated: 2025/10/17 14:18:46 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	n_min(t_list **a)
{
	int		min;
	t_list	*p;

	min = (*a)->number;
	p = (*a)->next;
	while (p != NULL)
	{
		if (p->number < min)
			min = p->number;
		p = p->next;
	}
	return (min);
}

int	n_max(t_list **a)
{
	int		max;
	t_list	*p;

	max = (*a)->number;
	p = (*a)->next;
	while (p != NULL)
	{
		if (p->number > max)
			max = p->number;
		p = p->next;
	}
	return (max);
}

int	ft_index_max(t_list **a)
{
	int		max_index;
	t_list	*p;

	p = *a;
	max_index = p->index;
	p = p->next;
	while (p != NULL)
	{
		if (max_index < p->index)
			max_index = p->index;
		p = p->next;
	}
	return (max_index);
}

int	ft_is_organize(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (tmp->number > tmp->next->number)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
