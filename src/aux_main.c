/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:44:39 by liferrei          #+#    #+#             */
/*   Updated: 2025/10/17 14:16:16 by liferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_split(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	ft_free_stack(t_list **stack)
{
	t_list	*cur;
	t_list	*next;

	if (stack == NULL || *stack == NULL)
		return ;
	cur = *stack;
	while (cur != NULL)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	*stack = NULL;
}

int	ft_fill_stack_from_args(char **args, t_list **a)
{
	int		i;
	int		num;
	t_list	*new_node;

	i = 0;
	while (args[i])
	{
		num = ft_parse_number(args[i]);
		new_node = malloc(sizeof(t_list));
		if (!new_node)
			ft_error_exit();
		new_node->number = num;
		new_node->next = NULL;
		ft_lst_add_back(a, new_node);
		i++;
	}
	return (i);
}

int	ft_parse_input(int argc, char **argv, t_list **a)
{
	int		i;
	int		total_size;
	char	**split_args;

	i = 1;
	total_size = 0;
	while (i < argc)
	{
		split_args = ft_split(argv[i], ' ');
		if (!split_args || !*split_args)
		{
			ft_free_split(split_args);
			ft_error_exit();
		}
		total_size += ft_fill_stack_from_args(split_args, a);
		ft_free_split(split_args);
		i++;
	}
	return (total_size);
}

void	ft_cleanup(t_list **a, t_list **b)
{
	ft_free_stack(a);
	ft_free_stack(b);
}
