/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:13:15 by leochen           #+#    #+#             */
/*   Updated: 2024/01/29 00:13:44 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (check_args(argc, argv) != 1)
		return (1);
	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (1);
	if (argv[1][0] == '\0' || check_all_space(argv[1]) == 1)
		free_and_errorprint(stack);
	initialize_stack(stack, argc, argv);
	if (check_dup(stack) == 1)
		free_stack_and_errorprint(stack);
	if (check_sorted(stack) != 1)
	{
		pre_sort(stack);
		indexing(stack);
		if (stack->size <= 3)
			sort_small_3(stack);
		else
			sort_big(stack);
	}
	free_stack(stack);
	return (0);
}
