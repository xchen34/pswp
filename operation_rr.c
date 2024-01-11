/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:02:18 by leochen           #+#    #+#             */
/*   Updated: 2024/01/11 15:18:16 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// original_input  33 10 42 67 99 25
// pre_sorted 		10 25 33 42 67 99
// indexed			(atop)2 0 3 4 5 1
// 5 b
// 2 b
// 0 b   btop
// 3  a   atop
// 1  a
// 4  a     atop是数字3在整个ab的index 也就是2
void	rra(t_stack *stack, int exec, int print)
{
	int	tmp;
	int	i;
	
	if (exec == 1 && stack->atop < stack->size - 1)  //size-1是indexed里面最大的数（即原数的大小index 第几小 从第零小开始） 如果atop等于它 说明只有一个数字
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
		write(1, "rra\n", 3);
}
void	rrb(t_stack *stack; int exec, int print)
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

void	rrr(t_stack *stack; int exec, int print)
{
	if (exec == 1)
	{
		rra(stack, 1, 0);
		rrb(stack, 1, 0);
	}	
	if (p == 1)
		write(1, "rrr\n", 4);
}