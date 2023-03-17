# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 11:52:50 by inwagner          #+#    #+#              #
#    Updated: 2023/03/17 19:59:13 by inwagner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	fdf
BNAME	:=	fdf_bonus

HDR		:=	-I ./includes/
CFLAG	:=	-Wall -Werror -Wextra
MFLAG	:=	-lbsd -lmlx -lXext -lX11 -lm

# PATHS
SRC		:=	./srcs/
OSRC	:=	./objs/
GSRC	:=	./srcs/gnl/
BSRC	:=	./srcs/bonus/

# MANDATORY
FTS		:=	fdf.c \
			fdf_utils.c \
			fdf_makers.c \
			fdf_parser.c \
			fdf_exit.c \
			fdf_matrix.c \
			fdf_matrix_utils.c \
			fdf_window.c \
			fdf_bresenham.c \
			fdf_draw.c
OBJ		:=	$(FTS:%.c=./objs/%.o)

# GNL
GFTS	:=	get_next_line.c \
			get_next_line_utils.c
GOBJ	:=	$(GFTS:%.c=./objs/%.o)

# BONUS
BFTS	:=	fdf_bonus.c \
			fdf_draw_bonus.c \
			fdf_features_bonus.c \
			fdf_window_bonus.c
BOBJ	:=	$(BFTS:%.c=./objs/%.o) \
			$(filter-out $(OSRC)fdf.o $(OSRC)fdf_draw.o $(OSRC)fdf_window.o, $(OBJ))

all: makedir $(NAME)

bonus: makedir $(BNAME)

# Compile objects together
$(NAME): $(GOBJ) $(OBJ)
	@cc $(CFLAG) $(GOBJ) $(OBJ) $(MFLAG) -o $@

$(BNAME): $(GOBJ) $(BOBJ)
	@cc $(CFLAG) $(GOBJ) $(BOBJ) $(MFLAG) -o $@

# Make Objects
makedir:
	@mkdir -p objs

$(OSRC)%.o: $(GSRC)%.c
	@cc $(CFLAG) $(HDR) $(MFLAG) -c $< -o $@

$(OSRC)%.o: $(SRC)%.c
	@cc $(CFLAG) $(HDR) $(MFLAG) -c $< -o $@

$(OSRC)%.o: $(BSRC)%.c
	@cc $(CFLAG) $(HDR) $(MFLAG) -c $< -o $@

clean:
	@[ -d ./objs ] && rm -rf ./objs || [ -f Makefile ]

fclean: clean
	@[ -f ./fdf ] && rm fdf && echo FdF cleaned ||  [ -f Makefile ]
	@[ -f ./fdf_bonus ] && rm fdf_bonus && echo FdF Bonus cleaned || [ -f Makefile ]

re: fclean all

.PHONY: all makedir bonus clean fclean re
