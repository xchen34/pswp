/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 01:09:32 by leochen           #+#    #+#             */
/*   Updated: 2024/01/26 16:52:36 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}	
	return (1);
}

void	free_and_errorprint(t_stack *stack)
{
	free(stack);
	error_print();
}

void	free_stack_and_errorprint(t_stack *stack)
{
	free_stack(stack);
	error_print();
}

void	free_stack_and_exit(t_stack *stack)
{
	free_stack(stack);
	exit(1);
}

int	check_all_space(char *s)
{
	while (*s)
	{
		if (*s == '\t' || *s == '\n' || *s == '\v'
			|| *s == '\f' || *s == '\r' || *s == ' ')
			s++;
		else
			return (0);
	}
	return (1);
}
