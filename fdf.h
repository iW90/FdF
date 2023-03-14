/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:53:04 by inwagner          #+#    #+#             */
/*   Updated: 2023/03/14 14:29:43 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "/usr/local/include/mlx.h"
# include "get_next_line.h"

# define ESC_KEY 65307
# define LEFT_KEY 65361
# define UP_KEY 65362
# define RIGHT_KEY 65363
# define MORE_KEY 65451
# define LESS_KEY 65453
# define DOWN_KEY 65364
# define BACK_KEY 65288
# define WIN_WIDTH 1920/2
# define WIN_HEIGHT 1080/2

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		llen;
	int		endian;
}	t_image;

typedef struct s_coordinates
{
	double	coord[3];
	int		z;
	int		color;
}	t_coordinates;

typedef struct s_mdata
{
	int				row;
	int				col;
	double			zoom;
	void			*wind;
	void			*mlxm;
	double			matrix[4][4];
	int				zhigher;
	int				zlower;
	int				mov[2];
	t_image			*image;

	t_coordinates	**coord;
}	t_mdata;

typedef struct s_delta
{
	int	dx;
	int	dy;
	int	dm;
	int	x0;
	int	x1;
	int	y0;
	int	y1;
}	t_delta;

int		ft_strncmp(const char *stra, const char *strb, size_t n);
int		ft_atoi_base(const char *str, int base);

void	define_size(t_mdata *m, int fd);
void	map_creator(t_mdata *m, int fd);

void	super_free(int rowtofree, t_mdata *m, int errn);
void	print_error(int errn);

void	mlxconfig(t_mdata *m);
int		exit_fdf(t_mdata *m);

void	plot_line(t_mdata *m, t_coordinates *stt, t_coordinates *end);
void	put_pixel(t_mdata *m, int x, int y, int color);
void	print_lines(t_mdata *m);
void	redraw(t_mdata *m);

void	apply_dot_prod(t_mdata *m, double matrix[4][4]);
void	angulation_matrix(double mat[4][4], double rad, char axis);
void	matrix_combinator(double res[4][4], double scale);
void	translation_matrix(double res[4][4], int row, int col);

void	fill_matrix(double matrix[4][4], double n);
void	copy_matrix(double srcm[4][4], double dstm[4][4]);
void	multiplier_matrix(double matA[4][4], \
		double matB[4][4], double mProduct[4][4]);

void	map_maker(char **argv, t_mdata *mlxdata);
void	matrix_maker(t_mdata *mlxdata);

void	scaler(t_mdata *m, double scale);
void	move_map(t_mdata *m, int width, int height);
void	reset_coords(t_coordinates **coord, int row, int col);
void	reset_map(t_mdata *m);

#endif