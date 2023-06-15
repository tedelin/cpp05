/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <tedelin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:53:09 by tedelin           #+#    #+#             */
/*   Updated: 2023/06/06 10:36:41 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "BureauCrat.hpp"
# include <string>
# include <iostream>
# include <stdexcept>

class BureauCrat;

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
        void beSigned(const BureauCrat& b);

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