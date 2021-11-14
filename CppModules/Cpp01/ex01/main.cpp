#include <iostream>
#include "Zombie.hpp"

void	announceAllZombies( Zombie *zombieHorde, size_t N)
{
	for (size_t i = 0; i < N; i++)
	{
		zombieHorde[i].announce();
	}
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	znak;
	int	kostil = 0;

	i = 1;
	nbr = -1;
	znak = 0;
	while (str[i])
	{
		if(ft_isdigit(str[i]))
			kostil++;
		else
			kostil = -2147483647;
		i++;
	}
	i = 0; 
	if (kostil >= 0)
	{
		nbr = 0;
		while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
				|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
			i++;
		if (str[i] != '\0' && str[i] == '-')
		{
			znak = 1;
		i++;
		}
		else if (str[i] == '+')
			i++;
		while (str[i] != '\0' && ft_isdigit(str[i]))
			nbr = (nbr * 10) + (str[i++] - '0');
		if (znak == 1)
			return (-nbr);
	}
	return (nbr);
}

int	main(int ac, char **av)
{
	int	n;

	if(ac == 2)
	{
		n = ft_atoi(av[1]);
		if (n > 0)
		{
			std::cout << YELLOW << "Creating a bunch of zombies"
				" named Vladimir" << RESET << std::endl;
			{
				Zombie *firstZombieHorde = zombieHorde(n, "Vladimir");
				announceAllZombies(firstZombieHorde, n);
				delete [] firstZombieHorde;
			}
		}
		if(n == 0)
		{
			std::cout << PINK << "You requested 0 zombies."
			" Here, get it." << RESET << std::endl;
		}
		if(n < 0)
			std::cout << PINK << "How do you imagine it?" << RESET << std::endl;
	}
	else
	{
		std::cout << PINK << "I will only work with one"
			" integer argument" << RESET << std::endl;
	}
}
