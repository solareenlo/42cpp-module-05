/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 02:54:52 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/01 06:33:22 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() :
    name_("Test"),
    signableGrade_(this->getLowestGrade_()),
    executableGrade_(this->getLowestGrade_()) {
    this->signed_ = false;
}

Form::Form(std::string const& name, int signableGrade, int executableGrade) :
    name_(name),
    signableGrade_(signableGrade),
    executableGrade_(executableGrade) {
        this->signed_ = false;
}

Form::~Form() {
}

Form::Form(Form const& src) :
    name_(src.getName()),
    signableGrade_(src.getSignableGrade()),
    executableGrade_(src.getExecutableGrade()) {
        this->operator=(src);
}

Form&   Form::operator=(Form const& right) {
    if (this != &right)
        this->signed_ = right.isSigned();
    return (*this);
}

std::string const&  Form::getName() const {
    return (this->name_);
}

int const   Form::getSignableGrade() const {
    return (this->signableGrade_);
}

int const   Form::getExecutableGrade() const {
    return (this->executableGrade_);
}

bool    Form::isSigned() const {
    return (this->signed_);
}

void    Form::beSigned(Bureaucrat const& bureaucrat) {
    if (bureaucrat.getGrade() > this->signableGrade_)
    this->signed_ = true;
}

int const   Form::getHighestGrade_() const {
    return (this->highest_grade_);
}

int const   Form::getLowestGrade_() const {
    return (this->lowest_grade_);
}

int Form::checkGrade_(int grade) {
    if (grade > this->getLowestGrade_())
        throw Form::GradeTooLowException();
    if (grade < this->getHighestGrade_())
        throw Form::GradeTooHighException();
    return (grade);
}

Form::GradeTooHighException::GradeTooHighException() : signed_(false) {
}

Form::GradeTooHighException::GradeTooHighException(bool sign) : signed_(sign) {
}

Form::GradeTooHighException::GradeTooHighException
(GradeTooHighException const& src) {
    this->operator=(src);
}

Form::GradeTooHighException::~GradeTooHighException() throw() {
}

Form::GradeTooHighException&
Form::GradeTooHighException::operator=(GradeTooHighException const& right) {
    if (this != &right)
        this->signed_ = right.getSigned();
    return (*this);
}

bool    Form::GradeTooHighException::getSigned() const {
    return (this->signed_);
}

char const* Form::GradeTooHighException::what() const throw() {
    if (this->getSigned())
        return ("The grade required to sign is high.");
    return ("The grade required to execute is high.");
}
