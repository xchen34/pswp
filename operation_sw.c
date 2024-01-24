/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_sw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:07:28 by leochen           #+#    #+#             */
/*   Updated: 2024/01/23 23:33:06 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack, int exec, int print)
{
	int	tmp;

	if (exec == 1 && stack->atop < stack->size - 1)
	{
		tmp = stack->indexed[stack->atop];
		stack->indexed[stack->atop] = stack->indexed[stack->atop + 1];
		stack->indexed[stack->atop + 1] = tmp;
	}
	if (print == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack *stack, int exec, int print)
{
	int	tmp;

	if (exec == 1 && stack->atop >= 2)
	{
		tmp = stack->indexed[stack->atop - 2];
		stack->indexed[stack->atop - 2] = stack->indexed[stack->atop - 1];
		stack->indexed[stack->atop - 1] = tmp;
	}
	if (print == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack *stack, int exec, int print)
{
	if (exec == 1)
	{
		sa(stack, 1, 0);
		sb(stack, 1, 0);
	}
	if (print == 1)
		write(1, "ss\n", 3);
}
