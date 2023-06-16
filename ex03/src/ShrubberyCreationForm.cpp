/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <tedelin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:00:01 by tedelin           #+#    #+#             */
/*   Updated: 2023/06/16 17:51:55 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137, "") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& cpy) : AForm(cpy) {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	AForm::operator=(rhs);
	return (*this);
}

void	ShrubberyCreationForm::action() const
{
	std::ofstream ofs((getTarget() + "_shrubbery").c_str());
	if (ofs.fail()) {
		std::cout << "Error Shrubbery: could not open file" << std::endl;
		return ;
	}
    ofs << "      /\\\n     /\\*\\\n    /\\O\\*\\\n   /*/\\/\\/\\\n  /\\O\\/\\*\\/\\\n /\\*\\/\\*\\/\\/\\\n/\\O\\/\\/*/\\/O/\\\n      ||\n      ||\n      ||\n";
    ofs.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {} 