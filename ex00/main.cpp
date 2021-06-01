/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 08:28:06 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/02 08:55:11 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

void    _test(std::string const& name, int grade) {
    try {
        std::cout << name << "'s test" << std::endl;

        Bureaucrat  bure(name, grade);
        std::cout << bure;

        bure.incrementGrade();
        std::cout << bure;
        bure.incrementGrade();
        std::cout << bure;

        bure.decrementGrade();
        std::cout << bure;
        bure.decrementGrade();
        std::cout << bure;
        bure.decrementGrade();
        std::cout << bure;

        std::cout << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << std::endl;
    }
}

int main() {
    _test("Kaneda", 1);
    _test("Tetsuo", 150);
    _test("Akira", 100);
    _test("Kiyoko", 150);
    _test("Takashi", -999);
    _test("Masaru", 999);
    return 0;
}
