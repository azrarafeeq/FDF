/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:22:32 by arafeeq           #+#    #+#             */
/*   Updated: 2022/11/30 14:51:16 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buffer_size(int fd, char *str)
{
	char	*buf;
	int		bytes;

	buf = malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes = 1;
	while (bytes && !ft_strchr(str, '\n'))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes] = '\0';
		str = ft_gnl_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char	*ft_line(char *str)
{
	char	*line;
	int		line_len;
	int		i;

	line_len = 0;
	if (!str[line_len])
		return (NULL);
	while (str[line_len] != '\0')
		line_len++;
	line = malloc(sizeof(char) * line_len + 1);
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

char	*ft_remain(char *str)
{
	char	*temp_str;
	int		j;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str)
	{
		free(str);
		return (NULL);
	}
	temp_str = malloc(sizeof(char) * (ft_strlen(str) - i) + 1);
	if (!temp_str)
		return (NULL);
	if (str[i] == '\n')
		i++;
	j = 0;
	while (str[i] != '\0')
		temp_str[j++] = str[i++];
	temp_str[j] = '\0';
	free(str);
	return (temp_str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || fd > 10240 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_buffer_size(fd, str);
	if (!str || str[0] == '\0')
	{
		if (str)
			free(str);
		str = NULL;
		return (NULL);
	}
	line = ft_line(str);
	str = ft_remain(str);
	if (!str)
	{
		free(str);
		str = NULL;
	}
	return (line);
}
