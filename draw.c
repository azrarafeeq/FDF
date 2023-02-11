/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:59:50 by arafeeq           #+#    #+#             */
/*   Updated: 2023/02/06 16:45:34 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_fdf **fdf, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && y >= 0) && (x < (*fdf)->win_width && y < (*fdf)->win_length))
	{
		dst = (*fdf)->i->addr + (y * (*fdf)->i->l_len + x
				* ((*fdf)->i->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int	get_sign(double num)
{
	if (num < 0)
		return (-1);
	else
		return (1);
}

void	rotate_x_y(t_rm *rm, t_coords *c, int z, t_fdf **fdf)
{
	double	temp_x;

	(*fdf)->m_width = (*fdf)->map->width * (*fdf)->zoom;
	(*fdf)->m_length = (*fdf)->map->height * (*fdf)->zoom;
	c->x *= (*fdf)->zoom;
	c->y *= (*fdf)->zoom;
	z = z * (*fdf)->zoom_z;
	c->x -= (*fdf)->m_width / 2;
	c->y -= (*fdf)->m_length / 2;
	c->x += (*fdf)->translate_x;
	c->y += (*fdf)->translate_y;
	temp_x = c->x;
	c->x = (rm->a11 * c->x) + (rm->a12 * c->y) + (rm->a13 * z);
	c->y = (rm->a21 * temp_x) + (rm->a22 * c->y) + (rm->a23 * z);
	c->x += (*fdf)->win_width / 2;
	c->y += (*fdf)->win_length / 2;
}

void	draw(t_fdf **fdf)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	(*fdf)->rm = malloc(sizeof(t_rm));
	allocate_rmatrice((*fdf)->ang, fdf);
	while (y < (*fdf)->map->height)
	{
		while (x < (*fdf)->map->width)
		{
			if (x < (*fdf)->map->width - 1)
				bressenham(x, y, 'a', fdf);
			if (y < (*fdf)->map->height - 1)
				bressenham(x, y, 'z', fdf);
			x++;
		}
		x = 0;
		y++;
	}
}
