/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <tedelin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:02:53 by tedelin           #+#    #+#             */
/*   Updated: 2023/06/15 13:56:22 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string& name, int gradeSign, int gradeExec) : 
_name(name), 
_signed(false),
_gradeSign(gradeSign), 
_gradeExec(gradeExec) 
{
    if (gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
    else if (gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
}

Form::Form() : _name(""), _signed(false), _gradeSign(150), _gradeExec(150) {}

Form::Form(const Form& cpy) : _name(cpy._name), _signed(cpy._signed), _gradeSign(cpy._gradeSign), _gradeExec(cpy._gradeExec) {}

Form& Form::operator=(const Form& rhs)
{
    if (this != &rhs) {
        this->_signed = rhs.isSigned();
    }
    return (*this);
}

const std::string&  Form::getName() const
{
    return (this->_name);
}

bool Form::isSigned() const
{
    return (this->_signed);
}

int Form::getGradeSign() const
{
    return (this->_gradeSign);
}

int Form::getGradeExec() const
{
    return (this->_gradeExec);
}

void   Form::beSigned(const BureauCrat& b)
{
    if (b.getGrade() <= this->_gradeSign)
        this->_signed = true;
    else
        throw GradeTooLowException();
}

std::ostream&   operator<<(std::ostream& o, const Form& rhs)
{
    o << "Form: " << rhs.getName()
    << " is " << (rhs.isSigned() ? "signed" : "not signed")
    << ", grade to sign: " << rhs.getGradeSign() 
    << ", grade to exec: " << rhs.getGradeExec();
    return (o);
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

Form::~Form() {}