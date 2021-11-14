#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie( std::string name ): name(name)
{
}

Zombie::~Zombie( void )
{
	Zombie::prefix();
	std::cout << RED << "GRrrggrgr\n" << YELLOW << " He is DEAD" << RESET << std::endl;
}

void	Zombie::announce( void ) const
{
	Zombie::prefix();
	std::cout <<  "Braaaaiiiinsss...." << std::endl;
}

void	Zombie::prefix( void ) const
{
	std::cout << "<" << GREEN << this->name << RESET << "> ";
}

std::string	Zombie::get_name( void ) const
{
	return (this->name);
}
