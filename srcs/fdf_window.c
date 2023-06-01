/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:20:23 by inwagner          #+#    #+#             */
/*   Updated: 2023/06/01 09:56:28 by inwagner         ###   ########.fr       */
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
	return (0);
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
	m->image->addr = mlx_get_data_addr(m->image->img, \
		&m->image->bpp, &m->image->llen, &m->image->endian);
	print_lines(m);
	mlx_put_image_to_window(m->mlxm, m->wind, m->image->img, 0, 0);
	mlx_loop(m->mlxm);
}
