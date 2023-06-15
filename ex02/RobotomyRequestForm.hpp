/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <tedelin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:35:37 by tedelin           #+#    #+#             */
/*   Updated: 2023/06/08 12:16:56 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"
# include <stdlib.h>

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& cpy);
        ~RobotomyRequestForm();
        RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);

    private:
        RobotomyRequestForm();
};

#endif