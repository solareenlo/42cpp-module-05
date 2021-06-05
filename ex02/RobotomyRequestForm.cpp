/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 02:32:14 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/06 04:13:16 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

char const* RobotomyRequestForm::form_name_ = "Robotomy";

RobotomyRequestForm::RobotomyRequestForm() : Form() {}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
    : Form(this->form_name_, this->sign_grade_, this->exec_grade_, target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src)
    : Form(src) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&
RobotomyRequestForm::operator=(RobotomyRequestForm const& right) {
    Form::operator=(right);
    return (*this);
}

void    RobotomyRequestForm::execute(Bureaucrat const& executer) const {
    Form::execute(executer);
    std::cout << "Dori dori dori dori ..." << std::endl;
    unsigned int seed = time(NULL);
    if (rand_r(&seed) % 2) {
        std::cout << "The robotization of " << this->getName()
            << " has been successfully completed." << std::endl;
    } else {
        std::cout << "The robotization of " << this->getName()
            << " has failed..." << std::endl;
    }
}
