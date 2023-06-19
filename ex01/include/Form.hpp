/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <tedelin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:53:09 by tedelin           #+#    #+#             */
/*   Updated: 2023/06/19 10:35:49 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"
# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat;

class Form
{
    public:
        Form(const std::string& name, int gradeSign, int gradeExec);
        Form(const Form& cpy);
        Form();
        ~Form();
        Form& operator=(const Form& rhs);

        const std::string& getName() const;
        bool isSigned() const;
        int getGradeSign() const;
        int getGradeExec() const;
        void beSigned(const Bureaucrat& b);

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

    private:
        const std::string _name;
        bool _signed;
        const int _gradeSign;
        const int _gradeExec;
};

std::ostream&   operator<<(std::ostream& o, const Form& rhs);

#endif