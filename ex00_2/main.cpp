/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 00:09:04 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/01 02:07:05 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"

void    _test(std::string const& name, int grade) {
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

int main() {
    _test("Akira", 100);
    std::cout << std::endl;

    _test("Tetsuo", 1);
    std::cout << std::endl;

    _test("Kiyoko", 150);
    std::cout << std::endl;

    _test("Takashi", 1000);
    std::cout << std::endl;

    _test("Masaru", -100);
    std::cout << std::endl;

    _test("Taisa", 0);
    std::cout << std::endl;
    return (0);
}
