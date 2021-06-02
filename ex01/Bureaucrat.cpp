/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 04:56:53 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/02 09:13:34 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("Default"), grade_(150) {
    this->checkGrade(this->getGrade());
}

Bureaucrat::Bureaucrat(Bureaucrat const& src) : name_(src.getName()) {
    this->operator=(src);
}

Bureaucrat::Bureaucrat(std::string const& name, int grade)
    : name_(name), grade_(grade) {
    this->checkGrade(this->getGrade());
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& right) {
    if (this != &right) {
        this->grade_ = right.getGrade();
    }
    this->checkGrade(this->getGrade());
    return (*this);
}

std::string const&  Bureaucrat::getName() const { return (this->name_); }
int                 Bureaucrat::getGrade() const { return (this->grade_); }
void                Bureaucrat::setGrade(int grade) { this->grade_ = grade; }

int                 Bureaucrat::getHighestGrade() const {
    return (this->highest_grade_);
}

int                 Bureaucrat::getLowestGrade() const {
    return (this->lowest_grade_);
}

void    Bureaucrat::incrementGrade() {
    this->checkGrade(this->getGrade() - 1);
    this->setGrade(this->getGrade() - 1);
}

void    Bureaucrat::decrementGrade() {
    this->checkGrade(this->getGrade() + 1);
    this->setGrade(this->getGrade() + 1);
}

void    Bureaucrat::checkGrade(int grade) {
    if (grade > this->getLowestGrade())
        throw Bureaucrat::GradeTooLowException();
    if (grade < this->getHighestGrade())
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::GradeTooHighException::GradeTooHighException() : std::exception() {}

Bureaucrat::GradeTooHighException::GradeTooHighException
(GradeTooHighException const& src) : std::exception() {
    this->operator=(src);
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

Bureaucrat::GradeTooHighException&
Bureaucrat::GradeTooHighException::operator=
(Bureaucrat::GradeTooHighException const& right) {
    (void)right;
    return (*this);
}

char const* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade is too high.");
}

Bureaucrat::GradeTooLowException::GradeTooLowException() : std::exception() {}

Bureaucrat::GradeTooLowException::GradeTooLowException
(GradeTooLowException const& src) : std::exception() {
    this->operator=(src);
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

Bureaucrat::GradeTooLowException&
Bureaucrat::GradeTooLowException::operator=
(Bureaucrat::GradeTooLowException const& right) {
    (void)right;
    return (*this);
}

char const* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade is too low.");
}

std::ostream&   operator<<(std::ostream& ostream, Bureaucrat const& right) {
    ostream << right.getName() << ", bureaucrat grade " << right.getGrade();
    ostream << std::endl;
    return (ostream);
}
