/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 08:28:06 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/06 03:53:42 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

void    _test_shrubbery(std::string const& name_bure,
        int grade,
        std::string const& target) {
    try {
        std::cout << name_bure << "'s test" << std::endl;

        Bureaucrat              bure(name_bure, grade);
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

void    _test_robotomy(std::string const& name_bure,
        int grade,
        std::string const& target) {
    try {
        std::cout << name_bure << "'s test" << std::endl;

        Bureaucrat          bure(name_bure, grade);
        RobotomyRequestForm form(target);

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

    std::cout << "<ROBOTOMY TESTS>" << std::endl;
    _test_robotomy("Akira", 10, "test11");
    _test_robotomy("Tetsuo", 45, "test22");
    _test_robotomy("Kiyoko", 60, "test33");
    _test_robotomy("A", 999, "test44");
    _test_robotomy("B", -999, "test55");
    return 0;
}
