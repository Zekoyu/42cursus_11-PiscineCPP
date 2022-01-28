#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
	Contact	_contacts[8];
	int		_contactsIndex;
	void	_displayContact(int contactIndex) const;
public:
	PhoneBook(/* args */);
	~PhoneBook();
	void		addContact(Contact contact);
	void		displayContacts(void) const;
	void		displayFullContact(int index) const;
};

#endif