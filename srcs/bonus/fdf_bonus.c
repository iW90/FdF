/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:52:59 by inwagner          #+#    #+#             */
/*   Updated: 2023/03/15 14:25:04 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_bonus.h"

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
