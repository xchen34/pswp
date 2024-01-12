/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:56:12 by leochen           #+#    #+#             */
/*   Updated: 2024/01/12 19:41:29 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 找到插入位置（insert_getindex 函数）：
// 如果堆栈 B 的顶部元素大于堆栈 A 的顶部元素，向下搜索堆栈 A，直到找到一个比它大的元素。
// 如果堆栈 B 的顶部元素小于堆栈 A 的顶部元素，向上搜索堆栈 A，直到找到一个比它小的元素。
// 返回找到的位置索引
int	find_insert_indice(t_stack *stack, int element_index)
{
	int	current_index;

	current_index = 0;
	if (stack->indexed[element_index] > stack->indexed[stack->atop])
	{
		current_index = stack->atop;
		while (current_index < stack->size)
		{
			if (stack->indexed[element_index] < stack->indexed[current_index])
				break;
			current_index++;
		}
	}
	else
	{
		current_index = stack->size - 1;
		while (current_index > stack->atop)
		{
			if (stack->indexed[element_index] > stack->indexed[current_index])
				break;
			current_index--;
		}
	}
	return (current_index);
}

void	calc_rotations(t_stack *stack, int *steps, int index_a, int index_b)
{
	int	step_a;
	int	step_b;
	int	total_steps;  

	if (index_a - stack->atop <= (stack->size - stack->atop) / 2)
		step_a = index_a - stack->atop;
	else
		step_a = index_a - stack->size;
	if (index_b >= stack->atop / 2)
		step_b = stack->atop - 1 - index_b;
	else
		steps_b = -(index_b + 1);
	total_steps = cont(step_a, steps_b);
	if (total_steps < steps[2] && total_steps >= 0 || index_b == stack->atop - 1)
	{
		steps[0] = step_a;
		steps[1] = step_b;
		steps[2] = total_steps;
	}
}     4 2 7 | 6 8 9
void	insert_from_b(t_stack *stack)
{
	int	steps[3];
	int	index_a;
	int	index_b;

	steps[]
	index_b = stack->atop - 1;
	while (index_b >= 0)
	{
		index_a = find_insert_indice(stack, index_b);
		calc_rotations(stack, steps, index_a, index_b);
		if (steps[2] <= 1)
			break;
		index_b--;
	}
	rotate_duo(steps[0], steps[1], stack);
	pa(stack, 1, 1);
}