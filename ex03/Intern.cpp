/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 05:53:27 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/06 10:48:07 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(Intern const& src) { (void)src; }
Intern::~Intern() {}
Intern& Intern::operator=(Intern const& right) { (void)right; return (*this); }

Intern::makeFormType_ const Intern::makeFormTypeList_[] = {
    {"shrubbery creation",  &Intern::makeShrubberyCreationForm_},
    {"presidential pardon", &Intern::makePresidentialPardonForm_},
    {"robotomy request",    &Intern::makeRobotomyRequestForm_},
};

Form*   Intern::makeShrubberyCreationForm_(std::string const& target) {
    return (new ShrubberyCreationForm(target));
}

Form*   Intern::makeRobotomyRequestForm_(std::string const& target) {
    return (new RobotomyRequestForm(target));
}

Form*   Intern::makePresidentialPardonForm_(std::string const& target) {
    return (new PresidentialPardonForm(target));
}

Form*
Intern::makeForm(std::string const& name, std::string const& target) {
    const int   n = sizeof(Intern::makeFormTypeList_)
        / sizeof(Intern::makeFormType_);
    for (int i = 0; i < n; i++) {
        if (name == this->makeFormTypeList_[i].name) {
            Form*   form = (this->*(makeFormTypeList_[i].func))(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return (form);
        }
    }
    std::cout << "Intern cannot create " << name << std::endl;
    return (NULL);
}
