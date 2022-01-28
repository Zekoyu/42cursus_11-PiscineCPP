#include "PhoneBook.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

int main()
{
	PhoneBook	phonebook;
	std::string	input;
	while (1)
	{
		std::cout << "Phonebook:";
		std::getline(std::cin, input);
		if (input == "EXIT")
		{
			return (0);
		}
		else if (input == "ADD")
		{
			Contact contact;
	
			std::cout << "Contact first name: ";
			std::getline(std::cin, input);
			contact.setFirstName(input);

			std::cout << "Contact last name: ";
			std::getline(std::cin, input);
			contact.setLastName(input);

			std::cout << "Contact nickame: ";
			std::getline(std::cin, input);
			contact.setNickname(input);

			std::cout << "Contact phone number: ";
			std::getline(std::cin, input);
			contact.setPhoneNumber(input);

			std::cout << "Contact darkest secret: ";
			std::getline(std::cin, input);
			contact.setDarkestSecret(input);

			phonebook.addContact(contact);
		}
		else if (input == "SEARCH")
		{
			phonebook.displayContacts();

			std::cout << "Select an index: ";
			std::getline(std::cin, input);

			int selectedIndex = 0;
			
			std::stringstream stream(input);
			stream >> selectedIndex;

			if (selectedIndex < 1 || selectedIndex > 8)
				std::cout << "Please enter a number between 1 and 8" << std::endl;
			else
				phonebook.displayFullContact(selectedIndex);
		}
	}
}