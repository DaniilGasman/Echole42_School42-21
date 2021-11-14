#include "phonebook.h"

int	PhoneBook::i = 0;
int	PhoneBook::full = 0;

PhoneBook::PhoneBook(void)
{
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::addNewContact(void)
{
	contacts[i].setIndex(i + 1);
	contacts[i].setFirstName();
	contacts[i].setLastName();
	contacts[i].setNickname();
	contacts[i].setTelephone();
	contacts[i].setSecret();
	i++;
	if (i == 8)
	{
		full = 1;
		i = 0;
	}
}

Contact	*PhoneBook::searchNewContact(int n)
{
	if ((n < 1 || n > 8) || (n > i && !full))
		return (NULL);
	return (&contacts[n - 1]);
}

void	PhoneBook::printColumn(std::string str)
{
	int	len = str.length();
	if (len > 10)
	{
		std::string copy = str;
		copy.resize(9);
		std::cout << copy << '.';
	}
	else if (len < 10)
	{
		while (len++ < 10)
			std::cout << ' ';
		std::cout << str;
	}
	else
		std::cout << str;

	std::cout << "|";
}

void	PhoneBook::printBook(void)
{
	int n = 0;
	std::string	copy;

	std::cout << "|===========================================|" << std::endl;
	std::cout << "|   index  |first name| last name| nickname |" << std::endl;
	std::cout << "|===========================================|" << std::endl;
	while (n < ((full) ? 8 : i))
	{
		std::cout << "|         " << contacts[n].get_index() << '|';
		printColumn(contacts[n].get_first_name());
		printColumn(contacts[n].get_last_name());
		printColumn(contacts[n].get_nickname());
		std::cout << std::endl;
		n++;
	}
	std::cout << "|___________________________________________|" << std::endl;
}
