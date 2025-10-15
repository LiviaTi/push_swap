/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 09:07:44 by liferrei          #+#    #+#             */
/*   Updated: 2025/10/15 17:19:33 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*tower_a;
	t_list	*tower_b;
	int		size;

	tower_a = NULL;
	tower_b = NULL;
	size = 0;
	if (argc < 2)
		return (0);
	size = ft_parse_input(argc, argv, &tower_a);
	ft_check_rep(&tower_a);
	if (!ft_is_organize(&tower_a))
		ft_organize(&tower_a, &tower_b, size);
	ft_free_stack(&tower_a);
	return (0);
}
