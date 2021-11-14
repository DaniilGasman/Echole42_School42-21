#ifndef KAREN_HPP
# define KAREN_HPP

# include <string>
# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define PINK		"\033[35m"

class Karen
{

public:

	enum filterLevel {
		levelError = 0,
		levelWarning,
		levelInfo,
		levelDebug,
		levelInsignificant = -1
	};

	Karen( void );
	Karen( const std::string &filterLevel );
	Karen( filterLevel filterLevel );
	~Karen( void );

	void complain( const std::string &level );
	void complain( filterLevel level );

	filterLevel	getLevel( void ) const;
	bool		setLevel( const filterLevel &newLevel );

private:

	void	defaultMessage( void );
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );

	filterLevel _level;

	filterLevel	getLevelFromString( std::string level );

};

#endif
