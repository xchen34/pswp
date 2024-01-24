/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:56:12 by leochen           #+#    #+#             */
/*   Updated: 2024/01/24 00:43:26 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_insert_index(t_stack *s, int idxb)
{
	int	idxa;

	idxa = 0;
	if (s->indexed[idxb] > s->indexed[s->atop])
	{
		idxa = s->atop;
		while (idxa < s->size && s->indexed[idxb] > s->indexed[idxa])
		{
			idxa++;
			if (idxa < s->size
				&& s->indexed[idxa] < s->indexed[idxa - 1])
				return (idxa);
		}
	}
	else
	{
		idxa = s->size;
		while (idxa > s->atop && s->indexed[idxb] < s->indexed[idxa - 1])
		{
			idxa--;
			if (idxa > s->atop && s->indexed[idxa] < s->indexed[idxa - 1])
				return (idxa);
		}
	}
	return (idxa);
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
	if ((total_steps < steps[2]
			&& total_steps >= 0) || index_b == stack->atop - 1)
	{
		steps[0] = step_a;
		steps[1] = step_b;
		steps[2] = total_steps;
	}
}

int	calc_total(int a, int b)
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
