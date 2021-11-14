# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/11 21:12:53 by nfedayki          #+#    #+#              #
#    Updated: 2021/05/16 18:22:18 by nfedayki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC_DIR = src

SRC_NAME =	main.c \
		ft_error.c \
		ft_exit.c \
		str_utils.c \
		str_utils_2.c \
		lst_utils.c \
		lst_utils_2.c \
		my_mlx.c \
		sprites_utils.c \
		ft_strtrim_err2.c \
		ft_split.c \
		parse_trigger.c \
		parse_line.c \
		id_filler.c \
		id_filler_2.c \
		parse_map.c \
		control_map.c \
		game_struct.c \
		player_init.c \
		sprites.c \
		movements_key.c \
		move_set.c \
		render_engine.c \
		render_engine_ray.c \
		render_engine_img.c \
		bmp_save.c \
		bmp_export.c \
		recursive_gnl.c \
		kostil_2_parse.c


SRC = $(addprefix $(SRC_DIR)/,$(SRC_NAME))

OBJ_DIR = objects

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_DIR)/,$(OBJ_NAME))

NAME = Cub3D

INC = -I includes -I$(MLX_DIR)

CC = gcc
RM = rm -f

CFLAGS = -Wall -Werror -Wextra

MLX = libmlx.a

MLX_LIBS = -lmlx

MLX_INC = -L$(MLX_DIR)

MLX_DIR =
	MLX_DIR += minilibx_opengl_20191021
	MLX_INC += -framework OpenGL -framework AppKit

all: $(MLX) $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	    $(CC) $(INC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
		mkdir -p $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INC) $(MLX_INC) $(MLX_LIBS)

$(MLX):
		@make -C $(MLX_DIR) $(MLX_LIBS)

clean:
		$(RM) -r $(OBJ_DIR)

fclean:		clean
		$(RM) $(NAME)
		@make -C $(MLX_DIR) clean

re:		fclean all

.PHONY:	clean re fclean

