/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:44:39 by liferrei          #+#    #+#             */
/*   Updated: 2025/10/15 15:52:51 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_parse_input(int argc, char **argv, t_list **tower_a)
{
	int		i;
	int		size;
	char	**args;

	i = 1;
	size = 0;
	while (i < argc)
	{
		args = ft_split(argv[i], ' ');
		if (!args || !*args)
		{
			ft_free_split(args);
			ft_error_exit();
		}
		size += ft_fill_tower(args, tower_a);
		ft_free_split(args);
		i++;
	}
	return (size);
}

void	ft_free_split(char **args)
{
	int		i;

	i = 0;
	if (!args)
		return ;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	ft_free_stack(t_list **stack)
{
	t_list	*current;
	t_list	*tmp;

	current = *stack;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*stack = NULL;
}

int	ft_fill_tower(char **args, t_list **a)
{
	int		i;
	int		total;
	t_list	*new_node;

	i = 0;
	total = 0;
	while (args[i])
	{
		total = ft_parse_number(args[i]);
		new_node = malloc(sizeof(t_list));
		if (!new_node)
			ft_error_exit();
		new_node->number = total;
		new_node->next = NULL;
		ft_lst_add_back(a, new_node);
		i++;
	}
	return (i);
}
