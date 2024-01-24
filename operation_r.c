/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:06:40 by leochen           #+#    #+#             */
/*   Updated: 2024/01/24 00:21:31 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack, int exec, int print)
{
	int	tmp;
	int	i;

	if (exec == 1 && stack->atop < stack->size - 1)
	{
		i = stack->atop;
		tmp = stack->indexed[i];
		while (i < stack->size - 1)
		{
			stack->indexed[i] = stack->indexed[i + 1];
			i++;
		}
		stack->indexed[i] = tmp;
	}
	if (print == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack *stack, int exec, int print)
{
	int	tmp;
	int	i;

	if (exec == 1 && stack->atop >= 2)
	{
		i = stack->atop - 1;
		tmp = stack->indexed[i];
		while (i > 0)
		{
			stack->indexed[i] = stack->indexed[i - 1];
			i--;
		}
		stack->indexed[i] = tmp;
	}
	if (print == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack *stack, int exec, int print)
{
	if (exec == 1)
	{
		ra(stack, 1, 0);
		rb(stack, 1, 0);
	}
	if (print == 1)
		write(1, "rr\n", 3);
}
