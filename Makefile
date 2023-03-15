# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 11:52:50 by inwagner          #+#    #+#              #
#    Updated: 2023/03/15 20:56:16 by inwagner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf
BNAME	=	fdf_bonus

HDR		=	-I ./includes/
CFLAG	=	-Wall -Werror -Wextra
MFLAG	=	-lbsd -lmlx -lXext -lX11 -lm
LBX		=	/usr/local/lib/libmlx.a

# MANDATORY
SRC		=	./srcs/
FTS		=	fdf_utils.c \
			fdf_makers.c \
			fdf_parser.c \
			fdf_exit.c \
			fdf_matrix.c \
			fdf_matrix_utils.c \
			fdf_window.c \
			fdf_bresenham.c \
			fdf_draw.c \
			get_next_line_utils.c \
			get_next_line.c
OBJ		=	$(FTS:.c=.o)

# BONUS
BSRC	=	./bonus/srcs/
BFTS	=	fdf_utils_bonus.c \
			fdf_makers_bonus.c \
			fdf_parser_bonus.c \
			fdf_exit_bonus.c \
			fdf_matrix_bonus.c \
			fdf_matrix_utils_bonus.c \
			fdf_window_bonus.c \
			fdf_bresenham_bonus.c \
			fdf_draw_bonus.c \
			fdf_features_bonus.c \
			get_next_line_utils_bonus.c \
			get_next_line_bonus.c
BOBJ	=	$(BFTS:.c=.o)

all: $(NAME)

$(NAME): makefdf $(OBJ)
	@cc $(CFLAG) $(HDR) ./objs/$(NAME).o $(addprefix ./objs/, ${FTS:.c=.o}) $(MFLAG) -o fdf

$(OBJ):
	@cc $(CFLAG) -c ./srcs/$(@:.o=.c) $(HDR) -o ./objs/$@

makefdf: mdir
	@cc $(CFLAG) -c ./srcs/$(NAME).c $(HDR) -o ./objs/$(NAME).o

mdir:
	@mkdir -p objs

bonus: clean $(BNAME)

$(BNAME): makefdfbonus $(BOBJ)
	@cc $(CFLAG) $(HDR) ./objs/$(BNAME).o $(addprefix ./objs/, ${BFTS:.c=.o}) $(MFLAG) -o fdf_bonus

$(BOBJ):
	@cc $(CFLAG) -c ./bonus/srcs/$(@:.o=.c) $(HDR) -o ./objs/$@

makefdfbonus: mdir
	@cc $(CFLAG) -c ./bonus/srcs/$(BNAME).c $(HDR) -o ./objs/$(BNAME).o
	
clean:
	@[ -d ./objs ] && rm -rf ./objs || echo Object directory doesn\'t exist

fclean: clean
	@[ -f ./fdf ] && rm fdf && echo fdf cleaned || echo Program fdf isn\'t compiled
	@[ -f ./fdf_bonus ] && rm fdf_bonus && echo bonus cleaned || echo Bonus fdf isn\'t compiled

re: fclean all

val:
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=teste -s ./fdf

valbonus:
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=teste -s ./fdf_bonus

.PHONY: all mdir makefdf bonus clean fclean re val valbonus
