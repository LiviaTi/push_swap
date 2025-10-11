/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:22:40 by liferrei          #+#    #+#             */
/*   Updated: 2025/10/10 15:57:46 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_check_rep(t_list **n)
{
	t_list	*tmp_1;
	t_list	*tmp_2;

	tmp_1 = n;
	while (tmp_1)
	{
		tmp_2 = tmp_1->next;
		while (tmp_2)
		{
			if (tmp_1->number == tmp_2->number)
				ft_error_exit();
			tmp_2 = tmp_2->next;
		}
		tmp_1 = tmp_1->next;
	}
}
