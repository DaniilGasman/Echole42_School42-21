#include <iostream>
#include "Zombie.hpp"

int	main( void )
{
	std::cout << "The first Zombie rises. His name is Vladimir.I!" << YELLOW
		<< " We do it manually" << RESET << std::endl;
	{
		Zombie	vladimiri("Vladimir.I");
		vladimiri.announce();
	}
	std::cout << "The second Zombie rises. His name is Michael.S!" << YELLOW
		" We use the \"newZombie\" functoin." << RESET << std::endl;
	{
		Zombie	*michaels = newZombie("Michael.S");
		michaels->announce();

		delete michaels;
	}
	{
		std::cout << "The thid Zombie rises. His name is Vladimir.V" << YELLOW
			" We use the \"randomChump\" function." << RESET << std::endl;
		randomChump("Vladimir.V");
	}
}