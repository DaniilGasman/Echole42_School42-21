#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define PINK		"\033[35m"

class	Zombie
{

public:
	Zombie( std::string name );
	~Zombie( void );

	std::string get_name( void ) const;

	void		announce( void ) const;

private:

	void		prefix( void ) const;

	std::string name;
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif