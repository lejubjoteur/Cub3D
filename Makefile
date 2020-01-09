# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qgimenez <qgimenez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/27 09:10:23 by qgimenez          #+#    #+#              #
#    Updated: 2020/01/09 14:37:35 by qgimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = gcc

CFLAGS  = -Wall -Wextra -Werror

FT = ./src/main.c ./src/get_next_line.c ./src/get_next_line_utils.c ./src/ft_split.c ./src/ft_strncmp.c ./src/ft_atoi.c ./src/parse_file.c ./src/parse_file2.c ./src/ft_isdigit.c ./src/ft_isalpha.c ./src/ft_memchr.c ./src/ft_delspace.c ./src/window.c ./src/window2.c ./src/mouvement.c ./src/sprite.c ./src/controle.c ./src/weapon.c ./src/crosshair.c ./src/fire.c ./src/hit_sprite.c ./src/ft_itoa.c ./src/ammo.c ./src/window3.c ./src/sprite2.c ./src/controle2.c ./src/weapon2.c ./src/window4.c ./src/ft_error.c ./src/check_map.c ./src/ft_save.c ./src/parse_file3.c ./src/ft_duplicatemap.c

FO      = ${FT:.c=.o}

INCLUDE = ./include/cub3d.h

NAMA    = cub3d.a

NAME	= cub3d

LINK	= ar rc

$(NAME):    ${FO} ${FT} include/cub3d.h mlx/libmlx.a
			${LINK} ${NAMA} ${FO}
			${CC} -O3 -I /usr/local/include -L ./mlx -lmlx -framework OpenGL -framework AppKit ${NAMA} -o ${NAME}
			rm cub3d.a

mlx/libmlx.a:
	make -C ./mlx CFLAGS="-D GL_SILENCE_DEPRECATION -Wno-deprecated-declarations -DSTRINGPUTX11"

all:        ${NAME}

gc:
	${CC} ${CFLAGS} ${NAME}

clean:
	rm -rf ${FO}

fclean:     clean
	rm -rf ${NAME}

re:	fclean all

.PHONY: all clean fclean re