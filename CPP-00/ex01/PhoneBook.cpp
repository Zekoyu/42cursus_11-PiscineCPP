#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook()
{
	this->_contactsIndex = 0;
}

PhoneBook::~PhoneBook()
{

}

void PhoneBook::addContact(Contact contact)
{
	this->_contacts[this->_contactsIndex].setDarkestSecret(contact.getDarkestSecret());
	this->_contacts[this->_contactsIndex].setFirstName(contact.getFirstName());
	this->_contacts[this->_contactsIndex].setLastName(contact.getLastName());
	this->_contacts[this->_contactsIndex].setNickname(contact.getNickname());
	this->_contacts[this->_contactsIndex].setPhoneNumber(contact.getPhoneNumber());
	this->_contactsIndex++;
	if (this->_contactsIndex >= 8)
		this->_contactsIndex = 0;
}

static void	printTruncatedString(std::string str, size_t size)
{
	if (str.length() > size)
	{
		str.resize(size);
		str[size - 1] = '.';
	}
	std::cout << std::setw(size) << str;
}

static void	displayHeader(void)
{
	std::cout << std::setw(11) << "index|";
	std::cout << std::setw(11) << "first name|";
	std::cout << std::setw(11) << "last name|";
	std::cout << std::setw(11) << "nickname|";
	std::cout << std::endl;
	std::cout << "+---------+----------+----------+----------+" << std::endl;
}

static void	displayFooter(void)
{
	std::cout << "+---------+----------+----------+----------+" << std::endl;
}

void	PhoneBook::_displayContact(int contactIndex) const
{
	std::cout << std::setw(10) << contactIndex + 1 << "|";
	printTruncatedString(this->_contacts[contactIndex].getFirstName(), 10);
	std::cout << "|";
	printTruncatedString(this->_contacts[contactIndex].getLastName(), 10);
	std::cout << "|";
	printTruncatedString(this->_contacts[contactIndex].getNickname(), 10);
	std::cout << "|" << std::endl;
}

void	PhoneBook::displayContacts(void) const
{
	displayHeader();
	for (int i = 0; i < 8; i++)
	{
		if (this->_contacts[i].getFirstName() != "")
			_displayContact(i);
	}
	displayFooter();
}

// index is "human friendly" index so need to do -1
void		PhoneBook::displayFullContact(int index) const
{
	if (index < 1 || index > 8)
		return ;
	else if (this->_contacts[index - 1].getFirstName() == "")
		std::cout << "Please choose a valid contact" << std::endl;
	else
	{
		Contact c = this->_contacts[index - 1];
	
		std::cout << c.getFirstName() << " " << c.getLastName() << " (aka. " << c.getNickname() << ")" << std::endl;
		std::cout << "Phone:          " << c.getPhoneNumber() << std::endl;
		std::cout << "Darkest secret: " << c.getDarkestSecret() << std::endl;
	}
}
