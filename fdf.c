/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:57:14 by arafeeq           #+#    #+#             */
/*   Updated: 2023/02/06 16:44:55 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	simple_parse(int argc, char **argv)
{
	int	len;
	int	fd;

	if (argc != 2)
	{
		write(2, "Error: arguments not equal to 1\n", 33);
		exit(0);
	}
	len = ft_strlen(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error: file does not exist\n", 27);
		exit(0);
	}
	close(fd);
	if (argv[1][len - 4] != '.' || argv[1][len - 3] != 'f'
		|| argv[1][len - 2] != 'd' || argv[1][len -1] != 'f')
	{
		write(2, "Error: file doesnot have '.fdf' extension\n", 43);
		exit(0);
	}
}

void	put_str_to_win(t_fdf **fdf)
{
	mlx_string_put((*fdf)->mlx, (*fdf)->win,
		2, 0, 0xd3d3d3, "W/S = alpha ++/--");
	mlx_string_put((*fdf)->mlx, (*fdf)->win,
		2, 15, 0xd3d3d3, "A/D = beta ++/--");
	mlx_string_put((*fdf)->mlx, (*fdf)->win,
		2, 30, 0xd3d3d3, "Q/E = gamma ++/--");
	mlx_string_put((*fdf)->mlx, (*fdf)->win,
		2, 45, 0xd3d3d3, "Z/X = projection top/side");
	mlx_string_put((*fdf)->mlx, (*fdf)->win,
		2, 60, 0xd3d3d3, "G/H = map gradient y/n");
	mlx_string_put((*fdf)->mlx, (*fdf)->win,
		2, 75, 0xd3d3d3, "I = isometric");
	mlx_string_put((*fdf)->mlx, (*fdf)->win, 2, 90, 0xd3d3d3, "+/- = z ++/--");
	mlx_string_put((*fdf)->mlx, (*fdf)->win,
		2, 105, 0xd3d3d3, "+/- = zoom ++/-- (numpad)");
	mlx_string_put((*fdf)->mlx, (*fdf)->win,
		2, 120, 0xd3d3d3, "up/down = translate_y ++/--");
	mlx_string_put((*fdf)->mlx, (*fdf)->win,
		2, 135, 0xd3d3d3, "right/left = translate_x ++/--");
}

int	mouse_hook(t_fdf **fdf)
{
	free_fdf(*fdf);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_fdf	*f;

	simple_parse(argc, argv);
	f = malloc(sizeof(t_fdf));
	allocate_fdf(&f, argv);
	f->i = malloc(sizeof(t_image));
	f->ang = malloc(sizeof(t_ang));
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, f->win_width, f->win_length, "FDF");
	f->i->i = mlx_new_image(f->mlx, f->win_width, f->win_length);
	f->i->addr = mlx_get_data_addr(f->i->i, &f->i->bpp, &f->i->l_len, &f->i->e);
	draw(&f);
	mlx_key_hook(f->win, key_hook, &f);
	mlx_hook(f->win, ON_DESTROY, 1L << 1, mouse_hook, &f);
	mlx_put_image_to_window(f->mlx, f->win, f->i->i, 0, 0);
	put_str_to_win(&f);
	mlx_loop(f->mlx);
	free_fdf(f);
	return (0);
}
