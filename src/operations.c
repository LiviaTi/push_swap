/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 09:21:33 by liferrei          #+#    #+#             */
/*   Updated: 2025/10/10 17:40:14 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_n_min(t_list **n)
{
	int		min;
	t_list	*list;
	
	min = (*n)->number;
	list = (*n)->next;
	while(list)
	{
		if(list->number < min)
			min = list->next;
		n = n->next;
	}
	return (min);
}

int	ft_n_max(t_list **n)
{
	int		max;
	t_list	*list;
	
	max = (*n)->number;
	list = (*n)->next;
	while(list)
	{
		if(list->number > max)
			max = list->next;
		n = n->next;
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
	
	while(list)
	{
		if(list->index > max)
			max = list->index;
		n = n->next;
	}
	return (max);
}

int ft_is_chosen(t_list **n)
{
	t_list		*tmp;
	
	tmp = *n;
	while(tmp)
	{
		if (tmp->number > tmp->next->number)
			return(0);
		tmp= tmp->next;
	}
	return (1);
}