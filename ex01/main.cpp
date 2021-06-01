/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 00:09:04 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/01 21:36:02 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"

void    _test(std::string const& name_bure, int grade_bure,
        std::string const& name_form, int grade_sign, int grade_exec) {
    try {
        Bureaucrat  bure(name_bure, grade_bure);
        Form        form(name_form, grade_sign, grade_exec);
        std::cout << bure;
        bure.signForm(&form);
        std::cout << form;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "<TEST FORM>" << std::endl;
    _test("Akira", 10, "test1", 100, 100);
    std::cout << std::endl;
    _test("Tetsuo", 100, "test1", 10, 10);
    std::cout << std::endl;
    _test("Kiyoko", 100, "test1", -10, 10);
    std::cout << std::endl;
    _test("Takashi", 100, "test1", 10, -10);
    std::cout << std::endl;
    _test("Masaru", 100, "test1", 10, 999);
    std::cout << std::endl;
    _test("Taisa", 100, "test1", 999, 10);
    std::cout << std::endl;
    _test("A", 999, "test1", 999, 999);
    std::cout << std::endl;
    _test("B", -999, "test1", 999, 999);
    std::cout << std::endl;
    _test("C", 100, "test1", -999, -999);
    std::cout << std::endl;
    return (0);
}
