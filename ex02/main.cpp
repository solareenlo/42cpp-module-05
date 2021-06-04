/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 08:28:06 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/02 10:48:45 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

void    _test(std::string const& name_bure,
        int grade,
        std::string const& target) {
    try {
        std::cout << name_bure << "'s test" << std::endl;

        Bureaucrat  bure(name_bure, grade);
        ShrubberyCreationForm   form(target);

        form.beSigned(bure);
        std::cout << form;
        // form.execute(bure);
        // std::cout << form;
        std::cout << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << std::endl;
    }
}

int main() {
    std::cout << "<TEST FORM>" << std::endl;
    _test("Akira", 10, "test1");
    _test("Tetsuo", 140, "test2");
    _test("Kiyoko", 150, "test3");
    _test("A", 999, "test7");
    _test("B", -999, "test8");
    return 0;
}
