/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 01:09:32 by leochen           #+#    #+#             */
/*   Updated: 2024/01/25 01:10:25 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_and_errorprint(t_stack *stack)
{
	free(stack);
	error_print();
}

void	free_stack_and_errorprint(t_stack *stack)
{
	free_stack(stack);
	error_print();
}

void	free_and_exit(t_stack *stack)
{
	free(stack);
	exit(1);
}