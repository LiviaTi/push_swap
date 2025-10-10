/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 09:07:44 by liferrei          #+#    #+#             */
/*   Updated: 2025/10/10 14:35:57 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int main(int argc, char *argv[])
{
	t_list	*tower_a;
	t_list	*tower_b;
	int		total;
	
	tower_a = NULL;
	tower_b = NULL;
	if (argc < 2)
		return(0);
	total = ft_parse_input(argc, argv, &tower_a);
	return(0);
}