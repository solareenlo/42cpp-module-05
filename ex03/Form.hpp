/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 09:23:48 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/06 05:15:41 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX03_FORM_HPP_
#define EX03_FORM_HPP_

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class   Bureaucrat;

class   Form {
 public:
    Form(std::string const& name, int signGrade, int execGrade);
    Form(std::string const& name, int signGrade, int execGrade,
        std::string const& target);
    Form(Form const& src);
    ~Form();
    Form&   operator=(Form const& right);

    std::string const&  getName() const;
    int                 getSignGrade() const;
    int                 getExecGrade() const;
    bool                getSigned() const;
    std::string const&  getTarget() const;
    void                beSigned(Bureaucrat const& bure);

 protected:
    Form();
    virtual void        execute(Bureaucrat const& executor) const;

 private:
    std::string const   name_;
    int const           sign_grade_;
    int const           exec_grade_;
    bool                signed_;
    std::string const   target_;
    static const char*  init_name_;
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

    class   NotSignedException : public std::exception {
     public:
        NotSignedException();
        NotSignedException(NotSignedException const& src);
        ~NotSignedException() throw();
        NotSignedException& operator=(NotSignedException const& right);
        char const* what() const throw();
    };
};

std::ostream&   operator<<(std::ostream& ostream, Form const& right);

#endif  // EX03_FORM_HPP_
