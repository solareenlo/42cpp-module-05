/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 08:28:06 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/02 08:31:46 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

void    _test(std::string const& name, int grade) {
    try {
        Bureaucrat  bure(name, grade);
        std::cout << bure;

        bure.incrementGrade();
        std::cout << bure;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

int main() {
    _test("Akira", 100);
    return 0;
}
