/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 09:36:24 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/06 03:11:33 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "Form.hpp"

char const* Form::init_name_ = "Test";

Form::Form()
    : name_(this->init_name_),
      sign_grade_(this->lowest_grade_),
      exec_grade_(this->lowest_grade_),
      signed_(false),
      target_("") {
    this->checkGrade(this->getSignGrade());
    this->checkGrade(this->getExecGrade());
}

Form::Form(std::string const& name, int const sign_grade, int const exec_grade)
    : name_(name),
      sign_grade_(sign_grade),
      exec_grade_(exec_grade),
      signed_(false),
      target_("") {
    this->checkGrade(this->getSignGrade());
    this->checkGrade(this->getExecGrade());
}

Form::Form(std::string const& name, int const sign_grade, int const exec_grade,
        std::string const& target)
    : name_(name),
      sign_grade_(sign_grade),
      exec_grade_(exec_grade),
      signed_(false),
      target_(target) {
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
std::string const&  Form::getTarget() const { return (this->target_); }
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

void    Form::execute(Bureaucrat const& executer) const {
    if (!this->getSigned())
        throw Form::NotSignedException();
    if (executer.getGrade() > this->getExecGrade())
        throw Form::GradeTooLowException();
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

Form::NotSignedException::NotSignedException() : std::exception() {}
Form::NotSignedException::~NotSignedException() throw() {}

Form::NotSignedException::NotSignedException
(Form::NotSignedException const& src) : std::exception() {
    this->operator=(src);
}

Form::NotSignedException&
Form::NotSignedException::operator=
(Form::NotSignedException const& right) {
    std::exception::operator=(right);
    return (*this);
}

char const*
Form::NotSignedException::what() const throw() {
    return("Form is not signed");
}

std::ostream&   operator<<(std::ostream& ostream, Form const& right) {
    ostream << right.getName() << " "
    << (right.getSigned() ? "" : "not ") << "signed" << std::endl;
    return (ostream);
}
