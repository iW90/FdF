/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_makers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:33:21 by inwagner          #+#    #+#             */
/*   Updated: 2023/03/12 19:48:34 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_maker(char **argv, t_mdata *mlxdata)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error(-1);
	define_size(mlxdata, fd);
	fd = close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error(-1);
	map_creator(mlxdata, fd);
	fd = close(fd);
}

void	matrix_maker(t_mdata *mlxdata)
{
	mlxdata->zoom = WIN_HEIGHT / sqrt(pow(mlxdata->col, 2) \
	+ pow(mlxdata->row, 2));
	fill_matrix(mlxdata->matrix, 1);
	translation_matrix(mlxdata->matrix, mlxdata->row, mlxdata->col);
	matrix_combinator(mlxdata->matrix, mlxdata->zoom);
	apply_dot_prod(mlxdata, mlxdata->matrix);
}
