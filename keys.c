/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:13:41 by arafeeq           #+#    #+#             */
/*   Updated: 2023/02/04 15:13:51 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change(t_fdf **f)
{
	mlx_destroy_image((*f)->mlx, (*f)->i->i);
	(*f)->i->i = mlx_new_image((*f)->mlx, 1920, 1080);
	(*f)->i->addr = mlx_get_data_addr((*f)->i->i, &(*f)->i->bpp,
			&(*f)->i->l_len, &(*f)->i->e);
	draw(&(*f));
	mlx_put_image_to_window((*f)->mlx, (*f)->win, (*f)->i->i, 0, 0);
	put_str_to_win(&(*f));
	return ;
}

void	assign_keys_projection(int keycode, t_fdf **fdf)
{
	if (keycode == 6)
	{
		(*fdf)->alpha = 20;
		(*fdf)->beta = 0;
		(*fdf)->gamma = 0;
	}
	else if (keycode == 7)
	{
		(*fdf)->alpha = 90;
		(*fdf)->beta = 0;
		(*fdf)->gamma = 8;
	}
	else if (keycode == 34)
	{
		(*fdf)->alpha = 70;
		(*fdf)->beta = 8;
		(*fdf)->gamma = 60;
	}
}

void	assign_keys_angles(int keycode, t_fdf **fdf)
{
	if (keycode == 13)
		(*fdf)->alpha += 0.5;
	else if (keycode == 1)
		(*fdf)->alpha -= 0.5;
	else if (keycode == 0)
		(*fdf)->beta -= 0.5;
	else if (keycode == 2)
		(*fdf)->beta += 0.5;
	else if (keycode == 12)
		(*fdf)->gamma -= 0.5;
	else if (keycode == 14)
		(*fdf)->gamma += 0.5;
	else if (keycode == 5)
		(*fdf)->grad = 'y';
	else if (keycode == 4)
		(*fdf)->grad = 'n';
}

void	assign_keys(int keycode, t_fdf **fdf)
{
	if (keycode == 53)
	{
		mlx_destroy_window((*fdf)->mlx, (*fdf)->win);
		free_fdf(*fdf);
		exit(0);
	}
	else if (keycode == 69)
		(*fdf)->zoom += 0.2;
	else if (keycode == 78)
		(*fdf)->zoom -= 0.2;
	else if (keycode == 124)
		(*fdf)->translate_x += 5;
	else if (keycode == 123)
		(*fdf)->translate_x -= 5;
	else if (keycode == 126)
		(*fdf)->translate_y -= 5;
	else if (keycode == 125)
		(*fdf)->translate_y += 5;
	else if (keycode == 24)
		(*fdf)->zoom_z += 0.2;
	else if (keycode == 27)
		(*fdf)->zoom_z -= 0.2;
}

int	key_hook(int keycode, t_fdf **fdf)
{
	assign_keys(keycode, fdf);
	assign_keys_angles(keycode, fdf);
	assign_keys_projection(keycode, fdf);
	change(fdf);
	return (0);
}
