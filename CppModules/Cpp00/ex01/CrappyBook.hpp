#ifndef CRAPPYBOOK_H
# define CRAPPYBOOK_H

class PhoneBook
{

private:
	Contact 	contacts[8];
	static int	i;
	static int	full;

public:
	PhoneBook(void);
	~PhoneBook(void);

	void	addNewContact(void);
	Contact	*searchNewContact(int n);
	void	printColumn(std::string str);
	void	printBook(void);

};

#endif
