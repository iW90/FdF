/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_features.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:08:22 by inwagner          #+#    #+#             */
/*   Updated: 2023/03/14 17:33:05 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scaler(t_mdata *m, double scale)
{
	double	matrix[4][4];

	fill_matrix(matrix, scale);
	apply_dot_prod(m, matrix);
	redraw(m);
}

void	move_map(t_mdata *m, int width, int height)
{
	m->mov[0] += width;
	m->mov[1] += height;
	redraw(m);
}

void	reset_coords(t_coordinates **coord, int row, int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < col)
	{
		j = 0;
		while (j < row)
		{
			coord[i][j].coord[0] = i;
			coord[i][j].coord[1] = j;
			coord[i][j].coord[2] = coord[i][j].z;
			j++;
		}
		i++;
	}
}

void	reset_map(t_mdata *m)
{
	m->mov[0] = 0;
	m->mov[1] = 0;
	reset_coords(m->coord, m->row, m->col);
	matrix_maker(m);
	redraw(m);
}
