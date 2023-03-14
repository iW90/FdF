/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:52:59 by inwagner          #+#    #+#             */
/*   Updated: 2023/03/14 14:38:51 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int			len;
	int			ext;
	t_mdata		mlxdata;
	t_image		img;

	if (argc != 2)
		print_error(22);
	len = ft_strlen(argv[1]);
	ext = ft_strncmp(&argv[1][len - 4], ".fdf", 5);
	if (len < 5 || ext)
		print_error(22);
	mlxdata = (t_mdata){0};
	img = (t_image){0};
	mlxdata.image = &img;
	map_maker(argv, &mlxdata);
	matrix_maker(&mlxdata);
	mlxconfig(&mlxdata);
	return (0);
}

//norminette fdf_bresenham.c fdf_draw.c fdf_exit.c fdf_features.c fdf_makers.c fdf_matrix_utils.c fdf_matrix.c fdf_parser.c fdf_utils.c fdf_window.c get_next_line.c get_next_line_utils.c main.c
