/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:52:19 by leochen           #+#    #+#             */
/*   Updated: 2024/01/09 13:55:03 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP.h
# define PUSH_SWAP.h

typedef struct	s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	capacity;
	int	chunk;
}				t_stack;

