/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureauCrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <tedelin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:57:02 by tedelin           #+#    #+#             */
/*   Updated: 2023/06/19 10:35:49 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const & name, int _grade) : _name(name)
{
    if (_grade < 1)
        throw GradeTooHighException();
    else if (_grade > 150)
        throw GradeTooLowException();
    else
        this->_grade = _grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& cpy) : _name(cpy.getName()), _grade(cpy.getGrade()) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
    if (this != &rhs) {
        this->_grade = rhs.getGrade();
    }
    return (*this);
}

int Bureaucrat::getGrade(void) const 
{
    return (this->_grade);
}

const std::string&  Bureaucrat::getName() const 
{
    return (this->_name);
}

void    Bureaucrat::incrementGrade()
{
    if (this->_grade == 1)
        throw GradeTooHighException();
    else
        this->_grade--;
}

void    Bureaucrat::decrementGrade()
{
    if (this->_grade == 150)
        throw GradeTooLowException();
    else
        this->_grade++;
}

void    Bureaucrat::signForm(AForm& f)
{
    try {
        f.beSigned(*this);
        std::cout << getName() << " signed " << f.getName() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << getName() << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

void	Bureaucrat::executeForm(AForm const& form)
{
	if (getGrade() > form.getGradeExec())
		throw GradeTooLowException();
	if (form.isSigned() == false)
		throw AForm::NotSignedException();
	form.action();
	std::cout << getName() << " executed " << form.getName() << std::endl;
}

std::ostream&   operator<<(std::ostream& o, const Bureaucrat& rhs)
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return (o);
}

Bureaucrat::~Bureaucrat() {}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}