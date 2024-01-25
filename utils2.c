/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:33:20 by leochen           #+#    #+#             */
/*   Updated: 2024/01/25 01:23:05 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_print(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	check_dup(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size - 1)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->original_input[i] != stack->original_input[j])
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack->atop == 0)
	{
		while (i < stack->size - 1)
		{
			if (stack->indexed[i] < stack->indexed[i + 1])
				i++;
			else
				return (0);
		}
		return (1);
	}
	return (0);
}

int	check_a_sorted(t_stack *stack)
{
	int	i;

	i = stack->atop;
	while (i < stack->size - 1)
	{
		if (stack->indexed[i] < stack->indexed[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

void	free_tmp(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i] != NULL)
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}
