/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureauCrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <tedelin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:54:29 by tedelin           #+#    #+#             */
/*   Updated: 2023/06/15 13:56:22 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include "Form.hpp"
# include <string>
# include <iostream>
# include <stdexcept>

class Form;

class BureauCrat
{
    public:
        BureauCrat(std::string const & name, int grade);
        BureauCrat(const BureauCrat& cpy);
        ~BureauCrat();
        BureauCrat & operator=(const BureauCrat& rhs);

        const std::string& getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(Form& f);
        
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        
    private:
        const std::string _name;
        int _grade;
};

std::ostream&   operator<<(std::ostream& o, const BureauCrat& rhs);

#endif