/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 09:36:24 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/02 10:47:08 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
    : name_("Test"),
      sign_grade_(this->getLowestGrade_()),
      exec_grade_(this->getLowestGrade_()),
      signed_(false) {
    this->checkGrade(this->getSignGrade());
    this->checkGrade(this->getExecGrade());
}

Form::Form(std::string const& name, int const sign_grade, int const exec_grade)
    : name_(name),
      sign_grade_(sign_grade),
      exec_grade_(exec_grade),
      signed_(false) {
    this->checkGrade(this->getSignGrade());
    this->checkGrade(this->getExecGrade());
}

Form::Form(Form const& src)
    : name_(src.getName()),
      sign_grade_(src.getSignGrade()),
      exec_grade_(src.getExecGrade()) {
    this->operator=(src);
}

Form::~Form() {}

Form&   Form::operator=(Form const& right) {
    if (this != &right)
        this->signed_ = right.getSigned();
    return (*this);
}

std::string const&  Form::getName() const { return (this->name_); }
int     Form::getSignGrade() const { return (this->sign_grade_); }
int     Form::getExecGrade() const { return (this->exec_grade_); }
bool    Form::getSigned() const { return (this->signed_); }
int     Form::getHighestGrade_() const { return (this->highest_grade_); }
int     Form::getLowestGrade_() const { return (this->lowest_grade_); }
void    Form::setSigned(bool sign) { this->signed_ = sign; }

void    Form::checkGrade(int grade) {
    if (grade > this->getLowestGrade_())
        throw Form::GradeTooLowException();
    if (grade < this->getHighestGrade_())
        throw Form::GradeTooHighException();
}

void    Form::beSigned(Bureaucrat const& bure) {
    if (bure.getGrade() > this->sign_grade_)
        throw Form::GradeTooLowException();
    this->setSigned(true);
}

Form::GradeTooHighException::GradeTooHighException() : std::exception() {}
Form::GradeTooHighException::~GradeTooHighException() throw() {}

Form::GradeTooHighException::GradeTooHighException
(Form::GradeTooHighException const& src) : std::exception() {
    this->operator=(src);
}

Form::GradeTooHighException&
Form::GradeTooHighException::operator=
(Form::GradeTooHighException const& right) {
    std::exception::operator=(right);
    return (*this);
}

char const* Form::GradeTooHighException::what() const throw() {
    return ("Grade is too high for form");
}

Form::GradeTooLowException::GradeTooLowException() : std::exception() {}
Form::GradeTooLowException::~GradeTooLowException() throw() {}

Form::GradeTooLowException::GradeTooLowException
(Form::GradeTooLowException const& src) : std::exception() {
    this->operator=(src);
}

Form::GradeTooLowException&
Form::GradeTooLowException::operator=
(Form::GradeTooLowException const& right) {
    std::exception::operator=(right);
    return (*this);
}

char const* Form::GradeTooLowException::what() const throw() {
    return ("Grade is too low for form");
}

std::ostream&   operator<<(std::ostream& ostream, Form const& right) {
    ostream << right.getName() << " ";
    ostream << (right.getSigned() ? "" : "not ");
    ostream << "signed" << std::endl;
    return (ostream);
}
