#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <string>
# include <iomanip>
# include "ClassContact.hpp"
# include "CrappyBook.hpp"
# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define PINK		"\033[35m"

int		main(void);
void	printResult(Contact *contact);
int		dataSearch(void);
Contact	dataAdd(void);

#endif
