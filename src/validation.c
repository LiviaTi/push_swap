/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:34:58 by liferrei          #+#    #+#             */
/*   Updated: 2025/10/15 17:11:10 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_parse_number(const char *str)
{
	long	n;
	int		i;
	int		num;

	if (!str || *str == '\0')
		ft_error_exit();
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		ft_error_exit();
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_error_exit();
		i++;
	}
	n = ft_atol(str);
	if (n < -2147483648 || n > 2147483647)
		ft_error_exit();
	num = n;
	return (num);
}

void	ft_check_rep(t_list **a)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *a;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->number == tmp2->number)
				ft_error_exit();
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}
