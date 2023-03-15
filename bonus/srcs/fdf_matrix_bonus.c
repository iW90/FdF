/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_matrix_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:37:24 by inwagner          #+#    #+#             */
/*   Updated: 2023/03/15 11:53:17 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_bonus.h"

// ROTACIONA O MAPA: TRANSLAÇÃO
/* res[3][0] se refere ao eixo X
 * res[3][1] se refere ao eixo Y
 * res[3][2] se refere ao eixo Z
 * res[2][2] se refere ao ajuste da escala de Z
 */
void	translation_matrix(double mtrans[4][4], int row, int col)
{
	mtrans[3][0] = row / 2;
	mtrans[3][1] = col / 2;
	mtrans[3][2] = (row + col) / 2;
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

void	apply_dot_prod(t_mdata *m, double matrix[4][4])
{
	int		i;
	int		j;

	i = 0;
	while (i < m->col)
	{
		j = 0;
		while (j < m->row)
		{
			dot_product(&m->coord[i][j], matrix);
			j++;
		}
		i++;
	}
}

// ISOMETRIC PROJETION - ROTATION ANGLES
/* Na projeção isométrica, o eixo X é inclinado em 45º, enquanto o
 * eixo Z é inclinado cerca de 35.264° (arctg(1/√2)).
 * (M_PI * 0.25) radianos equivale ao ângulo de 45º
 * (M_PI * 0.304) radianos equivale ao ângulo de 54.736º
 *     (complemento do 35.264°)
 * https://en.wikipedia.org/wiki/Isometric_projection
 */
void	matrix_combinator(double mmatrix[4][4], double scale)
{
	double	mtemp[4][4];
	double	mcopy[4][4];

	copy_matrix(mmatrix, mcopy);
	fill_matrix(mtemp, 1);
	angulation_matrix(mtemp, M_PI * 0.25, 'z');
	multiplier_matrix(mcopy, mtemp, mmatrix);
	copy_matrix(mmatrix, mcopy);
	fill_matrix(mtemp, 1);
	angulation_matrix(mtemp, M_PI * 0.304, 'x');
	multiplier_matrix(mcopy, mtemp, mmatrix);
	copy_matrix(mmatrix, mcopy);
	fill_matrix(mtemp, scale);
	mtemp[3][3] = 1;
	multiplier_matrix(mcopy, mtemp, mmatrix);
}
