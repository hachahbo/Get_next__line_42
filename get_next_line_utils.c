/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:52:54 by hachahbo          #+#    #+#             */
/*   Updated: 2022/10/31 22:23:40 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
char	*ft_strchr(const char *s, int c)
{
	c = (unsigned char)c;
	while (*s != '\0' && c != *s)
		s++;
	if (c == *s)
		return ((char *)s);
	return (0);
}
char	*ft_strjoin(char *lstr, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!lstr)
	{
		lstr = (char *)malloc(1 * sizeof(char));
		lstr[0] = '\0';
	}
	if (!lstr || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(lstr) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (lstr)
		while (lstr[++i] != '\0')
			str[i] = lstr[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(lstr) + ft_strlen(buff)] = '\0';
	free(lstr);
	return (str);
}

char	*ft_read_str(int fd, char *str)
{
	char	*buff;
	int		n;
	int		is_nw;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	n = 1;
	is_nw = 0;
	while (n != 0 && !is_nw)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n == -1)
		{
			if(str != NULL)
				free(str);
			return (free(buff),NULL);
		}
		buff[n] = '\0';
		str = ft_strjoin(str, buff);
		if(ft_strchr(str, '\n'))
			is_nw = 1;
	}
	return (free (buff),str);
}

char	*ft_get_line(char *str)
{
	int		i;
	char	*s;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_new_str(char *lstr)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (lstr[i] && lstr[i] != '\n')
		i++;
	if (!lstr[i])
	{
		free(lstr);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(lstr) - i + 1));
	if (!str)
	{
		free(lstr);
		return (NULL);
	}
	i++;
	j = 0;
	while (lstr[i])
		str[j++] = lstr[i++];
	str[j] = '\0';
	free(lstr);
	return (str);
}
