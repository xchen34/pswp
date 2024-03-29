/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:40:05 by leochen           #+#    #+#             */
/*   Updated: 2024/01/29 01:22:43 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>

typedef struct s_stack
{
	int	*indexed;
	int	*original_input;
	int	*pre_sorted;
	int	atop;
	int	size;
}		t_stack;

/***************Init stack*************************/
int		*put_to_array(int argc, char **argv, t_stack *stack);
void	pre_sort(t_stack *stack);
void	indexing(t_stack *stack);
void	initialize_stack(t_stack *stack, int argc, char **argv);
void	free_stack(t_stack *stack);

/****************operations*************************/
void	pb(t_stack *stack, int exec, int print);
void	pa(t_stack *stack, int exec, int print);
void	ra(t_stack *stack, int exec, int print);
void	rb(t_stack *stack, int exec, int print);
void	rr(t_stack *stack, int exec, int print);
void	rra(t_stack *stack, int exec, int print);
void	rrb(t_stack *stack, int exec, int print);
void	rrr(t_stack *stack, int exec, int print);
void	sa(t_stack *stack, int exec, int print);
void	sb(t_stack *stack, int exec, int print);
void	ss(t_stack *stack, int exec, int print);

/******************sort algo************************/
int		find_insert_index(t_stack *stack, int index_b);
void	calc_steps(t_stack *stack, int *steps, int index_a, int index_b);
int		calc_total(int a, int b);
void	rotate_command(t_stack *stack, int a, int b);
void	rotate_command_single(t_stack *stack, int a, int b);
void	insert_to_a(t_stack *stack);

/****************************sort********************/
void	sort_small_3(t_stack *stack);
void	sort_partition(t_stack *stack);
void	move_to_top(t_stack *stack, int n);
void	sort_big(t_stack *stack);

/*********************utils*************************/
bool	atoi2(const char *s, long long *nb);
int		abs(int n);
int		*str_to_array(char *s, t_stack *stack);
int		*args_to_array(int argc, char **argv, t_stack *stack);
void	error_print(void);
int		check_dup(t_stack *stack);
int		check_sorted(t_stack *stack);
int		check_a_sorted(t_stack *stack);
void	free_tmp(char **tmp);
char	**ft_split(char *s, char c);
int		count_words(char *s, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		check_numeric(char *str);
int		check_args(int argc, char **argv);
void	free_and_errorprint(t_stack *stack);
void	free_stack_and_errorprint(t_stack *stack);
void	free_stack_and_exit(t_stack *stack);
int		check_all_space(char *s);
void	free_arry(char **tmp, int *arry, t_stack *stack);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);
int		get_sign(const char **s);

#endif
