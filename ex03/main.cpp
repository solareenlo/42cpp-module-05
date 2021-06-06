/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 08:28:06 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/06 11:16:34 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void    _test_intern(std::string const& name, std::string const& target) {
    Intern      someRandomIntern;
    Form*       rrf;
    Bureaucrat  bure("Akira", 1);

    rrf = someRandomIntern.makeForm(name, target);

    if (rrf) {
        std::cout << bure;
        bure.signForm(rrf);
        std::cout << *rrf;
        std::cout << std::endl;
    }
}

int main() {
    std::cout << "<SHURUBBERY TESTS>" << std::endl;
    _test_intern("shrubbery creation", "Bender");
    _test_intern("robotomy request", "Bender");
    _test_intern("presidential pardon", "Bender");
    _test_intern("nothing form", "Bender");
    return 0;
}
