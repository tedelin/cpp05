/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <tedelin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:34:38 by tedelin           #+#    #+#             */
/*   Updated: 2023/06/18 10:49:35 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BureauCrat.hpp"

int main()
{
    try {
        BureauCrat b("Ted", 1);
        BureauCrat b2("John", 150);
        std::cout << b << std::endl;
        std::cout << b2 << std::endl;
        for (int i = 0; i < 149; i++) {
            b2.incrementGrade();
        }
        std::cout << b2 << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
        b.incrementGrade();
		b.incrementGrade();
    }
    catch(const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        BureauCrat b("toLow", 151);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
     try {
        BureauCrat b("toHigh", 0);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}