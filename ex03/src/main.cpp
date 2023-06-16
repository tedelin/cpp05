/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <tedelin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:34:38 by tedelin           #+#    #+#             */
/*   Updated: 2023/06/16 16:56:31 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BureauCrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try {
		Intern someRandomIntern;
		BureauCrat b("Bender", 1);
		AForm* rrf;
		AForm* ppf;
		AForm* scf;
		
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
		scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		
		b.signForm(*rrf);
		b.signForm(*ppf);
		b.signForm(*scf);
		b.executeForm(*scf);
		b.executeForm(*ppf);
		b.executeForm(*rrf);
		
		delete rrf;
		delete ppf;
		delete scf;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("inexistant form", "Bender");	
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}