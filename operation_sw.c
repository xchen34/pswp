/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_sw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:07:28 by leochen           #+#    #+#             */
/*   Updated: 2024/01/11 18:46:47 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// original_input  33 10 42 67 99 25
// pre_sorted 		10 25 33 42 67 99
// indexed			(atop)2 0 3 4 5 1
// 2 b
// 0 b   btop
// 3  a   atop
// 1  a
// 4  a     atop是数字3在整个ab的index 也就是2
void	sa(t_stack *stack, int exec, int print)
{
	int	tmp;

	if (exec == 1 && stack->atop < stack->size - 1)  //size-1是indexed里面最大的数（即原数的大小index 第几小 从第零小开始） 如果atop等于它 说明只有一个数字
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
