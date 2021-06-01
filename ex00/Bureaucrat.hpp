/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:32:03 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/02 08:48:54 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX00_BUREAUCRAT_HPP_
#define EX00_BUREAUCRAT_HPP_

#include <iostream>
#include <string>
#include <exception>

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

 private:
    Bureaucrat();

    std::string const   name_;
    int                 grade_;
    void                setGrade(int grade);

    static const int    highest_grade_ = 1;
    static const int    lowest_grade_ = 150;
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

#endif  // EX00_BUREAUCRAT_HPP_
