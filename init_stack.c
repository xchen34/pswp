/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 21:14:33 by leochen           #+#    #+#             */
/*   Updated: 2024/01/22 17:01:24 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*put_to_array(int argc, char **argv)
{
	if (argc == 2)
		return (str_to_array(argv[1]));
	else if (argc > 2)
		return (args_to_array(argc, argv));
	else
		return (NULL);
}

void	pre_sort(t_stack *stack)
{
	int	i;
	int	count;
	int	tmp;

	i = 0;
	count = stack->size - 1;
	while (count > 0)
	{
		i = 0;
//		while (i < stack->size - 1)
		while (i < count)
		{
			if (stack->pre_sorted[i] > stack->pre_sorted[i + 1])
			{
				tmp = stack->pre_sorted[i];
				stack->pre_sorted[i] = stack->pre_sorted[i + 1];
				stack->pre_sorted[i + 1] = tmp;
			}
		    i++;
		}
		count--;
	}
	/*int k;
for (k=0;k<stack->size; k++)
    printf("pre sorted[%d]:%d", k, stack->pre_sorted[k]);*/
}
void indexing(t_stack *stack)
{
    int i;
	int	j;

	i = 0;
	j = 0;
	while (i < stack->size)
	{
		j = 0;
		while (j < stack->size)
		{
			if (stack->original_input[i] == stack->pre_sorted[j])
			{
				stack->indexed[i] = j;
				break;
			}
			j++;
		}
		i++;
	}
    // 打印输出部分
   /* for (i = 0; i < stack->size; i++)
        printf("indexed[%d]: %d", i, stack->indexed[i]);*/
}

void	initialize_stack(t_stack *stack, int argc, char **argv)
{
	stack->original_input = put_to_array(argc, argv);
	stack->pre_sorted = put_to_array(argc, argv);
	stack->indexed = put_to_array(argc, argv);
	stack->atop = 0;
	if (argc > 2)
		stack->size = argc - 1;
	else
		stack->size = count_words(argv[1], ' ');

    pre_sort(stack);
//    printf("Pre sort!!!!!");
//    for (int k=0; k<stack->size; k++){
//        printf("!!!!!!%d", stack->pre_sorted[k]);
//    }
	indexing(stack);
}

void	free_stack(t_stack *stack)
{
	free(stack->indexed);
	free(stack->original_input);
	free(stack->pre_sorted);;
	free(stack);
}
