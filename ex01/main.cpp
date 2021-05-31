/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 00:09:04 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/01 07:17:07 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"

void    _test_bure(std::string const& name, int grade) {
    try {
        std::cout << name << "'s test" << std::endl;
        Bureaucrat  bureaucrat(name, grade);

        std::cout << name << "'s increment test" << std::endl;
        bureaucrat.incrementGrade();
        std::cout << bureaucrat;

        std::cout << name << "'s decrement test" << std::endl;
        bureaucrat.decrementGrade();
        std::cout << bureaucrat;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void    _test_form(std::string const& name, int grade_sign, int grade_exec) {
    try {
        Form    form(name, grade_sign, grade_exec);
        std::cout << form;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

int main() {
    {
        std::cout << "<TEST BUREAUCRAT>" << std::endl;
        _test_bure("Akira", 100);
        std::cout << std::endl;

        _test_bure("Tetsuo", 1);
        std::cout << std::endl;

        _test_bure("Kiyoko", 150);
        std::cout << std::endl;

        _test_bure("Takashi", 1000);
        std::cout << std::endl;

        _test_bure("Masaru", -100);
        std::cout << std::endl;

        _test_bure("Taisa", 0);
        std::cout << std::endl;
    }
    {
        std::cout << "<TEST FORM>" << std::endl;
        _test_form("test1", 10, 10);
        _test_form("test2", 20, 10);
        _test_form("test3", 10, 20);
    }
    return (0);
}
