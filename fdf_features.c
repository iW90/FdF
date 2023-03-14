/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_features.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:08:22 by inwagner          #+#    #+#             */
/*   Updated: 2023/03/14 19:06:07 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// ZOOM
void	scaler(t_mdata *m, double scale)
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

// RESETAR MAPA
/* Redefinição dos valores para que a imagem volte ao ponto inicial.
 * Necessário redefinir as coordenas que saíram do lugar após a movimentação
 * e reatribuir o valor inicial da coordenada Z. Lembrando que:
 * coord[0] = x (largura/colunas)
 * coord[1] = y (altura/linhas)
 * coord[2] = z (relevo/depressão do mapa)
 */
static void	reset_coords(t_coordinates **coord, int row, int col)
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
