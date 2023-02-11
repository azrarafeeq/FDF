/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:24:53 by arafeeq           #+#    #+#             */
/*   Updated: 2023/02/06 16:45:06 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_char_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_int_array(int **int_array, int size)
{
	int	i;

	i = 0;
	while (i != size)
	{
		free(int_array[i]);
		i++;
	}
	free(int_array);
	return ;
}

void	free_fdf(t_fdf *fdf)
{
	free_int_array(fdf->map->z, fdf->map->height);
	free_int_array(fdf->map->colour, fdf->map->height);
	free(fdf->map);
	free(fdf->i);
	free(fdf->ang);
	free(fdf->rm);
	free(fdf);
}
