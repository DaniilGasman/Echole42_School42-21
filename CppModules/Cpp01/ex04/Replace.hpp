#ifndef SED_HPP
# define SED_HPP

# include <fstream>

class CppSed
{

public:

	CppSed( void );
	~CppSed( void );

	bool	setFile( std::string newFile );

	bool	replace( std::string stringToReplace, std::string replacement );
	void	outputToFile( std::string fileContent );

private:

	std::string		stringToReplace;
	std::string		replacement;
	std::string		fileName;
	std::ifstream	inputFileStream;

};

#endif
