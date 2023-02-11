/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bressenham.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:50:41 by arafeeq           #+#    #+#             */
/*   Updated: 2023/02/04 15:36:12 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	swap_content(double *int1, double *int2)
{
	double	temp;

	if (*int2 > *int1)
	{
		temp = *int1;
		*int1 = *int2;
		*int2 = temp;
		return (1);
	}
	else
		return (0);
}

void	initialize_x_y(t_coords *c, int x1, int y1, char flag)
{
	c->x = x1;
	c->y = y1;
	if (flag == 'a')
		c->x = x1 + 1;
	else if (flag == 'z')
		c->y = y1 + 1;
}

void	bressenham_part_2(t_balg *b_alg, double *x, double *y)
{
	while (b_alg->diff >= 0)
	{
		b_alg->diff = b_alg->diff - 2 * b_alg->delta_x;
		if (b_alg->swap)
			*x += b_alg->step_1;
		else
			*y += b_alg->step_2;
	}
	b_alg->diff = b_alg->diff + 2 * b_alg->delta_y;
	if (b_alg->swap)
		*y += b_alg->step_2;
	else
		*x += b_alg->step_1;
}

void	bressenham(int x1, int y1, char flag, t_fdf **fdf)
{
	t_coords	c1;
	t_coords	c2;
	int			ints[3];

	initialize_x_y(&c1, x1, y1, 'r');
	initialize_x_y(&c2, x1, y1, flag);
	ints[0] = (int)c2.x;
	ints[1] = (int)c2.y;
	rotate_x_y((*fdf)->rm, &c1, (*fdf)->map->z[y1][x1], fdf);
	rotate_x_y((*fdf)->rm, &c2, (*fdf)->map->z[ints[1]][ints[0]], fdf);
	(*fdf)->b_alg = allocate_balg(&c1.x, &c1.y, &c2.x, &c2.y);
	while (++(*fdf)->b_alg->i < (*fdf)->b_alg->delta_x)
	{
		if ((*fdf)->map->colour[y1][x1] != 0xf8f8ff)
			ints[2] = (*fdf)->map->colour[y1][x1];
		else
			ints[2] = (*fdf)->map->colour[ints[1]][ints[0]];
		if ((*fdf)->grad == 'y' && ints[2] != 0xf8f8ff)
			my_mlx_pixel_put(fdf, c1.x, c1.y, ints[2] + c1.x);
		else
			my_mlx_pixel_put(fdf, c1.x, c1.y, ints[2]);
		bressenham_part_2((*fdf)->b_alg, &c1.x, &c1.y);
	}
	free((*fdf)->b_alg);
}
