/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:25:37 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/01 21:35:27 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("Eva01") {
    this->grade_ = this->getLowestGrade_();
}

Bureaucrat::Bureaucrat(std::string const& name, int grade) : name_(name) {
    this->grade_ = this->checkGrade_(grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const& src) {
    this->operator=(src);
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& right) {
    if (this != &right) {
        this->name_ = right.getName();
        this->grade_ = this->checkGrade_(right.getGrade());
    }
    return (*this);
}

std::string const& Bureaucrat::getName() const {
    return (this->name_);
}

int Bureaucrat::getGrade() const {
    return (this->grade_);
}

void    Bureaucrat::setGrade(int grade) {
    this->grade_ = grade;
}

void    Bureaucrat::incrementGrade() {
    this->setGrade(this->checkGrade_(this->getGrade() - 1));
}

void    Bureaucrat::decrementGrade() {
    this->setGrade(this->checkGrade_(this->getGrade() + 1));
}

void    Bureaucrat::signForm(Form* form) const {
    try {
        form->beSigned(*this);
        std::cout << this->getName() << " signs " << form->getName();
        std::cout << std::endl;
    }
    catch (std::exception const& e) {
        std::cout << this->getName() << " cannot sign " << form->getName();
        std::cout << " because " << e.what() << std::endl;
    }
}

int Bureaucrat::getLowestGrade_() const {
    return (this->lowest_grade_);
}

int Bureaucrat::getHighestGrade_() const {
    return (this->highest_grade_);
}

int Bureaucrat::checkGrade_(int grade) {
    if (grade > this->getLowestGrade_())
        throw Bureaucrat::GradeTooLowException();
    if (grade < this->getHighestGrade_())
        throw Bureaucrat::GradeTooHighException();
    return (grade);
}

std::ostream&   operator<<(std::ostream& ostream, Bureaucrat const& right) {
    ostream << right.getName() << ", bureaucrat grade " << right.getGrade();
    ostream << std::endl;
    return (ostream);
}

Bureaucrat::GradeTooHighException::GradeTooHighException() : std::exception() {
}

Bureaucrat::GradeTooHighException::GradeTooHighException(
        GradeTooHighException const& src) {
    this->operator=(src);
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {
}

Bureaucrat::GradeTooHighException&
Bureaucrat::GradeTooHighException::operator=
(GradeTooHighException const& right) {
    (void)right;
    return (*this);
}

char const* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade is too high");
}

Bureaucrat::GradeTooLowException::GradeTooLowException() : std::exception() {
}

Bureaucrat::GradeTooLowException::GradeTooLowException(
        GradeTooLowException const& src) {
    this->operator=(src);
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {
}

Bureaucrat::GradeTooLowException&
Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const& right) {
    (void)right;
    return (*this);
}

char const* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade is too low");
}
