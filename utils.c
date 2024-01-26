/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:51:02 by leochen           #+#    #+#             */
/*   Updated: 2024/01/26 12:59:54 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}	
	return (1);
}
int	check_args(int argc, char **argv)
{	
	int	i;

	i = 1;
	if argc == 2
	{
		
	}
	if (argc > 2)
	{
		while (i < argc)
		{
			if (check_numeric(argv[i]) == 0)
				error_print();
			i++;
		}
	}
	if (i > 1)
		return (1);
	return (0);
}
/*int	arg_ok(char *s)
{
	if ((s[0] == '+' && s[1] == '\0') || (s[0] == '-' && s[1] == '\0')
		|| (s[0] == ' ' && s[1] == '\0'))
		return (0);
	return (1);
}*/

int	atoi2(const char *s)
{
	long long int	nb;
	int				sign;

	sign = 1;
	nb = 0;
	while ((*s >= 9 && *s <= 13) || *s == 32)
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
		if ((sign == 1 && nb * sign > 2147483647)
			|| (sign == -1 && nb * sign < -2147483648))
			error_print();
	}
	return (nb * sign);
}

int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	*str_to_array(char *s)
{
	int			i;
	int			count;
	int			*arry;
	char		**tmp;

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
