/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:56:12 by leochen           #+#    #+#             */
/*   Updated: 2024/01/18 19:21:05 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_insert_index(t_stack *stack, int index_b)
{
	int	index_a;

	index_a = 0;
	if (stack->indexed[index_b] > stack->indexed[stack->atop])
	{
		index_a = stack->atop;
		while (index_a < stack->size && stack->indexed[index_b] > stack->indexed[index_a])
		{
			index_a++;
			if (index_a < stack->size && stack->indexed[index_a] < stack->indexed[index_a - 1])
				return (index_a);
		}
	}
	else
	{
		index_a = stack->size;
		while (index_a > stack->atop && stack->indexed[index_b] < stack->indexed[index_a - 1])
		{
			index_a--;
			if (index_a > stack->atop && stack->indexed[index_a] < stack->indexed[index_a - 1])
				return (index_a);
		}
	}
	return (index_a);
}

void	calc_steps(t_stack *stack, int *steps, int index_a, int index_b)
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
		step_b = -(index_b + 1);
	total_steps = calc_total(step_a, step_b);
	if ((total_steps < steps[2] && total_steps >= 0) || index_b == stack->atop - 1)
	{
		steps[0] = step_a;
		steps[1] = step_b;
		steps[2] = total_steps;
	}
}

int	calc_total(int	a, int b)
{
	if ((a * b >= 0) && (abs(a) >= abs(b)))
		return (abs(a));
	else if ((a * b >= 0) && (abs(a) < abs(b)))
		return (abs(b));
	else if (a * b < 0)
		return (abs(a) + abs(b));
	return (0);
}

void	rotate_command(t_stack *stack, int a, int b)
{
	if (a == 0 && b == 0)
		return ;
	while (a > 0 && b > 0)
	{
		rr(stack, 1, 1);
		a--;
		b--;
	}
	while (a < 0 && b < 0)
	{
		rrr(stack, 1, 1);
		a++;
		b++;
	}
	rotate_command_single(stack, a, b);
}

void	rotate_command_single(t_stack *stack, int a, int b)
{
	while (a > 0)
	{
		ra(stack, 1, 1);
		a--;
	}
	while (b > 0)
	{
		rb(stack, 1, 1);
		b--;
	}
	while (a < 0)
	{
		rra(stack, 1, 1);
		a++;
	}
	while (b < 0)
	{
		rrb(stack, 1, 1);
		b++;
	}
}

void	insert_to_a(t_stack *stack)
{
	int	steps[3];
	int	index_a;
	int	index_b;

	steps[0] = 0;
	steps[1] = 0;
	steps[2] = 0;
	index_b = stack->atop - 1;
	while (index_b >= 0)
	{
		index_a = find_insert_index(stack, index_b);
		//printf("***find_insert_index_result****\nindex_b=%d, atop=%d, index_a=%d\n", index_b, stack->atop, index_a);
		calc_steps(stack, steps, index_a, index_b);
		//printf("****calc steps result*****\nstep_a=%d, step_b=%d, total_steps=%d\n", steps[0], steps[1], steps[2]);
		if (steps[2] == 0 || steps[2] == 1)
			break;
		index_b--;
	}
	//printf("before rotate command\n");
	rotate_command(stack, steps[0], steps[1]);
	//printf("****rotate command result*****\nstep[0]=%d, step[1]=%d, total_steps=%d\n", steps[0], steps[1], steps[2]);
	pa(stack, 1, 1);
	//printf("****now indexed*****\n");
	//for (int k=0; k<stack->size; k++)
		//printf("%d ", stack->indexed[k]);
}