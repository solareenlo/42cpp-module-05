/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 09:23:48 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/02 21:15:14 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX02_FORM_HPP_
#define EX02_FORM_HPP_

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class   Bureaucrat;

class   Form {
 public:
    Form(std::string const& name, int signGrade, int execGrade);
    Form(Form const& src);
    ~Form();
    Form&   operator=(Form const& right);

    std::string const&  getName() const;
    int                 getSignGrade() const;
    int                 getExecGrade() const;
    bool                getSigned() const;
    void                beSigned(Bureaucrat const& bure);

 private:
    Form();
    std::string const   name_;
    int                 sign_grade_;
    int                 exec_grade_;
    bool                signed_;
    static const int    highest_grade_ = 1;
    static const int    lowest_grade_ = 150;
    int                 getHighestGrade_() const;
    int                 getLowestGrade_() const;
    void                setSigned(bool sign);
    void                checkGrade(int grade);

    class   GradeTooHighException : public std::exception {
     public:
        GradeTooHighException();
        GradeTooHighException(GradeTooHighException const& src);
        ~GradeTooHighException() throw();
        GradeTooHighException&  operator=(GradeTooHighException const& right);
        char const* what() const throw();
    };

    class   GradeTooLowException : public std::exception {
     public:
        GradeTooLowException();
        GradeTooLowException(GradeTooLowException const& src);
        ~GradeTooLowException() throw();
        GradeTooLowException&   operator=(GradeTooLowException const& right);
        char const* what() const throw();
    };
};

std::ostream&   operator<<(std::ostream& ostream, Form const& right);

#endif  // EX02_FORM_HPP_
