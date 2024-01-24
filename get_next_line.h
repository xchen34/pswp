/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:06:45 by leochen           #+#    #+#             */
/*   Updated: 2023/12/14 16:49:35 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

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
