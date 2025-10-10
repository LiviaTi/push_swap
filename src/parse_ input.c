/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:44:39 by liferrei          #+#    #+#             */
/*   Updated: 2025/10/10 14:44:22 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int ft_parse_input(int argc, char **argv, t_list **tower_a)
{
	int		i;
	int		size;
	char	**args;

	i = 1;
	size = 0;
	while (i < argc)
	{
		size = ft_split(argv[i], ' ');
		if (!args || !*args)
		{
			ft_free_split(args);
			ft_exit_error();
		}
		size += ft_fill_tower_args(args, tower_a);
		ft_free_split(args);
		i++;
	}
	return (size);
}