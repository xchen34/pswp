/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 21:14:33 by leochen           #+#    #+#             */
/*   Updated: 2024/01/11 18:46:43 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*put_to_array(int argc, char **argv)
{
	int		i;
	int		*arry;
	char	**tmp;

	arry = NULL;
	if (argc < 2)
		error_exit();
	else if (count == 2)
	{
		i = 0;
		tmp = ft_split(argv[1], ' ');
		while (tmp[i++] != NULL)
			arry[i] = atoi2(tmp[i]);
	}
	else
	{
		i = 1;
		while (i++ < argc)
			arry[i - 1] = atoi2(argv[i]);
	}
	free_tmp(tmp);
	return (arry);
}

void	pre_sort(t_stack *stack)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < stack->size - 1)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->pre_sorted[i] < stack->pre_sorted[j])
				j++;
			else
			{
				tmp = stack->pre_sorted[i];
				stack->pre_sorted[i] = stack->pre_sorted[j];
				stack->pre_sorted[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	indexing(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stack->size)
	{
		if (original_input[i] == pre_sorted[j])
		{
			indexed[i] = j;
			i++;
		}
		j++;
	}
}

void	initialize_stack(t_stack *stack, int argc, char **argv)
{
	stack->original_input = put_to_array(argc, argv);
	stack->pre_sorted = put_to_array(argc, argv);
	stack->indexed = put_to_array(argc, argv);
	stack->atop = 0;
	stack->size = argc - 1;
}

void	free_stack(t_stack *stack)
{
	free(stack->indexed);
	free(stack->original_input);
	free(stack->pre_sorted);
	free(stack);
}
