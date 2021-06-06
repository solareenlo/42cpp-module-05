/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 04:19:04 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/06 04:53:53 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

char const* PresidentialPardonForm::form_name_ = "Presidential";

PresidentialPardonForm::PresidentialPardonForm()
    : Form(this->form_name_, this->sign_grade_, this->exec_grade_) {}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
    : Form(this->form_name_, this->sign_grade_, this->exec_grade_, target) {
}

PresidentialPardonForm::PresidentialPardonForm
(PresidentialPardonForm const& src) : Form(src) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm&
PresidentialPardonForm::operator=(PresidentialPardonForm const& right) {
    Form::operator=(right);
    return (*this);
}

void    PresidentialPardonForm::execute(Bureaucrat const& executer) const {
    Form::execute(executer);
    std::cout << this->getName() << " has been pardoned by Zafod Beeblebrox"
        << std::endl;
}
