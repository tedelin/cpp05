/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <tedelin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:53:09 by tedelin           #+#    #+#             */
/*   Updated: 2023/06/16 13:55:18 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include "BureauCrat.hpp"
# include <string>
# include <iostream>
# include <stdexcept>

class BureauCrat;

class AForm
{
    public:
        AForm(const std::string& name, int gradeSign, int gradeExec, const std::string& target);
        AForm(const AForm& cpy);
        ~AForm();
        AForm& operator=(const AForm& rhs);

        const std::string& getName() const;
        bool isSigned() const;
        int getGradeSign() const;
        int getGradeExec() const;
		const std::string& getTarget() const;
        void beSigned(const BureauCrat& b);
		void execute(BureauCrat const& executor);

		virtual void	action() const = 0;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
		 class NotSignedException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

    private:
        AForm();
        const std::string _name;
        bool _signed;
        const int _gradeSign;
        const int _gradeExec;
		const std::string _target;
};

std::ostream&   operator<<(std::ostream& o, const AForm& rhs);

#endif