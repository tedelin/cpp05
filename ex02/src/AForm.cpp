/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <tedelin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:02:53 by tedelin           #+#    #+#             */
/*   Updated: 2023/06/16 13:54:00 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string& name, int gradeSign, int gradeExec, const std::string& target) : 
_name(name), 
_signed(false),
_gradeSign(gradeSign), 
_gradeExec(gradeExec),
_target(target)
{
    if (gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
    else if (gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
}

AForm::AForm() : _name(""), _signed(false), _gradeSign(150), _gradeExec(150), _target("") {}

AForm::AForm(const AForm& cpy) : _name(cpy._name), _signed(cpy._signed), _gradeSign(cpy._gradeSign), _gradeExec(cpy._gradeExec) {}

AForm& AForm::operator=(const AForm& rhs)
{
    if (this != &rhs) {
        this->_signed = rhs.isSigned();
    }
    return (*this);
}

const std::string&  AForm::getName() const
{
    return (this->_name);
}

bool AForm::isSigned() const
{
    return (this->_signed);
}

int AForm::getGradeSign() const
{
    return (this->_gradeSign);
}

int AForm::getGradeExec() const
{
    return (this->_gradeExec);
}

const std::string& AForm::getTarget() const
{
	return (this->_target);
}

void   AForm::beSigned(const BureauCrat& b)
{
    if (b.getGrade() <= this->_gradeSign)
        this->_signed = true;
    else
        throw GradeTooLowException();
}

void	AForm::execute(BureauCrat const& executor)
{
	if (executor.getGrade() > getGradeExec())
		throw GradeTooLowException();
	if (isSigned() == false)
		throw NotSignedException();
	action();
}

std::ostream&   operator<<(std::ostream& o, const AForm& rhs)
{
    o << "Form: " << rhs.getName()
    << " is " << (rhs.isSigned() ? "signed" : "not signed")
    << ", grade to sign: " << rhs.getGradeSign() 
    << ", grade to exec: " << rhs.getGradeExec();
    return (o);
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

const char* AForm::NotSignedException::what() const throw()
{
    return ("Cannot execute because form is not signed");
}

AForm::~AForm() {}