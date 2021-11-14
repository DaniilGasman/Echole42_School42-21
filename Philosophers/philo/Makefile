# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/11 21:12:53 by nfedayki          #+#    #+#              #
#    Updated: 2021/07/26 19:33:36 by nfedayki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC_DIR = src

SRC_NAME =	main.c \
		fork_utils.c \
		free_mutex.c \
		ft_print_mess.c \
		lib_utils.c \
		philo_utils.c \
		philosopher.c \


SRC = $(addprefix $(SRC_DIR)/,$(SRC_NAME))

OBJ_DIR = objects

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_DIR)/,$(OBJ_NAME))

NAME = philo

INC = -I includes 

CC = gcc
RM = rm -f

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "\n"
	@echo "\033[0;32mCompiling philo..."
	@$(CC) $(INC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
		mkdir -p $@

$(NAME): $(OBJ)
	@echo "\n"
	@echo "\033[0;32mCompiling philo..."
	@$(CC) $(CFLAGS) -o $(NAME) $(INC) $(OBJ)
	@echo "\n\033[0;0m⠄⠄⠄⢰⣧⣼⣯⠄⣸⣠⣶⣶⣦⣾⠄⠄⠄⠄⡀⠄⢀⣿⣿⠄⠄⠄⢸⡇⠄⠄\n⠄⠄⠄⣾⣿⠿⠿⠶⠿⢿⣿⣿⣿⣿⣦⣤⣄⢀⡅⢠⣾⣛⡉⠄⠄⠄⠸⢀⣿⠄\n⠄⠄⢀⡋⣡⣴⣶⣶⡀⠄⠄⠙⢿⣿⣿⣿⣿⣿⣴⣿⣿⣿⢃⣤⣄⣀⣥⣿⣿⠄\n⠄⠄⢸⣇⠻⣿⣿⣿⣧⣀⢀⣠⡌⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⠿⣿⣿⣿⠄\n⠄⢀⢸⣿⣷⣤⣤⣤⣬⣙⣛⢿⣿⣿⣿⣿⣿⣿⡿⣿⣿⡍⠄⠄⢀⣤⣄⠉⠋⣰\n⠄⣼⣖⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⢇⣿⣿⡷⠶⠶⢿⣿⣿⠇⢀⣤\n⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣽⣿⣿⣿⡇⣿⣿⣿⣿⣿⣿⣷⣶⣥⣴⣿⡗\n⢀⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠄\n⢸⣿⣦⣌⣛⣻⣿⣿⣧⠙⠛⠛⡭⠅⠒⠦⠭⣭⡻⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠄\n⠘⣿⣿⣿⣿⣿⣿⣿⣿⡆⠄⠄⠄⠄⠄⠄⠄⠄⠹⠈⢋⣽⣿⣿⣿⣿⣵⣾⠃⠄\n⠄⠘⣿⣿⣿⣿⣿⣿⣿⣿⠄\033[1;31m⣴⣿⣶⣄⠄⣴⣶⠄\033[0;0m⢀⣾⣿⣿⣿⣿⣿⣿⠃⠄⠄\n⠄⠄⠄⠄⠈⠛⢿⣿⣿⣿⠁\033[1;31m⠞⢿⣿⣿⡄⢿⣿⡇\033[0;0m⣸⣿⣿⠿⠛⠁⠄⠄⠄⠄⠄\n⠄⠄⠄⠄⠄⠄⠄⠉⠻⣿⣿⣾⣦\033[1;31m⡙⠻⣷⣾⣿⠃\033[0;0m⠿⠋⠁⠄⠄⠄⠄⠄⢀⣠⣴\n⣿⣿⣿⣶⣶⣮⣥⣒⠲⢮⣝⡿⣿⣿⡆\033[1;31m⣿⡿⠃\033[0;0m⠄⠄⠄⠄⠄⠄⠄⣠⣴⣿⣿⣿\n\n"
	@echo "\033[0;31mAll done senpai!\n"
clean:
		$(RM) -r $(OBJ_DIR)

fclean:		clean
		$(RM) $(NAME)
		@make clean

re:		fclean all

.PHONY:	clean re fclean

