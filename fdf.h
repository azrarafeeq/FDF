/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:57:24 by arafeeq           #+#    #+#             */
/*   Updated: 2023/02/06 16:45:28 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"

typedef struct s_image {
	void	*i;
	char	*addr;
	int		bpp;
	int		l_len;
	int		e;
}				t_image;

typedef struct s_map {
	int		height;
	int		width;
	int		**z;
	int		**colour;
}				t_map;

typedef struct s_coords {
	double	x;
	double	y;
}				t_coords;

typedef struct s_balg {
	double	delta_x;
	double	delta_y;
	int		step_1;
	int		step_2;
	double	diff;
	int		swap;
	int		i;
}				t_balg;

typedef struct s_ang {
	double	a;
	double	b;
	double	g;
}				t_ang;

typedef struct s_rm {
	double	a11;
	double	a12;
	double	a13;
	double	a21;
	double	a22;
	double	a23;
	double	a31;
	double	a32;
	double	a33;
}				t_rm;

typedef struct s_fdf {
	void	*mlx;
	void	*win;
	double	win_width;
	double	win_length;
	double	m_width;
	double	m_length;
	double	translate_x;
	double	translate_y;
	double	zoom;
	double	zoom_z;
	double	alpha;
	double	beta;
	double	gamma;
	char	grad;
	t_image	*i;
	t_map	*map;
	t_ang	*ang;
	t_rm	*rm;
	t_balg	*b_alg;
}				t_fdf;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

void	simple_parse(int argc, char **argv);

void	allocate_fdf(t_fdf **fdf, char **argv);
void	allocate_map(t_fdf **fdf, char **argv);
void	allocate_rmatrice(t_ang *a, t_fdf **fdf);
t_balg	*allocate_balg(double *x, double *y, double *x2, double *y2);

void	map_height(char *filename, t_map *map);
void	map_width(char *line, t_map *map);
void	read_map(t_map *map, int fd);
void	read_map_part_2(t_map *map, int i, int j, char **split);

void	draw(t_fdf **fdf);
void	rotate_x_y(t_rm *rm, t_coords *c, int z, t_fdf **fdf);
void	bressenham(int x1, int y1, char flag, t_fdf **fdf);
void	my_mlx_pixel_put(t_fdf **data, int x, int y, int color);

int		get_sign(double num);
int		swap_content(double *int1, double *int2);
int		ft_atoi_base(char *str);

int		key_hook(int keycode, t_fdf **fdf);
void	assign_keys(int keycode, t_fdf **fdf);
int		mouse_hook( t_fdf **fdf);
void	put_str_to_win(t_fdf **fdf);
void	change(t_fdf **f);

void	free_int_array(int **int_array, int size);
void	free_char_array(char **array);
void	free_fdf(t_fdf *fdf);

#endif