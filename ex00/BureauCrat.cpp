/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <tedelin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:57:02 by tedelin           #+#    #+#             */
/*   Updated: 2023/06/06 10:16:27 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BureauCrat.hpp"

BureauCrat::BureauCrat(std::string const & name, int _grade) : _name(name)
{
    if (_grade < 1)
        throw GradeTooHighException();
    else if (_grade > 150)
        throw GradeTooLowException();
    else
        this->_grade = _grade;
}

BureauCrat::BureauCrat(const BureauCrat& cpy) : _name(cpy.getName()), _grade(cpy.getGrade()) {}

BureauCrat& BureauCrat::operator=(const BureauCrat& rhs)
{
    if (this != &rhs) {
        this->_grade = rhs.getGrade();
    }
    return (*this);
}

int BureauCrat::getGrade(void) const 
{
    return (this->_grade);
}

const std::string&  BureauCrat::getName() const 
{
    return (this->_name);
}

void    BureauCrat::incrementGrade()
{
    if (this->_grade == 1)
        throw GradeTooHighException();
    else
        this->_grade--;
}

void    BureauCrat::decrementGrade()
{
    if (this->_grade == 150)
        throw GradeTooLowException();
    else
        this->_grade++;
}

std::ostream&   operator<<(std::ostream& o, const BureauCrat& rhs)
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return (o);
}

BureauCrat::~BureauCrat() {}

const char* BureauCrat::GradeTooHighException::what() const throw()
{
    return ("Error: Grade too high");
}

const char* BureauCrat::GradeTooLowException::what() const throw()
{
    return ("Error: Grade too low");
}