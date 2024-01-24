/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_pu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:07:02 by leochen           #+#    #+#             */
/*   Updated: 2024/01/23 22:52:20 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *stack, int exec, int print)
{
	if (exec == 1 && stack->atop < stack->size)
		stack->atop += 1;
	if (print == 1)
		write(1, "pb\n", 3);
}

void	pa(t_stack *stack, int exec, int print)
{
	if (exec == 1 && stack->atop >= 1)
		stack->atop -= 1;
	if (print == 1)
		write(1, "pa\n", 3);
}
