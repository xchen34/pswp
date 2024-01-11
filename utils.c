/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:51:02 by leochen           #+#    #+#             */
/*   Updated: 2024/01/11 16:42:40 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	atoi2(const char *s)
{
	long long int	nb;
	int	sign;

	sign = 1;
	nb = 0;
	while(*s == '\t' || *s == '\n' || *s == '\v'
		|| *s == '\f' || *s == '\r' || *s == ' ')
		s++;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (*s)
	{
		if (!(*s >= '0' && *s <= '9'))
			error_print();
		nb = nb * 10 + (*s - '0');
		s++;
	if ((sign == 1 && nb * sign > 2147483647) || (sign == -1 &&nb * sign < -2147483648))
		error_print();
	}	
	return (nb * sign);
}
