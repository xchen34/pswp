/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:02:18 by leochen           #+#    #+#             */
/*   Updated: 2024/01/24 00:01:30 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack, int exec, int print)
{
	int	tmp;
	int	i;

	if (exec == 1 && stack->atop < stack->size - 1)
	{
		i = stack->size - 1;
		tmp = stack->indexed[i];
		while (i > stack->atop)
		{
			stack->indexed[i] = stack->indexed[i - 1];
			i--;
		}
		stack->indexed[stack->atop] = tmp;
	}
	if (print == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *stack, int exec, int print)
{
	int	tmp;
	int	i;

	if (exec == 1 && stack->atop >= 2)
	{
		i = 0;
		tmp = stack->indexed[i];
		while (i < stack->atop - 1)
		{
			stack->indexed[i] = stack->indexed[i + 1];
			i++;
		}
		stack->indexed[i] = tmp;
	}
	if (print == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack, int exec, int print)
{
	if (exec == 1)
	{
		rra(stack, 1, 0);
		rrb(stack, 1, 0);
	}
	if (print == 1)
		write(1, "rrr\n", 4);
}
