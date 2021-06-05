/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 21:13:40 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/06 04:50:35 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

char const* ShrubberyCreationForm::form_name_ = "Shrubbery";
char const* ShrubberyCreationForm::ascii_tree_ = ""
            "              ,@@@@@@@,\n"
            "      ,,,.   ,@@@@@@@@@,  .oo8888o.\n"
            "   ,&&&&&&&&,@@@@@@@@@@@@,888888888o\n"
            "  ,&&&&&&&&&&,@@@@@@@@@@@88888888888'\n"
            "  &&&&&&&&&&&&@@@@@@@@@@@88888888888'\n"
            "  &&&&& &&&&&&@@@ @ @@@' `8888 `888'\n"
            "  `&&  `  &&'    |.|         |'|8'\n"
            "      |.|        |.|         |'|\n"
            "      |.|        |.|         |'|\n";

ShrubberyCreationForm::ShrubberyCreationForm()
    : Form(this->form_name_, this->sign_grade_, this->exec_grade_) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
    : Form(this->form_name_, this->sign_grade_, this->exec_grade_, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src)
    : Form(src) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm&
ShrubberyCreationForm::operator=(ShrubberyCreationForm const& right) {
    Form::operator=(right);
    return (*this);
}

void    ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
    Form::execute(executor);

    std::string const&
        filename(std::string(this->getTarget()) + std::string("_shrubbery"));
    std::ofstream   out(filename);
    if (out)
        out << std::string(this->getAsciiTree());
    else
        std::cerr << "Error: " << filename
            << " could not be opend" << std::endl;
}

char const* ShrubberyCreationForm::getAsciiTree() const {
    return (this->ascii_tree_);
}
