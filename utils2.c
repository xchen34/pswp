/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:33:20 by leochen           #+#    #+#             */
/*   Updated: 2024/01/15 20:41:41 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	error_print(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	check_dup(t_stack *stack)
{
	int	*tmp;
	int	i;
	int	j;

	i = 0;
	tmp = stack->original_input;
	while (i < stack->size - 1)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (tmp[i] != tmp[j])
				j++;
			else
				return (1);
		}
		i++;
	}
	free(tmp);
	return (0);
}

int	check_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->original_input[i] < stack->original_input[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_a_soted(t_stack *stack)
{
	int	i;

	i = stack->atop;
	while (i < stack->size - 1)
	{
		if (stack->indexed[i] < stack->indexed[i + 1])
			i++;
		else
			return (0);	
	}
	return (1);
}
void	free_tmp(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i] != NULL)
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}