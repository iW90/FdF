/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_dimensioner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:53:10 by inwagner          #+#    #+#             */
/*   Updated: 2023/03/10 11:50:05 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// DIMENSIONADOR
/* Realiza a contagem das colunas e linhas para, respectivamente, definir a
 * largura e altura do mapa. A quantidade de colunas se refere ao eixo X,
 * enquanto a quantidade de linhas se refere ao eixo Y.
 */
static int	counter_col(char *strrow, t_mdata *m)
{
	while (*strrow != '\n' && *strrow != '\0')
	{
		while (*strrow == ' ')
			strrow++;
		if (*strrow != '\n' && *strrow != '\0')
			m->col++;
		while (*strrow != ' ' && *strrow != '\n' && *strrow != '\0')
			strrow++;
	}
	return (m->col);
}

int	define_size(t_mdata *m, int fd)
{
	char	*gnlrow;

	m->row = 0;
	m->col = 0;
	gnlrow = get_next_line(fd);
	m->col = counter_col(gnlrow, m);
	free(gnlrow);
	while (gnlrow)
	{
		gnlrow = get_next_line(fd);
		if (gnlrow)
		{
			m->row++;
			free(gnlrow);
		}
	}
	if (m->row != 0)
		m->row++;
	return (0);
}
