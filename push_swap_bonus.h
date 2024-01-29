/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:26:24 by leochen           #+#    #+#             */
/*   Updated: 2024/01/26 16:46:28 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stddef.h>
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# include "push_swap.h"

int		handle_sw(t_stack *stack, char *line);
int		handle_pu(t_stack *stack, char *line);
int		handle_r(t_stack *stack, char *line);
int		handle_rr(t_stack *stack, char *line);
int		match_op(t_stack *stack, char *line);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/*****************get next line*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*clean_extracted_stock(char *stock);
char	*extract_from_stock(char *stock);
char	*read_and_add(int fd, char *stock);
size_t	ft_strlen(char *s);
char	*add_to_stock(char*stock, char *buf);
char	*ft_strchr(char *s, int c);

#endif
