/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <tedelin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:34:38 by tedelin           #+#    #+#             */
/*   Updated: 2023/06/16 13:58:17 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BureauCrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try {
        BureauCrat b("Ted", 1);
        BureauCrat b2("John", 150);
		ShrubberyCreationForm f("tedelin");
        std::cout << f << std::endl;
        b2.signForm(f);
        std::cout << f << std::endl;
        b.signForm(f);
		std::cout << f << std::endl;
		b.executeForm(f);
		b.executeForm(f);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}