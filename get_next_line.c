/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:58:51 by efarhat           #+#    #+#             */
/*   Updated: 2022/11/30 19:06:48 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(char *str, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	int	rdd;

	rdd = 1;
	while (!ft_strchr(str, '\n') && rdd > 0)
	{
		rdd = read(fd, buff, BUFFER_SIZE);
		buff[rdd] = '\0';
		str = ft_strjoin(str, buff);
	}
	return (str);
}

char	*ft_get_line(char *str)
{
	int	i;
	char	*line;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_get_remaining(char *str)
{
	int	i;
	char	*s;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	s = malloc(sizeof(char) * (len - i));
	if (!s)
		return (NULL);
	i++;
	while (str[i + j] != '\0')
	{
		s[j] = str[i + j];
		j++;
	}
	s[j] = '\0';
	free(str);
	return (s);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char	*sbuff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	sbuff = ft_read_line(sbuff, fd);
	if (!sbuff)
		return (NULL);
	line = ft_get_line(sbuff);
	sbuff = ft_get_remaining(sbuff);
	return (line);
}
