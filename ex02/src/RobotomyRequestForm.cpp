/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <tedelin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:59:55 by tedelin           #+#    #+#             */
/*   Updated: 2023/06/16 13:56:45 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45, "") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& cpy) : AForm(cpy) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
    AForm::operator=(rhs);
    return (*this);
}

void	RobotomyRequestForm::action() const
{
	static int nb = 0;
    if (nb == 0) {
        std::cout << getTarget() << " has been robotomized successfully." << std::endl;
		nb = 1;	
	}
    else {
        std::cout << getTarget() << " has not been robotomized." << std::endl;
		nb = 0;
	}
}

RobotomyRequestForm::~RobotomyRequestForm() {}