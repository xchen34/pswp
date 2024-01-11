/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:41:31 by leochen           #+#    #+#             */
/*   Updated: 2024/01/11 15:18:18 by leochen          ###   ########.fr       */
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

void	sort_3(t_stack **a)
{
	if (check_sorted(stack) == 0)
	{
		if (stack->indexed[stack->atop] > stack->indexed[stack->atop + 2])
		{
			if (stack->indexed[stack->atop + 1] < stack->indexed[stack->atop + 1])
		}
		}
	}
}

