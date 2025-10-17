/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 09:07:44 by liferrei          #+#    #+#             */
/*   Updated: 2025/10/17 14:19:14 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	int		total_size;

	a = NULL;
	b = NULL;
	if (argc < 2 || argv[1][0] == '\0')
		ft_error_exit();
	total_size = ft_parse_input(argc, argv, &a);
	ft_check_rep(&a);
	if (!ft_is_organize(&a))
		ft_organize(&a, &b, total_size);
	ft_cleanup(&a, &b);
	return (0);
}
