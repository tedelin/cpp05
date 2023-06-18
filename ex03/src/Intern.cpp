/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <tedelin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:59:07 by tedelin           #+#    #+#             */
/*   Updated: 2023/06/18 11:21:42 by tedelin          ###   ########.fr       */
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

AForm*	Intern::makeForm(const std::string& form, const std::string& target) const
{
	std::string	forms[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm* (Intern::*func_ptr[3])(const std::string&) const = {&Intern::make_robotomy, &Intern::make_president, &Intern::make_shrubbery};

	for (int i = 0; i < 3; i++)
	{
		if (form == forms[i]) {
			std::cout << "Intern creates " << form << std::endl;
			return ((this->*func_ptr[i])(target));
		}
	}
	throw Intern::InvalidFormException();
}

const char* Intern::InvalidFormException::what() const throw()
{
    return ("Form doesn't exist.");
}

Intern::~Intern() {}