/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:01:05 by inwagner          #+#    #+#             */
/*   Updated: 2023/03/12 12:19:25 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// TRATAMENTO DE ERRO
/* A função "perror" imprime a mensagem referente ao último erro gravado, e a
 * "strerror" imprime uma mensagem de erro de acordo com o número passado pelo
 * parâmetro "errn". A lista de erros está disponível no arquivo "error.md".
 */
void	print_error(int errn)
{
	if (errn == -1)
		perror("");
	else
		write(2, strerror(errn), ft_strlen(strerror(errn)));
	write(2, "\n", 1);
	exit(-1);
}

void	super_free(int coltofree, t_mdata *m, int errn)
{
	int	i;

	i = 0;
	while (i < coltofree)
	{
		free(m->coord[i]);
		i++;
	}
	if (coltofree)
		free(m->coord);
	if (errn)
		print_error(errn);
}
