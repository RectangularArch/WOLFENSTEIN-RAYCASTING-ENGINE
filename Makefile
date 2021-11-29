# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csilverb <csilverb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/21 19:30:07 by csilverb          #+#    #+#              #
#    Updated: 2021/04/03 18:17:45 by csilverb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

LIBFT = ./libft/libft.a

MLX_LIBFT = libmlx.dylib

SRCS =  main.c \
		parser/parse_link.c \
		parser/parse_map_utils.c \
		parser/parse_map.c \
		parser/parse_resolution.c \
		parser/parse_rgb.c \
		parser/parser_utils.c \
		parser/parser.c \
		error_handler/error_handler.c \
		get_next_line/get_next_line_utils.c \
		get_next_line/get_next_line.c \
		engine/engine.c \
		engine/screen.c \
		engine/text_reader.c \
		engine/draw_utils.c \
		engine/key_hook.c \
		engine/sort_sprites.c \
		engine/wall_cast.c \
		engine/wall_cast_utils.c \
		engine/sprite_cast.c \

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

INCLUDES = -I ./includes/

OBJS	= ${SRCS:.c=.o}

${NAME}:	${OBJS}
			$(MAKE) -C ./minilibx_mms_20200219
			cp -a minilibx_mms_20200219/libmlx.dylib .
			$(MAKE) bonus -C ./libft
			${CC} ${CFLAGS} ${INCLUDES} ${OBJS} ${LIBFT} ${MLX_LIBFT} -o $(NAME)

all:		${NAME}

clean:
			$(MAKE) clean -C ./libft
			rm -f ${OBJS}
			rm -f screenshot.bmp

fclean:		clean 
			$(MAKE) clean -C ./minilibx_mms_20200219
			$(MAKE) fclean -C ./libft
			rm -f ${NAME}
			rm -f norminette_log.txt
			rm -f libmlx.dylib

re:			fclean all

start:
			./cub3D map.cub

save:
			./cub3D map.cub "--save"

norme:
	norminettev2 ./libft/*.c ./includes/*.h ${SRCS} > norminette_log.txt

.PHONY:		all clean fclean re bonus