/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:25:37 by tayamamo          #+#    #+#             */
/*   Updated: 2021/05/31 19:22:03 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char* msg_too_high_ = "Grade is too high.";
const char* msg_too_low_ = "Grade is too low.";

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

int Bureaucrat::getLowestGrade_() const {
    return (this->lowest_grade_);
}

int Bureaucrat::getHighestGrade_() const {
    return (this->highest_grade_);
}

Bureaucrat::GradeTooHighException::GradeTooHighException() : std::exception() {
}

char const* Bureaucrat::GradeTooHighException::what() const throw() {
    return (msg_too_high_);
}

char const* Bureaucrat::GradeTooLowException::what() const throw() {
    return (msg_too_low_);
}

int Bureaucrat::checkGrade_(int grade) {
    if (grade < this->getLowestGrade_())
        throw Bureaucrat::GradeTooLowException();
    if (grade > this->getHighestGrade_())
        throw Bureaucrat::GradeTooHighException();
    return (grade);
}

std::ostream&   operator<<(std::ostream& ostream, Bureaucrat const& right) {
    ostream << right.getName() << ", bureaucrat grade" << right.getGrade();
    return (ostream);
}
