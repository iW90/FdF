# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 11:52:50 by inwagner          #+#    #+#              #
#    Updated: 2023/03/14 14:34:03 by inwagner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	fdf
CFLAG	=	-Wall -Werror -Wextra
MFLAG	=	-lbsd -lmlx -lXext -lX11 -lm
HDR		=	-I ./
LBX		=	/usr/local/lib/libmlx.a
FTS		=	get_next_line.c \
			get_next_line_utils.c \
			main.c \
			fdf_utils.c \
			fdf_makers.c \
			fdf_parser.c \
			fdf_exit.c \
			fdf_matrix.c \
			fdf_matrix_utils.c \
			fdf_window.c \
			fdf_bresenham.c \
			fdf_draw.c \
			fdf_features.c \

all:
	cc ${CFLAG} ${HDR} ${FTS} ${LBX} ${MFLAG} -g -o ${NAME}

clean:
	@[ -f ./fdf ] && rm -f ./fdf || echo no fdf file

re: clean all
