/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <tedelin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:59:55 by tedelin           #+#    #+#             */
/*   Updated: 2023/06/08 12:17:28 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string& target) : AForm("RobotomyRequestForm", 72, 45)
{
    std::srand(std::time(0));
    int nb = std::rand() % 2;
    if (nb == 0)
        std::cout << target << " has been robotomized successfully." << std::endl;
    else
        std::cout << target << " has not been robotomized." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& cpy) : AForm(cpy) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
    AForm::operator=(rhs);
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}