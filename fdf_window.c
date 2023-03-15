/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:20:23 by inwagner          #+#    #+#             */
/*   Updated: 2023/03/14 21:34:05 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// ATALHOS DO TECLADO
/* Se pressionado o botão ESC, o programa será encerrado.
 */
static int	keyboard_commands(int nkey, t_mdata *m)
{
	if (nkey == ESC_KEY)
		exit_fdf(m);
	if (nkey == LEFT_KEY)
		move_map(m, -24, 0);
	if (nkey == RIGHT_KEY)
		move_map(m, 24, 0);
	if (nkey == UP_KEY)
		move_map(m, 0, -24);
	if (nkey == DOWN_KEY)
		move_map(m, 0, 24);
	if (nkey == BACK_KEY)
		reset_map(m);
	if (nkey == MORE_KEY)
		z_scaler(m, '+');
	if (nkey == LESS_KEY)
		z_scaler(m, '-');
	return (0);
}

// ATALHO DO MOUSE
/* nkey 1 = left click
 * nkey 3 = right click
 * nkey 4 = scroll para cima: zoom+
 * nkey 5 = scroll para baixo: zoom-
 */
static int	mouse_click(int nkey, int x, int y, t_mdata *m)
{
	if (nkey == 1)
		rotate_map(m, -1, x, y);
	if (nkey == 3)
		rotate_map(m, 1, x, y);
	if (nkey == 4)
		zoom_map(m, 1.1);
	if (nkey == 5)
		zoom_map(m, 0.9);
	return (x + y);
}

// JANELA
/* mlx_init: inicia a lbx
 * mlx_new_window: criauma nova janela com as dimensões e nome definidos.
 * mlx_new_image: inicia um espaço de desenho com as dimensões definidas.
 * mlx_hook: função genérica para criar funcionalidades.
 *   Fechar janela no botão X e pressionando ESC habilitados.
 * mlx_get_data_addr: define o endereço e atributos da janela de desenho.
 * print_lines: faz o desenho por Bresenham.
 * mlx_put_image_to_window: imprime o desenho criado na janela.
 * mlx_loop: mantém a janela funcionando sem erros.
 */
void	mlxconfig(t_mdata *m)
{
	m->mlxm = mlx_init();
	m->wind = mlx_new_window(m->mlxm, WIN_WIDTH, WIN_HEIGHT, "FdF");
	m->image->img = mlx_new_image(m->mlxm, WIN_WIDTH, WIN_HEIGHT);
	mlx_hook(m->wind, 17, 0, &exit_fdf, m);
	mlx_hook(m->wind, 2, 1L << 0, &keyboard_commands, m);
	mlx_mouse_hook(m->wind, &mouse_click, m);
	m->image->addr = mlx_get_data_addr(m->image->img, \
		&m->image->bpp, &m->image->llen, &m->image->endian);
	print_lines(m);
	mlx_put_image_to_window(m->mlxm, m->wind, m->image->img, 0, 0);
	menu(m);
	mlx_loop(m->mlxm);
}

// RESET
/* Redefinição dos valores para que a imagem volte ao ponto inicial.
 * Necessário redefinir as coordenas que saíram do lugar após a movimentação
 * e reatribuir o valor inicial da coordenada Z. Lembrando que:
 * coord[0] = x (largura/colunas)
 * coord[1] = y (altura/linhas)
 * coord[2] = z (relevo/depressão do mapa)
 * m->mov[0] = deslocamento horizontal
 * m->mov[1] = deslocamento vertical
 */
void	reset_coords(t_coordinates **coord, int row, int col, double mod)
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
			coord[i][j].coord[2] = coord[i][j].z * mod;
			j++;
		}
		i++;
	}
}

void	reset_map(t_mdata *m)
{
	m->mov[0] = 0;
	m->mov[1] = 0;
	z_scaler(m, 'r');
	reset_coords(m->coord, m->row, m->col, 1);
	matrix_maker(m);
	redraw(m);
}
