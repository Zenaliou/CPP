#include "contact.hpp"

Contact::Contact(){
}

Contact::~Contact(){
}

void	Contact::setName(std::string name)
{
	this->name = name;
}

void	Contact::setLast(std::string last)
{
	this->last = last;
}

void	Contact::setNick(std::string nick)
{
	this->nick = nick;
}

void	Contact::setPhone(std::string phone)
{
	this->phone = phone;
}

void	Contact::setSecret(std::string secret)
{
	this->secret = secret;
}

std::string	Contact::getName() const
{
	return (this->name);
}

std::string	Contact::getLast() const
{
	return (this->last);
}

std::string	Contact::getNick() const
{
	return (this->nick);
}

std::string	Contact::getPhone() const
{
	return (this->phone);
}

std::string	Contact::getSecret() const
{
	return (this->secret);
}
