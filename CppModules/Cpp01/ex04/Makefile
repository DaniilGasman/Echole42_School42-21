CC		=	clang++

CFLAGS	= 	-Wall -Wextra -Werror

NAME	=	replace

HEADER	=	Replace.hpp

SRC		=	Replace.cpp main.cpp

OBJ		=	$(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
			@echo ""
			@echo "\n\033[0;0m⠄⠄⠄⢰⣧⣼⣯⠄⣸⣠⣶⣶⣦⣾⠄⠄⠄⠄⡀⠄⢀⣿⣿⠄⠄⠄⢸⡇⠄⠄\n⠄⠄⠄⣾⣿⠿⠿⠶⠿⢿⣿⣿⣿⣿⣦⣤⣄⢀⡅⢠⣾⣛⡉⠄⠄⠄⠸⢀⣿⠄\n⠄⠄⢀⡋⣡⣴⣶⣶⡀⠄⠄⠙⢿⣿⣿⣿⣿⣿⣴⣿⣿⣿⢃⣤⣄⣀⣥⣿⣿⠄\n⠄⠄⢸⣇⠻⣿⣿⣿⣧⣀⢀⣠⡌⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⠿⣿⣿⣿⠄\n⠄⢀⢸⣿⣷⣤⣤⣤⣬⣙⣛⢿⣿⣿⣿⣿⣿⣿⡿⣿⣿⡍⠄⠄⢀⣤⣄⠉⠋⣰\n⠄⣼⣖⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⢇⣿⣿⡷⠶⠶⢿⣿⣿⠇⢀⣤\n⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣽⣿⣿⣿⡇⣿⣿⣿⣿⣿⣿⣷⣶⣥⣴⣿⡗\n⢀⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠄\n⢸⣿⣦⣌⣛⣻⣿⣿⣧⠙⠛⠛⡭⠅⠒⠦⠭⣭⡻⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠄\n⠘⣿⣿⣿⣿⣿⣿⣿⣿⡆⠄⠄⠄⠄⠄⠄⠄⠄⠹⠈⢋⣽⣿⣿⣿⣿⣵⣾⠃⠄\n⠄⠘⣿⣿⣿⣿⣿⣿⣿⣿⠄\033[1;31m⣴⣿⣶⣄⠄⣴⣶⠄\033[0;0m⢀⣾⣿⣿⣿⣿⣿⣿⠃⠄⠄\n⠄⠄⠄⠄⠈⠛⢿⣿⣿⣿⠁\033[1;31m⠞⢿⣿⣿⡄⢿⣿⡇\033[0;0m⣸⣿⣿⠿⠛⠁⠄⠄⠄⠄⠄\n⠄⠄⠄⠄⠄⠄⠄⠉⠻⣿⣿⣾⣦\033[1;31m⡙⠻⣷⣾⣿⠃\033[0;0m⠿⠋⠁⠄⠄⠄⠄⠄⢀⣠⣴\n⣿⣿⣿⣶⣶⣮⣥⣒⠲⢮⣝⡿⣿⣿⡆\033[1;31m⣿⡿⠃\033[0;0m⠄⠄⠄⠄⠄⠄⠄⣠⣴⣿⣿⣿\n\n"
			@echo "\033[0;31mAll done boy!\n"
			@echo ""

%.o:		%.cpp $(HEADER)
			@$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@
			@echo "\033[35m Hacking the Pentagon servers... \033[0m"

clean:
			@rm -rf $(OBJ)
			@echo "\033[32m------> CLEAN  completed <------\033[0m"

fclean:		clean
			@rm -f $(NAME)
			@rm -f *.replace
			@echo "\033[34m------> FCLEAN completed <------\033[0m"

re:			fclean all
			@echo "\033[36m------>   RE completed   <------\033[0m"

.PHONY:		all clean fclean re