/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 21:13:40 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/04 08:52:15 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

char const* form_name_ = "Shrubbery";
// const char* ASCIITREE = "tree";
// "              ,@@@@@@@,\n"
// "      ,,,.   ,@@@@@@8@@,  .oo8888o.\n"
// "   ,&%%&%&&%,@@@@@@@@@@@@,888888888o\n"
// "  ,%&%%&&%&&%,@@@@@@@@@@@88888888888'\n"
// "  %&&%&%&/%&&%@@@@@@ @@@@88888888888'\n"
// "  %&&%% %&%%&&@@@ V @@@' `8888 `888'\n"
// "  `&%  `  %&'    |.|         |'|8'\n"
// "      |o|        | |         | |\n"
// "      |.|        | |         | |\n";

ShrubberyCreationForm::ShrubberyCreationForm()
    : Form(this->getFromName(), this->getSignGrade(), this->getExecGrade()) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
    : Form(this->getFromName(),
           this->getSignGrade(),
           this->getExecGrade(),
           target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src)
    : Form(src) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm&
ShrubberyCreationForm::operator=(ShrubberyCreationForm const& right) {
    Form::operator=(right);
    return (*this);
}

void    ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
    Form::execute(executor);

    std::string const&  filename(std::string(this->getTarget()) + std::string("_shrubbery"));
    std::ofstream   out(filename);
    if (out) {
        std::string const tree = ""
            "              ,@@@@@@@,\n"
            "      ,,,.   ,@@@@@@8@@,  .oo8888o.\n"
            "   ,&%%&%&&%,@@@@@@@@@@@@,888888888o\n"
            "  ,%&%%&&%&&%,@@@@@@@@@@@88888888888'\n"
            "  %&&%&%&/%&&%@@@@@@ @@@@88888888888'\n"
            "  %&&%% %&%%&&@@@ V @@@' `8888 `888'\n"
            "  `&%  `  %&'    |.|         |'|8'\n"
            "      |o|        | |         | |\n"
            "      |.|        | |         | |\n";
        out << std::string(tree);
    } else {
        std::cerr << "Error: " << filename << " could not be opend" << std::endl;
    }
}

char const*   ShrubberyCreationForm::getFromName() const {
    return (this->form_name_);
}

int ShrubberyCreationForm::getSignGrade() const {
    return (this->sign_grade_);
}

int ShrubberyCreationForm::getExecGrade() const {
    return (this->exec_grade_);
}
