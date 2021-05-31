/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 02:14:05 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/01 04:16:49 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX01_FORM_HPP_
#define EX01_FORM_HPP_

#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"

class   Form {
 public:
    Form();
    Form(std::string const& name, int signableGrade, int executableGrade);
    Form(Form const& src);
    ~Form();
    Form&   operator=(Form const& right);

 public:
    std::string const&  getName() const;
    int const           getSignableGrade() const;
    int const           getExecutableGrade() const;
    bool                isSigned() const;
    void                beSigned(Bureaucrat& bureaucrat);

 private:
    std::string         name_;
    int const           signableGrade_;
    int const           executableGrade_;
    bool                signed_;
    static const int    MAX_GRADE_ = 1;
    static const int    MIN_GRADE_ = 150;

 private:
    int const           getMaxGrade_() const;
    int const           getMinGrade_() const;
    int                 checkGrade_(int grade);

 public:
    class   GradeTooHighException : public std::exception {
     public:
        GradeTooHighException();
        GradeTooHighException(GradeTooHighException const& src);
        ~GradeTooHighException() throw();
        GradeTooHighException&  operator=(GradeTooHighException const& right);

     public:
        char const* what() const throw();
    };

 public:
    class   GradeTooLowException : public std::exception {
     public:
        GradeTooLowException();
        GradeTooLowException(GradeTooLowException const& src);
        ~GradeTooLowException() throw();
        GradeTooLowException& operator=(GradeTooLowException const& right);

     public:
        char const* what() const throw();
    };
};

std::ostream&   operator<<(std::ostream& ostream, Form const& right);

#endif  // EX01_FORM_HPP_
