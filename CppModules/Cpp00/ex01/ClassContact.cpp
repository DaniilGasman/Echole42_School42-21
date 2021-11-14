#include "phonebook.h"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void	Contact::setIndex(int i)
{
	this->_index = i;
}

void 	Contact::setFirstName(void)
{
	std::cout << PINK << "Oh! Enter first name: " << RESET;
	std::cin >> _firstName;
}

void 	Contact::setLastName(void)
{
	std::cout << PINK << "Enter last name: " << RESET;
	std::cin >> _lastName;
}

void 	Contact::setNickname(void)
{
	std::cout << PINK << "Enter nickname: " << RESET;
	std::cin >> _nickname;
}

void 	Contact::setTelephone(void)
{
	std::cout << PINK << "Enter telephone number: " << RESET;
	std::cin >> _telephone;
}

void 	Contact::setSecret(void)
{
	std::cout << PINK << "I will call you, now... Enter your secret: " << RESET;
	std::cin >> _secret;
}

int		Contact::get_index(void)
{
	return (this->_index);
}

std::string	Contact::get_first_name(void)
{
	return (this->_firstName);
}

std::string	Contact::get_last_name(void)
{
	return (this->_lastName);
}

std::string	Contact::get_nickname(void)
{
	return (this->_nickname);
}

std::string	Contact::get_telephone(void)
{
	return (this->_telephone);
}

std::string	Contact::get_secret(void)
{
	return (this->_secret);
}
