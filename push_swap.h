/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:40:05 by leochen           #+#    #+#             */
/*   Updated: 2024/01/11 15:18:18 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP.H
# define PUSH_SWAP.H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_stack
{
	int	*indexed;
	int	*original_input;
	int	*pre_sorted;
	int	atop; //表示栈顶的位置
	int	size;  //栈中的总元素数量
}				t_stack;




#endif