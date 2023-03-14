/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_zoom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:08:22 by inwagner          #+#    #+#             */
/*   Updated: 2023/03/14 13:24:51 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scaler(t_mdata *m, double scale)
{
	double	matrix[4][4];

	fill_matrix(matrix, scale);
	apply_dot_prod(m, matrix);
	redraw(m);
	//mlx_string_put(m->mlxm, m->wind, 10, 530, 0xffffff, "MENU ROW NO SEU COL");
}

void	move_map(t_mdata *m, int width, int height)
{
	m->ud += height;
	m->lr += width;
	redraw(m);
}

void	reset_coords(t_coordinates **coord, int row, int col)
{
	int i;
	int j;

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
	m->lr = 0;
	m->ud = 0;
	reset_coords(m->coord, m->row, m->col);
	matrix_maker(m);
	redraw(m);
}
