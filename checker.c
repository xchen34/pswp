/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:32:47 by leochen           #+#    #+#             */
/*   Updated: 2024/01/26 12:59:38 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	process_op(t_stack *stack)
{
	char	*line;

	line = get_next_line(0);
	if (!line)
		return ;
	while (line)
	{
		if (match_op(stack, line) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			free(line);
			free_stack(stack);
			exit(1);
		}
		free(line);
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc == 1 || argv[1][0] == '\0')
		error_print();
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		error_print();
	initialize_stack(stack, argc, argv);
	if (check_dup(stack) == 1 || check_sorted(stack) == 1)
		free_stack_and_errorprint(stack);
	process_op(stack);
	if (check_sorted(stack) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(stack);
	return (0);
}
