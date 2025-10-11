/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 15:54:20 by liferrei          #+#    #+#             */
/*   Updated: 2025/10/11 16:57:33 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_organize(t_list **a, t_list **b, int size)
{
	if (size >= 2 && size <= 5)
	{
		if (size == 2)
			ft_organize_2(a);
		else if (size == 3)
			ft_organize_3(a);
		else if (size == 4 || size == 5)
			ft_organize_4_5(a, b, size);
	}
	if (size >= 6)
	{
		ft_set_index(a);
		if (size <= 100)
			ft_organize_big(a, b, 15);
		else
			ft_organize_big(a, b, 30);
	}
}

void	ft_organize_2(t_list **a)
{
	if ((*a)->next->number < (*a)->number)
		sa(a);
}

void	ft_organize_3(t_list **a)
{
	if ((*a)->number == n_max(a))
	{
		ra(a);
		if ((*a)->number > (*a)->next->number)
			sa(a);
	}
	else if ((*a)->number == n_min(a) && (*a)->number == n_max(a))
	{
		rra(a);
		sa(a);
	}
	else if ((*a)->number == n_min(a) && (*a)->number > (*a)->next->number)
		sa(a);
	else if ((*a)->number == n_min(a) && (*a)->number < (*a)->next->number)
		rra(a);
}

void	ft_organize_4_5(t_list **a, t_list **b, int size)
{
	int		i;

	i = 0;
	while (i < size / 2 + size % 2)
	{
		if ((*a)->number > n_max(a) && !min_pos(a, n_max(a), lst_size(a)))
			ra(a);
		else if ((*a)->number > n_max(a) && min_pos(a, n_max(a), lst_size(a)))
			rra(a);
		else if ((*a)->number == ft_n_min(a))
		{
			pb(a, b);
			i++;
		}
	}
	if ((*a)->number != n_min(a))
		sa(a);
	while ((*b))
		pa(a, b);
}

void	ft_organize_big(t_list **a, t_list **b, int size_chunk)
{
	int		i;

	i = 0;
	while ((*a))
	{
		if (i > 0 && (*a)->index < i)
		{
			pb(a, b);
			if ((*a) && (*a)->index >= i + size_chunk)
				rr(a, b);
			else
				rb(b);
			i++;
		}
		else if ((*a)->index < i + size_chunk)
		{
			pb(a, b);
			i++;
		}
		else if ((*a)->index >= i + size_chunk)
			ra(a);
	}
	ft_organize(a, b);
}
