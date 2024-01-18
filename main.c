/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:13:15 by leochen           #+#    #+#             */
/*   Updated: 2024/01/18 17:45:24 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;
	//int	i;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (argc == 1 || !stack)
		return (1);
	initialize_stack(stack, argc, argv);
	if (!stack || check_dup(stack) == 1)
	{
		free_stack(stack);
		error_print();
	}
	if (check_sorted(stack) != 1)
	{
		pre_sort(stack);
		indexing(stack);
		if (stack->size <= 3)
			sort_small_3(stack);
		else
			sort_big(stack);
	}
	//for (i = 0; i < stack->size; i++)
		//printf("final indexed[%d]: %d\n", i, stack->indexed[i]);
	free_stack(stack);
	return (0);
}
