/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <tedelin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:34:38 by tedelin           #+#    #+#             */
/*   Updated: 2023/06/06 11:56:37 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BureauCrat.hpp"
#include "Form.hpp"

int main()
{
    try {
        BureauCrat b("Ted", 1);
        BureauCrat b2("John", 150);
        Form f("contrat", 1, 1);
        std::cout << f << std::endl;
        b2.signForm(f);
        b.signForm(f);
        std::cout << f << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}