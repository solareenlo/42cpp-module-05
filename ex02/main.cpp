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

void    _test_shrubbery(std::string const& name_bure,
        int grade,
        std::string const& target) {
    try {
        std::cout << name_bure << "'s test" << std::endl;

        Bureaucrat  bure(name_bure, grade);
        ShrubberyCreationForm   form(target);

        form.beSigned(bure);
        std::cout << form;
        form.execute(bure);
        std::cout << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << std::endl;
    }
}

int main() {
    std::cout << "<SHURUBBERY TESTS>" << std::endl;
    _test_shrubbery("Akira", 10, "test1");
    _test_shrubbery("Tetsuo", 140, "test2");
    _test_shrubbery("Kiyoko", 150, "test3");
    _test_shrubbery("A", 999, "test4");
    _test_shrubbery("B", -999, "test5");
    return 0;
}
