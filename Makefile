# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 11:52:50 by inwagner          #+#    #+#              #
#    Updated: 2023/03/14 22:03:49 by inwagner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf
CFLAG	=	-Wall -Werror -Wextra
MFLAG	=	-lbsd -lmlx -lXext -lX11 -lm
HDR		=	-I ./includes/
LBX		=	/usr/local/lib/libmlx.a
GNL		=	./gnl/get_next_line.c \
			./gnl/get_next_line_utils.c
FTS		=	./src/fdf.c \
			./src/fdf_utils.c \
			./src/fdf_makers.c \
			./src/fdf_parser.c \
			./src/fdf_exit.c \
			./src/fdf_matrix.c \
			./src/fdf_matrix_utils.c \
			./src/fdf_window.c \
			./src/fdf_bresenham.c \
			./src/fdf_draw.c \
			./src/fdf_features.c

all:
	cc ${CFLAG} ${HDR} ${FTS} ${GNL} ${LBX} ${MFLAG} -g -o ${NAME}

clean:
	@[ -f ./fdf ] && rm -f ./fdf || echo no fdf file

re: clean all
