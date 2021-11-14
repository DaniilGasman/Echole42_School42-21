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

	Zombie( void );
	~Zombie( void );

	void		announce( void ) const;

	std::string	get_name( void ) const;
	bool		set_name( std::string newName );

private:

	void		prefix( void ) const;

	std::string name;
};

Zombie	*zombieHorde( int N, std::string name );

#endif
