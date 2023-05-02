/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:34:46 by arafeeq           #+#    #+#             */
/*   Updated: 2023/04/30 15:27:21 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi_base(char *str)
{
	int	i;
	int	res;
	int	base;
	int	digit;

	i = 0;
	res = 0;
	base = 10;
	if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
	{
		base = 16;
		i = i + 2;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			digit = str[i] - '0';
		else if (base == 16 && (str[i] >= 'A' && str[i] <= 'F'))
			digit = str[i] - 'A' + 10;
		else if (base == 16 && (str[i] >= 'a' && str[i] <= 'f'))
			digit = str[i] - 'a' + 10;
		res = res * base + digit;
			i++;
	}
	return (res);
}

void	map_height(char *filename, t_map *map)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(filename, O_RDONLY);
	height = 0;
	line = get_next_line(fd);
	if (!line)
	{
		write(2, "Error: Map is Empty\n", 21);
		close(fd);
		exit(0);
	}
	map_width(line, map);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	map->height = height;
	close(fd);
}

void	map_width(char *line, t_map *map)
{
	int		words;
	char	**line_split;

	words = 0;
	line_split = ft_split(line, ' ');
	while (line_split[words])
		words++;
	map->width = words;
	free_char_array(line_split);
}

void	read_map(t_map *map, int fd)
{
	int		i;
	int		j;
	char	*line;
	char	**split;

	i = -1;
	line = get_next_line(fd);
	while (line && ++i != map->height)
	{
		j = -1;
		split = ft_split(line, ' ');
		map->z[i] = (int *) malloc(sizeof(int) * map->width);
		map->colour[i] = (int *) malloc(sizeof(int) * map->width);
		while (split[++j] && j != map->width)
			read_map_part_2(map, i, j, split);
		free_char_array(split);
		free(line);
		line = get_next_line(fd);
	}
}

void	read_map_part_2(t_map *map, int i, int j, char **split)
{
	char	**c_split;

	if (ft_strrchr(split[j], ','))
	{
		c_split = ft_split(split[j], ',');
		map->z[i][j] = ft_atoi(c_split[0]) * -1;
		map->colour[i][j] = ft_atoi_base(c_split[1]);
		free_char_array(c_split);
	}
	else
	{
		map->z[i][j] = ft_atoi(split[j]) * -1;
		map->colour[i][j] = 0xf8f8ff;
	}
}
