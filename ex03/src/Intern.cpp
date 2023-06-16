/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <tedelin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:59:07 by tedelin           #+#    #+#             */
/*   Updated: 2023/06/16 17:03:01 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& cpy) {(void) cpy;}

Intern& Intern::operator=(const Intern& rhs)
{
	(void) rhs;
    return (*this);
}

AForm* Intern::make_robotomy(const std::string& target) const
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::make_president(const std::string& target) const
{
	return (new PresidentialPardonForm(target));
}


AForm* Intern::make_shrubbery(const std::string& target) const
{
	return (new ShrubberyCreationForm(target));
}


typedef AForm* (Intern::*func_ptr)(const std::string&) const;

AForm*	Intern::makeForm(const std::string& form, const std::string& target) const
{
	std::string	forms[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	func_ptr	funcs[3] = {&Intern::make_robotomy, &Intern::make_president, &Intern::make_shrubbery};
	
	for (int i = 0; i < 3; i++)
	{
		if (form == forms[i]) {
			std::cout << "Intern creates " << form << std::endl;
			return ((this->*funcs[i])(target));
		}
	}
	throw Intern::InvalidFormException();
}

const char* Intern::InvalidFormException::what() const throw()
{
    return ("Form doesn't exist.");
}

Intern::~Intern() {}