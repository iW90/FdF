/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:52:59 by inwagner          #+#    #+#             */
/*   Updated: 2023/03/12 11:14:16 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//void	printmap(t_mdata *ms);

int	main(int argc, char *argv[])
{
	int			fd;
	int			len;
	int			ext;
	t_mdata		mlxdata;
	t_image		img;

	/* Preenche as structs com zeros e nulls */
	mlxdata = (t_mdata) {0};
	img = (t_image) {0};
	
	/* Validação do nome do arquivo */
	if (argc != 2)
		print_error(22);
	len = ft_strlen(argv[1]);
	ext = ft_strncmp(&argv[1][len - 4], ".fdf", 5);
	if (len < 5 || ext)
		print_error(22);

	/* Mapeando dimensões */
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error(-1);
	define_size(&mlxdata, fd);
	fd = close(fd);


	/* Clonando mapa */
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error(-1);
	map_creator(&mlxdata, fd);

	/* Matrix */
	mlxdata.zoom = WIN_HEIGHT / sqrt(pow(mlxdata.col, 2) + pow(mlxdata.row, 2));
	printf("Zoom: %f\n", mlxdata.zoom);
	fill_matrix(mlxdata.matrix, 1);
	translation_matrix(mlxdata.matrix, mlxdata.row, mlxdata.col);
	concat_matrix(mlxdata.matrix, mlxdata.zoom);
	mod_coord(&mlxdata, mlxdata.matrix);
	
	fd = close(fd);

	/* LBX */
	mlxdata.image = &img;
	mlxconfig(&mlxdata);

	/* Drawing */
	
	
	return (0);
}

