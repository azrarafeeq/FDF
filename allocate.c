/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:49:04 by arafeeq           #+#    #+#             */
/*   Updated: 2023/02/02 14:31:35 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	allocate_fdf(t_fdf **fdf, char **argv)
{
	(*fdf)->zoom = 30;
	(*fdf)->zoom_z = 10;
	(*fdf)->translate_x = 0;
	(*fdf)->translate_y = 0;
	(*fdf)->alpha = 70;
	(*fdf)->beta = 8;
	(*fdf)->gamma = 60;
	(*fdf)->grad = 'n';
	allocate_map(fdf, argv);
	(*fdf)->m_width = (*fdf)->map->width * (*fdf)->zoom;
	(*fdf)->m_length = (*fdf)->map->height * (*fdf)->zoom;
	(*fdf)->win_width = (*fdf)->m_width * 2;
	(*fdf)->win_length = (*fdf)->m_length * 2;
	if ((*fdf)->map->width >= 25 || (*fdf)->map->height >= 25)
	{
		(*fdf)->zoom = 5;
		(*fdf)->zoom_z = 1;
		(*fdf)->win_width = 1800;
		(*fdf)->win_length = 1080;
	}
	else if ((*fdf)->map->width <= 10 || (*fdf)->map->height <= 10)
	{
		(*fdf)->win_width = 800;
		(*fdf)->win_length = 800;
	}
}

void	allocate_map(t_fdf **fdf, char **argv)
{
	int	fd;

	(*fdf)->map = malloc(sizeof(t_map));
	map_height(argv[1], (*fdf)->map);
	(*fdf)->map->z = malloc(sizeof(int *) * (*fdf)->map->height);
	(*fdf)->map->colour = malloc(sizeof(int *) * (*fdf)->map->height);
	fd = open(argv[1], O_RDONLY);
	read_map((*fdf)->map, fd);
	close(fd);
}

void	allocate_rmatrice(t_ang *a, t_fdf **fdf)
{
	a->a = (*fdf)->alpha * M_PI / 180;
	a->b = (*fdf)->beta * M_PI / 180;
	a->g = (*fdf)->gamma * M_PI / 180;
	(*fdf)->rm->a11 = cos(a->b) * cos(a->g);
	(*fdf)->rm->a12 = cos(a->b) * sin(a->g);
	(*fdf)->rm->a13 = -sin(a->b);
	(*fdf)->rm->a21 = sin(a->a) * sin(a->b) * cos(a->g) - cos(a->a) * sin(a->g);
	(*fdf)->rm->a22 = sin(a->a) * sin(a->b) * sin(a->g) + cos(a->a) * cos(a->g);
	(*fdf)->rm->a23 = sin(a->a) * cos(a->b);
}

t_balg	*allocate_balg(double *x, double *y, double *x2, double *y2)
{
	t_balg	*b_alg;

	b_alg = malloc(sizeof(t_balg));
	b_alg->delta_x = fabs(*x2 - *x);
	b_alg->delta_y = fabs(*y2 - *y);
	b_alg->step_1 = get_sign(*x2 - *x);
	b_alg->step_2 = get_sign(*y2 - *y);
	b_alg->swap = swap_content(&b_alg->delta_x, &b_alg->delta_y);
	b_alg->diff = 2 * b_alg->delta_y - b_alg->delta_x;
	b_alg->i = -1;
	return (b_alg);
}
