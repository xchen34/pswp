/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:24:17 by leochen           #+#    #+#             */
/*   Updated: 2024/01/26 12:59:48 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	handle_sw(t_stack *stack, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3))
	{
		sa(stack, 1, 0);
		return (1);
	}
	else if (!ft_strncmp(line, "sb\n", 3))
	{
		sb(stack, 1, 0);
		return (1);
	}
	else if (!ft_strncmp(line, "ss\n", 3))
	{
		ss(stack, 1, 0);
		return (1);
	}
	return (0);
}

int	handle_pu(t_stack *stack, char *line)
{
	if (!ft_strncmp(line, "pa\n", 3))
	{
		pa(stack, 1, 0);
		return (1);
	}
	else if (!ft_strncmp(line, "pb\n", 3))
	{
		pb(stack, 1, 0);
		return (1);
	}
	return (0);
}

int	handle_r(t_stack *stack, char *line)
{
	if (!ft_strncmp(line, "ra\n", 3))
	{
		ra(stack, 1, 0);
		return (1);
	}
	else if (!ft_strncmp(line, "rb\n", 3))
	{
		rb(stack, 1, 0);
		return (1);
	}
	else if (!ft_strncmp(line, "rr\n", 3))
	{
		rr(stack, 1, 0);
		return (1);
	}
	return (0);
}

int	handle_rr(t_stack *stack, char *line)
{
	if (!ft_strncmp(line, "rra\n", 4))
	{
		rra(stack, 1, 0);
		return (1);
	}
	else if (!ft_strncmp(line, "rrb\n", 4))
	{
		rrb(stack, 1, 0);
		return (1);
	}
	else if (!ft_strncmp(line, "rrr\n", 4))
	{
		rrr(stack, 1, 0);
		return (1);
	}
	return (0);
}

int	match_op(t_stack *stack, char *line)
{
	if (handle_sw(stack, line) == 1)
		return (1);
	if (handle_pu(stack, line) == 1)
		return (1);
	if (handle_r(stack, line) == 1)
		return (1);
	if (handle_rr(stack, line) == 1)
		return (1);
	return (0);
}
