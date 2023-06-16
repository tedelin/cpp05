/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <tedelin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:59:20 by tedelin           #+#    #+#             */
/*   Updated: 2023/06/16 16:49:52 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include <string>
#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern& cpy);
		Intern&	operator=(const Intern& rhs);
		
		AForm* make_shrubbery(const std::string& target) const;
		AForm* make_president(const std::string& target) const;
		AForm* make_robotomy(const std::string& target) const;
		AForm*	makeForm(const std::string& form, const std::string& target) const;

		class InvalidFormException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};


#endif