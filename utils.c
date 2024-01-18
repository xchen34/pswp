/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:51:02 by leochen           #+#    #+#             */
/*   Updated: 2024/01/18 12:55:49 by leochen          ###   ########.fr       */
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

int	abs(int	n)
{
	if (n < 0)
		return (-n);
	return (n);
}
int	*str_to_array(char *s)
{
	int	*arry;
	int	i;
	int	count;
	char	**tmp;

	tmp = ft_split(s, ' ');
	count = 0;
	i = 0;
	while (tmp[count] != NULL)
		count++;
	arry = (int *)malloc(sizeof(int) * count);
	if (arry == NULL)
		return (NULL);
	while (i < count)
	{
		arry[i] = atoi2(tmp[i]);
		i++;
	}
	free_tmp(tmp);
	return (arry);
}

int	*args_to_array(int argc, char **argv)
{
	int	i;
	int	*arry;

	i = 0;
	arry = (int *)malloc(sizeof(int) * (argc - 1));
	if (arry == NULL)
		return (NULL);
	while (i < argc - 1)
	{
		arry[i] = atoi2(argv[i + 1]);
		i++;
	}
	return (arry);
}