#include "Contact.hpp"

Contact::Contact() { this->_darkestSecret = this->_firstName = this->_lastName = this->_nickname = this->_phoneNumber = ""; }

Contact::~Contact(){}

void	Contact::setFirstName(std::string firstName) { this->_firstName = firstName; }

void	Contact::setLastName(std::string lastName) { this->_lastName = lastName; }

void	Contact::setNickname(std::string nickName) { this->_nickname = nickName; }

void	Contact::setPhoneNumber(std::string phoneNumber) { this->_phoneNumber = phoneNumber; }

void	Contact::setDarkestSecret(std::string darkestSecret) { this->_darkestSecret = darkestSecret; }

std::string	Contact::getFirstName(void) const { return (this->_firstName); }

std::string	Contact::getLastName(void) const { return (this->_lastName); }

std::string	Contact::getNickname(void) const { return (this->_nickname); }

std::string	Contact::getPhoneNumber(void) const { return (this->_phoneNumber); }

std::string	Contact::getDarkestSecret(void) const { return (this->_darkestSecret); }
