/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:09:53 by inwagner          #+#    #+#             */
/*   Updated: 2023/03/12 16:42:03 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// DIMENSIONADOR
/* Realiza a contagem das colunas e linhas para definir, respectivamente, a
 * largura e altura do mapa. A quantidade de colunas se refere ao eixo X,
 * enquanto a quantidade de linhas se refere ao eixo Y.
 */
static int	define_width(char *strrow, t_mdata *m)
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

void	define_size(t_mdata *m, int fd)
{
	char	*gnlrow;

	m->row = 0;
	m->col = 0;
	gnlrow = get_next_line(fd);
	m->col = define_width(gnlrow, m);
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
}

// PARSEADOR
/* Com a largura e a altura já definidas, o parseador percorre novamente
 * o mapa, dessa vez coletando as informações e atribuindo às posições
 * alocadas na memória.
 */
static int	get_data(char *strrow, t_mdata *m, int j, int i)
{
	char	*dif;

	dif = strrow;
	while (*strrow == ' ')
		strrow++;
	if (*strrow != '\n' || *strrow != '\0')
	{
		m->coord[i][j].coord[0] = i;
		m->coord[i][j].coord[1] = j;
		m->coord[i][j].coord[2] = ft_atoi_base(strrow, 10);
		while (*strrow != ' ' && *strrow != ',' \
		&& *strrow != '\n' && *strrow != '\0')
			strrow++;
		if (*strrow == ',')
		{
			strrow = strrow + 3;
			m->coord[i][j].color = ft_atoi_base(strrow, 16);
			while (*strrow != ' ' && *strrow != '\n' && *strrow != '\0')
				strrow++;
		}
		else
			m->coord[i][j].color = 0;
	}
	return (strrow - dif);
}

static void	populate_map(t_mdata *m, int fd)
{
	int		j;
	int		i;
	char	*strrow;
	int		dif;

	j = 0;
	while (j < m->row)
	{
		dif = 0;
		strrow = get_next_line(fd);
		i = 0;
		while (i < m->col)
		{
			dif += get_data(&strrow[dif], m, j, i);
			i++;
		}
		j++;
		free(strrow);
	}
}

void	map_creator(t_mdata *m, int fd)
{
	int	i;

	m->coord = malloc((sizeof(t_coordinates *) * m->col));
	if (!m->coord)
		super_free(0, m, -1);
	i = 0;
	while (i < m->col)
	{
		m->coord[i] = malloc((sizeof(t_coordinates) * m->row));
		if (!m->coord[i])
			super_free(i, m, -1);
		i++;
	}
	populate_map(m, fd);
}
