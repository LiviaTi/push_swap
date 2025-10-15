/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 15:32:03 by liferrei          #+#    #+#             */
/*   Updated: 2025/10/15 17:59:21 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_list **tower_a, t_list **tower_b)
{
	t_list		*tmp;

	if (!tower_b || !*tower_b)
		return ; 
	tmp = *tower_b;
	*tower_b = tmp->next;
	tmp->next = *tower_a;
	*tower_a = tmp;
	write(1, "pa\n", 3);
}

void	pb(t_list **tower_a, t_list **tower_b)
{
	t_list		*tmp;

	if (!tower_b || !*tower_b)
		return ; 
	tmp = *tower_a;
	*tower_a = tmp->next;
	tmp->next = *tower_b;
	*tower_b = tmp;
	write(1, "pb\n", 3);
}
