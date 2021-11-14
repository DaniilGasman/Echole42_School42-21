# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dminerva <dminerva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/25 19:40:51 by nfedayki          #+#    #+#              #
#    Updated: 2021/07/18 17:30:52 by dminerva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	minishell

SRC_DIR = src

SRC_NAME =	main.c \
		args_utils.c\
		args_utils2.c\
		bash.c\
		bin.c\
		cd.c\
		env_utils.c\
		env_utils2.c\
		exit.c\
		ft_split_case.c\
		ft_utils.c\
		ft_utils2.c\
		ft_utils3.c\
		ft_utils4.c\
		gnl.c\
		handlers.c\
		lib_utils.c\
		lib_utils2.c\
		lib_utils3.c\
		lib_utils4.c\
		parcer.c\
		pipe_utils.c\
	

SRC = $(addprefix $(SRC_DIR)/,$(SRC_NAME))

OBJ_DIR = objects

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_DIR)/,$(OBJ_NAME))

INC = /includes/utils.h

RLINE = -L/Users/$(USER)/.brew/opt/readline/lib -lreadline

CC = gcc
RM = rm -f

CFLAGS = -Wall -Werror -Wextra 
all: $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	   $(CC) $(CFLAGS) -c $< -o $@ 
		
$(OBJ_DIR):
		mkdir -p $@

 $(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC)  $(RLINE)    -o $(NAME) 

clean:
		$(RM) -r $(OBJ_DIR)
		
fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	clean re fclean
