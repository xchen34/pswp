/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:41:31 by leochen           #+#    #+#             */
/*   Updated: 2024/01/12 19:41:35 by leochen          ###   ########.fr       */
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

void	sort_small_3(t_stack *stack)
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
	while (i < stack->size / 2)
	{
		if (stack->indexed[stack->atop] < stack->size / 2)
		{
			pb(stack, 1, 1);
			i++;
		}
		else
			ra(stack, 1, 1);
	}
	while (stack->atop < stack->size - 3)
	{
		pb(stack, 1, 1);
		i++;
	}
	sort_small_3(stack);
	while (i >= 0)
	{
		insert_from_b(stack);
		i--;
	}
}

void	sort_big(t_stack *stack)
{
	if (check_sorted == 0)
	{
		sort_partition(stack);

}
