/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_features.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:08:22 by inwagner          #+#    #+#             */
/*   Updated: 2023/03/14 21:29:11 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



// ZOOM
void	zoom_map(t_mdata *m, double scale)
{
	double	matrix[4][4];

	fill_matrix(matrix, scale);
	apply_dot_prod(m, matrix);
	redraw(m);
}

// MOVIMENTAÇÃO DO MAPA HORIZONTAL E VERTICALMENTE
void	move_map(t_mdata *m, int width, int height)
{
	m->mov[0] += width;
	m->mov[1] += height;
	redraw(m);
}

// ROTAÇÃO (EIXOS X, Y OU Z)
void	rotate_map(t_mdata *m, int signal, int x, int y)
{
	char	axis;
	double matrix[4][4];

	if (x > 13 && x < 73 \
		&& y < WIN_HEIGHT - 14 && y > WIN_HEIGHT - 35)
		axis = 'x';
	if (x > 73 && x < 133 \
		&& y < WIN_HEIGHT - 14 && y > WIN_HEIGHT - 35)
		axis = 'y';
	if (x > 133 && x < 193 \
		&& y < WIN_HEIGHT - 14 && y > WIN_HEIGHT - 35)
		axis = 'z';
	fill_matrix(matrix, 1);
	angulation_matrix(matrix, signal * M_PI / 12, axis);
	apply_dot_prod(m, matrix);
	redraw(m);
}

// Z SCALER
void	z_scaler(t_mdata *m, char button)
{
	static double zscale;
	
	if (!zscale)
		zscale = 1;
	if (button == '+')
		zscale += 0.05;
	if (button == '-')
		zscale -= 0.05;
	if (button == 'r')
	{
		zscale = 1;
		return ;
	}
	reset_coords(m->coord, m->row, m->col, zscale);
	apply_dot_prod(m, m->matrix);
	redraw(m);
}
