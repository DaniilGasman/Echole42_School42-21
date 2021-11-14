#ifndef CLASSCONTACT_H
# define CLASSCONTACT_H

class Contact
{

private:
	int			_index;
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_telephone;
	std::string	_secret;

public:
	Contact( void );
	~Contact( void );

	void	setIndex(int i);
	void	setFirstName(void);
	void	setLastName(void);
	void	setNickname(void);
	void	setTelephone(void);
	void	setSecret(void);

	int		get_index(void);
	std::string	get_first_name(void);
	std::string	get_last_name(void);
	std::string	get_nickname(void);
	std::string	get_telephone(void);
	std::string	get_secret(void);
};

#endif
