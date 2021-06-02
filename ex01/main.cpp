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

void    _test(std::string const& name_bure, int grade,
        std::string const& name_form, int sign_grade, int exec_grade) {
    try {
        std::cout << name_bure << "'s test" << std::endl;

        Bureaucrat  bure(name_bure, grade);
        Form        form(name_form, sign_grade, exec_grade);
        std::cout << bure;
        bure.signForm(&form);
        std::cout << form;
        std::cout << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << std::endl;
    }
}

int main() {
    std::cout << "<TEST FORM>" << std::endl;
    _test("Akira", 10, "test1", 100, 100);
    _test("Tetsuo", 100, "test1", 10, 10);
    _test("Kiyoko", 100, "test1", -10, 10);
    _test("Takashi", 100, "test1", 10, -10);
    _test("Masaru", 100, "test1", 10, 999);
    _test("Taisa", 100, "test1", 999, 10);
    _test("A", 999, "test1", 999, 999);
    _test("B", -999, "test1", 999, 999);
    _test("C", 100, "test1", -999, -999);
    return 0;
}
