/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:23:44 by inwagner          #+#    #+#             */
/*   Updated: 2023/03/14 13:04:49 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_mdata *m, int x, int y, int color)
{
	char	*brush;

	if (y > WIN_HEIGHT - 15 || y < 0 || x > m->image->llen || x < 0)
		return ;
	if (!color)
		color = 0xFFFFFF;
	brush = m->image->addr + (y * m->image->llen + x * (m->image->bpp / 8));
	*(unsigned int *)brush = color;
}

void	print_lines(t_mdata *m)
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

void	redraw(t_mdata *m)
{
	clear_board(m);
	print_lines(m);
	mlx_put_image_to_window(m->mlxm, m->wind, m->image->img, 0, 0);
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