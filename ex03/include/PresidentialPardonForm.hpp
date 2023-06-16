/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <tedelin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:35:19 by tedelin           #+#    #+#             */
/*   Updated: 2023/06/16 13:55:24 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& cpy);
        ~PresidentialPardonForm();
        PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);

		void	action() const;

    private:
        PresidentialPardonForm();
};

#endif