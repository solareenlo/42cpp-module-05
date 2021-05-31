/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:50:40 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/01 00:42:06 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX00_BUREAUCRAT_HPP_
#define  EX00_BUREAUCRAT_HPP_

#include <iostream>
#include <string>

class   Bureaucrat {
 public:
    Bureaucrat();
    Bureaucrat(std::string const& name, int grade);
    Bureaucrat(Bureaucrat const& src);
    virtual ~Bureaucrat();
    Bureaucrat&         operator=(Bureaucrat const& right);

    std::string const&  getName() const;
    int                 getGrade() const;
    void                setGrade(int grade);
    void                incrementGrade();
    void                decrementGrade();

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

 private:
    std::string         name_;
    int                 grade_;
    static const int    highest_grade_ = 1;
    static const int    lowest_grade_ = 150;
    int                 getHighestGrade_() const;
    int                 getLowestGrade_() const;
    int                 checkGrade_(int grade);
};

std::ostream&   operator<<(std::ostream& ostream, Bureaucrat const& right);

#endif  // EX00_BUREAUCRAT_HPP_
