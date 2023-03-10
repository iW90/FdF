/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:23:44 by inwagner          #+#    #+#             */
/*   Updated: 2023/03/10 15:54:34 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	putpixel(t_mdata *m, int x, int y, int color)
{
	char	*brush;

	if (y > WIN_HEIGHT - 15 || y < 0 || x > m->image->llen || x < 0)
		return ;
	if (!color)
		color = 0xFFFFFF;
	brush = m->image->addr + (y * m->image->llen + x * (m->image->bpp / 8));
	*(unsigned int *)brush = color;
}

void	print_bresenham(t_mdata *m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->col)
	{
		j = 0;
		while (j < m->row)
		{
			if ((i + 1) != m->col)
				plot_line(m, &m->coord[i][j], &m->coord[i + 1][j]);
			if ((j + 1) != m->row)
				plot_line(m, &m->coord[i][j], &m->coord[i][j + 1]);
			j++;
		}
		i++;
	}
}

// FUNÇÃO PARA DESENHAR DIRETO NA JANELA 
// (NÃO PERMITIDO NESSE PROJETO)
/*
void	paint(t_mdata *m)
{
	int	x;
	int	y;
	int	color;

	x = 150;
	color = 0xFF0000;

	while (x < 156)
	{
		y = 0;
		
		while (y < 200)
		{
			putpixel(m, x, y, color);
			y++;
		}
		x++;
	}
}
*/