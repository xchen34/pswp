/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:55:07 by leochen           #+#    #+#             */
/*   Updated: 2024/01/09 19:24:40 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **copy_arguments(int argc, char **argv, int *size)
{
	char	**str;
	int			i;

	if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		i = 0;
		while (str[i] != NULL)
			i++;
	}
	else
	{
		str = (char **)malloc(sizeof(char *) * argc);
		if (str == NULL)
			
	}

}


int	main(int argc, char **argv)
{
	t_pile	*piles;
	int		size;

	if (argc < 2)
		exit(0);
	piles->input_str = split(argc, argv, &size);
	init_piles_ab(piles, size);
	atoi_to_pile(piles, argc);
	if (check_dup(piles) == 1)
		error_print();
	if (check_sorted == 1)
		error_print();
	turn_a_to_index(piles);
	push_chunks_to_b(piles);
	push_back_to_a(piles);
	free_and_quit(piles, argc, 0)?
	return (0);

}


