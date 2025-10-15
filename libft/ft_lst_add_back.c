/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 00:51:54 by liferrei          #+#    #+#             */
/*   Updated: 2025/10/15 14:53:48 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_add_back(t_list **a, t_list *new_node)
{
	t_list	*last;

	if (!new_node)
		return ;
	if (*a == NULL)
	{
		*a = new_node;
		return ;
	}
	last = *a;
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
}
