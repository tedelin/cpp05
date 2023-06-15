/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <tedelin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:00:01 by tedelin           #+#    #+#             */
/*   Updated: 2023/06/08 12:19:32 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string& target) : AForm("ShrubberyCreationForm", 145, 137)
{
    std::ofstream ofs(target + "_shrubbery");
    ofs << "      /\\\n     /\\*\\\n    /\\O\\*\\\n   /*/\\/\\/\\\n  /\\O\\/\\*\\/\\\n /\\*\\/\\*\\/\\/\\\n/\\O\\/\\/*/\\/O/\\\n      ||\n      ||\n      ||\n";
    ofs.close();
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& cpy) : AForm(cpy) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
    AForm::operator=(rhs);
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {} 