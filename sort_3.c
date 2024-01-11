/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:41:31 by leochen           #+#    #+#             */
/*   Updated: 2024/01/11 16:42:36 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 123  0
// 132  2  rra sa 
// 213  1 sa
// 
//231  1 rra
// 312  1  ra 
// 321  2 ra sa 

#include "push_swap.h"

void	sort_2and3(t_stack *stack)
{
	while (check_a_sorted(stack) == 0)
	{
		if (stack->size - stack->atop == 2)
		{	
			sa(stack, 1, 1);
			return ;
		}
		if (stack->size - stack->atop == 3)
		{
			if (stack->indexed[stack->atop] > stack->indexed[stack->size - 1])
			{
				if (stack->indexed[stack->atop] > stack->indexed[stack->atop + 1])
					ra(stack, 1, 1);
				else
					rra(stack, 1, 1);
			}
			else if (stack->indexed[stack->atop] < stack->indexed[stack->size - 1])
			{
				if (stack->indexed[stack->atop] > stack->indexed[stack->atop + 1])
					sa(stack, 1, 1);
			}
		}
	}
	return ;
}
void	sort_partition(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < size - 2)
	{
		if (stack->atop <= stack->size / 2)
			pb(stack, 1, 1);
		else
			ra(stack, 1, 1);
		i++;
	}


