/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:37:24 by inwagner          #+#    #+#             */
/*   Updated: 2023/03/12 12:46:26 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// ROTACIONA O MAPA: TRANSLAÇÃO
/* res[3][0] se refere ao eixo X
 * res[3][1] se refere ao eixo Y
 * res[3][2] se refere ao eixo Z
 * res[2][2] se refere ao ajuste da escala de Z
 */
void	translation_matrix(double res[4][4], int row, int col)
{
	res[3][0] = row;
	res[3][1] = -col;
	res[3][2] = -5;
	res[2][2] = 0.1;//coloca m->zoom pra testar
}

// ROTACIONA O MAPA: ROTAÇÃO
/* O mapa gira em torno de um dos eixos, passado por parâmetro.
 * https://www.scratchapixel.com/lessons/mathematics-physics-for-computer-graphics/geometry/how-does-matrix-work-part-1.html
 */
void	angulation_matrix(double mat[4][4], double rad, char axis)
{
	if (axis == 'x')
	{
		mat[1][1] = cos(rad);
		mat[1][2] = sin(rad);
		mat[2][1] = -sin(rad);
		mat[2][2] = cos(rad);
	}
	if (axis == 'y')
	{
		mat[0][0] = cos(rad);
		mat[0][2] = -sin(rad);
		mat[2][0] = sin(rad);
		mat[2][2] = cos(rad);
	}
	if (axis == 'z')
	{
		mat[0][0] = cos(rad);
		mat[0][1] = sin(rad);
		mat[1][0] = -sin(rad);
		mat[1][1] = cos(rad);
	}
}

// PRODUTO ESCALAR (DOT PRODUCT)
/* Função coringa para aplicar uma multiplicação nos valores X, Y e Z.
 * https://www.scratchapixel.com/lessons/mathematics-physics-for-computer-graphics/geometry/math-operations-on-points-and-vectors.html
 */
static void	dot_product(t_coordinates *c, double m[4][4])
{
	double	temp[3];

	temp[0] = c->coord[0] * m[0][0] + c->coord[1] * m[1][0] + \
	c->coord[2] * m[2][0] + 1 * m[3][0];
	temp[1] = c->coord[0] * m[0][1] + c->coord[1] * m[1][1] + \
	c->coord[2] * m[2][1] + 1 * m[3][1];
	temp[2] = c->coord[0] * m[0][2] + c->coord[1] * m[1][2] + \
	c->coord[2] * m[2][2] + 1 * m[3][2];
	c->coord[0] = temp[0];
	c->coord[1] = temp[1];
	c->coord[2] = temp[2];
}

void	modifier_dot_prod(t_mdata *m, double mtest[4][4])
{
	int		i;
	int		j;

	i = 0;
	while (i < m->col)
	{
		j = 0;
		while (j < m->row)
		{
			dot_product(&m->coord[i][j], mtest);
			j++;
		}
		i++;
	}
}

//
/*
 * M_PI * 0.25 angulo de 45º
 * M_PI * 0.304 angulo de //54,736 //35,264 (arctg(30))
 */
void	concat_matrix(double res[4][4], double scale)
{
	double	mz[4][4];
	double	rescopy[4][4];

	copy_matrix(res, rescopy);
	fill_matrix(mz, 1);
	angulation_matrix(mz, M_PI * 0.25, 'z');
	multiply_matrix(rescopy, mz, res);
	copy_matrix(res, rescopy);
	fill_matrix(mz, 1);
	angulation_matrix(mz, M_PI * 0.304, 'x');
	multiply_matrix(rescopy, mz, res);
	copy_matrix(res, rescopy);
	fill_matrix(mz, scale);
	mz[3][3] = 1;
	multiply_matrix(rescopy, mz, res);
}
