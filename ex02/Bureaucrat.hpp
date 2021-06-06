/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:32:03 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/06 11:23:55 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX02_BUREAUCRAT_HPP_
#define EX02_BUREAUCRAT_HPP_

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class   Form;

class   Bureaucrat {
 public:
    Bureaucrat(std::string const& name, int const grade);
    Bureaucrat(Bureaucrat const& src);
    ~Bureaucrat();
    Bureaucrat&         operator=(Bureaucrat const& right);

    std::string const&  getName() const;
    int                 getGrade() const;
    void                incrementGrade();
    void                decrementGrade();
    void                signForm(Form* form) const;
    void                executeForm(Form const& form) const;

 private:
    Bureaucrat();
    std::string const   name_;
    int                 grade_;
    static const int    highest_grade_ = 1;
    static const int    lowest_grade_ = 150;
    void                setGrade(int grade);
    int                 getHighestGrade() const;
    int                 getLowestGrade() const;
    void                checkGrade(int grade);

    class   GradeTooHighException : public std::exception {
     public:
        GradeTooHighException();
        GradeTooHighException(GradeTooHighException const& src);
        ~GradeTooHighException() throw();
        GradeTooHighException& operator=(GradeTooHighException const& right);
        char const* what() const throw();
    };

    class   GradeTooLowException : public std::exception {
     public:
        GradeTooLowException();
        GradeTooLowException(GradeTooLowException const& src);
        ~GradeTooLowException() throw();
        GradeTooLowException& operator=(GradeTooLowException const& right);
        char const* what() const throw();
    };
};

std::ostream&   operator<<(std::ostream& stream, Bureaucrat const& right);

#endif  // EX02_BUREAUCRAT_HPP_
