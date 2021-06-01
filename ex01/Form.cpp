/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 02:54:52 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/01 10:50:19 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() :
    name_("Test"),
    signableGrade_(this->getLowestGrade_()),
    executableGrade_(this->getLowestGrade_()) {
    this->signed_ = false;
}

Form::Form(std::string const& name, int const signableGrade,
        int const executableGrade) :
    name_(name),
    signableGrade_(checkGrade_(signableGrade, true)),
    executableGrade_(checkGrade_(executableGrade, false)) {
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

int Form::getSignableGrade() const {
    return (this->signableGrade_);
}

int Form::getExecutableGrade() const {
    return (this->executableGrade_);
}

bool    Form::isSigned() const {
    return (this->signed_);
}

void    Form::beSigned(Bureaucrat const& bureaucrat) {
    if (bureaucrat.getGrade() > this->signableGrade_)
        throw Form::GradeTooLowException(true);
    this->signed_ = true;
}

int Form::getHighestGrade_() const {
    return (this->highest_grade_);
}

int Form::getLowestGrade_() const {
    return (this->lowest_grade_);
}

int Form::checkGrade_(int grade, bool sign) {
    if (grade > this->getLowestGrade_())
        throw Form::GradeTooLowException(sign);
    if (grade < this->getHighestGrade_())
        throw Form::GradeTooHighException(sign);
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
        return ("the grade required to sign is too high");
    return ("The grade required to execute is too high");
}

Form::GradeTooLowException::GradeTooLowException() : signed_(false) {
}

Form::GradeTooLowException::GradeTooLowException(bool sign) : signed_(sign) {
}

Form::GradeTooLowException::GradeTooLowException
(GradeTooLowException const& src) {
    this->operator=(src);
}

Form::GradeTooLowException::~GradeTooLowException() throw() {
}

Form::GradeTooLowException&
Form::GradeTooLowException::operator=(GradeTooLowException const& right) {
    if (this != &right)
        this->signed_ = right.getSigned();
    return (*this);
}

bool    Form::GradeTooLowException::getSigned() const {
    return (this->signed_);
}

char const* Form::GradeTooLowException::what() const throw() {
    if (this->getSigned())
        return ("the grade required to sign is too low");
    return ("The grade required to execute is too low");
}

std::ostream&   operator<<(std::ostream& ostream, Form const& right) {
    ostream << right.getName() << " ";
    ostream << (right.isSigned() ? "" : "not ");
    ostream << "signed" << std::endl;
    return (ostream);
}
