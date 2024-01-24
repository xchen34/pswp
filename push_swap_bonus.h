/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:26:24 by leochen           #+#    #+#             */
/*   Updated: 2024/01/23 22:54:59 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stddef.h>
# include <stdint.h>
# include "push_swap.h"

int		handle_sw(t_stack *stack, char *line);
int		handle_pu(t_stack *stack, char *line);
int		handle_r(t_stack *stack, char *line);
int		handle_rr(t_stack *stack, char *line);
int		match_op(t_stack *stack, char *line);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*get_next_line(int fd);

#endif