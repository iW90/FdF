/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_zoom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:08:22 by inwagner          #+#    #+#             */
/*   Updated: 2023/03/13 21:45:06 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//[0] Quantidade
//[1] Maior
//[2] Menor
void	get_average(double zcoord, int zdata[3])
{
	if (zcoord)
		zdata[0]++;
	if (zcoord > zdata[1])
		zdata[1] = zcoord;
	if (zcoord < zdata[2])
		zdata[2] = zcoord;
}

static void	clear_board(t_mdata *m)
{
	char	*eraser;
	int		i;

	eraser = m->image->addr;
	i = 0;
	while (i < WIN_HEIGHT * m->image->llen)
	{
		eraser[i] = 0;
		i++;
	}
}

void	scaler(t_mdata *m, double scale)
{
	double	matrix[4][4];

	fill_matrix(matrix, scale);
	apply_dot_prod(m, matrix);
	clear_board(m);
	print_lines(m);
	mlx_put_image_to_window(m->mlxm, m->wind, m->image->img, 10, 10);
}
