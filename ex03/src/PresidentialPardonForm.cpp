/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <tedelin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:34:13 by tedelin           #+#    #+#             */
/*   Updated: 2023/06/16 13:55:44 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5, "") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5, target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& cpy) : AForm(cpy) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
    AForm::operator=(rhs);
    return (*this);
}

void	PresidentialPardonForm::action() const
{
	std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {}