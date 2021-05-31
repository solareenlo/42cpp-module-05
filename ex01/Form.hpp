/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 02:14:05 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/01 06:31:04 by tayamamo         ###   ########.fr       */
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
    void                beSigned(Bureaucrat const& bureaucrat);

 private:
    std::string         name_;
    int const           signableGrade_;
    int const           executableGrade_;
    bool                signed_;
    static const int    highest_grade_ = 1;
    static const int    lowest_grade_ = 150;

 private:
    int const           getHighestGrade_() const;
    int const           getLowestGrade_() const;
    int                 checkGrade_(int grade);

 public:
    class   GradeTooHighException : public std::exception {
     public:
        GradeTooHighException();
        explicit GradeTooHighException(bool sign);
        GradeTooHighException(GradeTooHighException const& src);
        ~GradeTooHighException() throw();
        GradeTooHighException&  operator=(GradeTooHighException const& right);

     public:
        bool        getSigned() const;
        char const* what() const throw();

     private:
        bool        signed_;
    };

 public:
    class   GradeTooLowException : public std::exception {
     public:
        GradeTooLowException();
        explicit GradeTooLowException(bool sign);
        GradeTooLowException(GradeTooLowException const& src);
        ~GradeTooLowException() throw();
        GradeTooLowException& operator=(GradeTooLowException const& right);

     public:
        char const* what() const throw();

     private:
        bool        signed_;
    };
};

std::ostream&   operator<<(std::ostream& ostream, Form const& right);

#endif  // EX01_FORM_HPP_
