/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:34:52 by hachahbo          #+#    #+#             */
/*   Updated: 2022/10/31 04:36:03 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// # include <unistd.h>
// # include <stdlib.h>
// # include <stdio.h>
# include <libc.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

char	*get_next_line(int fd);
char	*ft_read_str(int fd, char *str);
char	*ft_get_line(char *str);
char	*ft_new_str(char *str);
char	*ft_strjoin(char *str, char *buff);
size_t	ft_strlen(char *s);

#endif