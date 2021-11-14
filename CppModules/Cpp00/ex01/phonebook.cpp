#include "phonebook.h"

void	print_greetings()
{
	std::cout << GREEN << "────╔╗─╔╗     ───────────╔══╗╔══╗╔╗─╔╗  " << RESET;
	std::cout << GREEN << "   ╔══╗╔╗──────────────╔╗──────────╔╗──\n" << RESET;
	std::cout << GREEN << "────║║─║║     ───────────║╔╗║║╔╗║║║─║║  " << RESET;
	std::cout << GREEN << "   ║╔╗║║║──────────────║║──────────║║──\n" << RESET;
	std::cout << GREEN << "╔╗╔╗║╚═╝║     ╔══╗╔═╗╔══╗║╚╝║║╚╝║║╚═╝║  " << RESET;
	std::cout << GREEN << "   ║╚╝║║╚═╗╔══╗╔═╗─╔══╗║╚═╗╔══╗╔══╗║║╔╗\n" << RESET;
	std::cout << GREEN << "║╚╝║╚═╗╔╝     ║╔═╝║╔╝║╔╗║║╔═╝║╔═╝╚═╗╔╝  " << RESET;
	std::cout << GREEN << "   ║╔═╝║╔╗║║╔╗║║╔╗╗║║═╣║╔╗║║╔╗║║╔╗║║╚╝╝\n" << RESET;
	std::cout << GREEN << "║║║║╔═╝║─     ║╚═╗║║─║╔╗║║║──║║──╔═╝║─  " << RESET;
	std::cout << GREEN << "   ║║──║║║║║╚╝║║║║║║║═╣║╚╝║║╚╝║║╚╝║║╔╗╗\n" << RESET;
	std::cout << GREEN << "╚╩╩╝╚══╝─     ╚══╝╚╝─╚╝╚╝╚╝──╚╝──╚══╝─  " << RESET;
	std::cout << GREEN << "   ╚╝──╚╝╚╝╚══╝╚╝╚╝╚══╝╚══╝╚══╝╚══╝╚╝╚╝\n" << RESET;
}

int	dataSearch(void)
{
	std::string str;
	int n;

	while (1)
	{
		std::cout << "Search: ";
		std::cin >> str;
		if (str.length() > 1 || !isdigit(str[0]))
		{
			std::cout << RED << "Wrong number. Try again" << RESET << std::endl;
			continue ;
		}
		break ;
	}
	n = str[0] - '0';
	return (n);
}

void	printResult(Contact *contact)
{
	if (contact == NULL)
	{
		std::cout << RED << "No such contact" << RESET << std::endl;
		return ;
	}
	std::cout << std::endl;
	std::cout << "=======================" << std::endl;
	std::cout << "First name: " << contact->get_first_name() << std::endl;
	std::cout << "Last name:  " << contact->get_last_name() << std::endl;
	std::cout << "Nickname:   " << contact->get_nickname() << std::endl;
	std::cout << "Telephone:  " << contact->get_telephone() << std::endl;
	std::cout << "Secret:     " << contact->get_secret() << std::endl;
	std::cout << "=======================" << std::endl;
}

int	main(void)
{
	PhoneBook	addressBook;
	std::string	command;
	int			s;

	print_greetings();
	std::cout << RED << "You can ADD contacts to the phonebook and ";
	std::cout << "SEARCH contacts in it." << RESET << std::endl;
	while (1)
	{
		std::cout << YELLOW << "Enter the command: " << RESET;
		std::cin >> command;
		if (command == "ADD")
			addressBook.addNewContact();
		else if (command == "SEARCH")
		{
			addressBook.printBook();
			s = dataSearch();
			printResult(addressBook.searchNewContact(s));
		}
		else if (command == "EXIT")
			break ;
		else
			std::cout << RED << "Wrong command" << RESET << std::endl;
	}
	return (0);
}
