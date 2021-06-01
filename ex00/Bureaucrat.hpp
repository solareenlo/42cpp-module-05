/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:32:03 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/01 19:38:33 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX00_BUREAUCRAT_HPP_
#define EX00_BUREAUCRAT_HPP_

#include <iostream>
#include <string>

class   Bureaucrat {
 public:
    Bureaucrat(std::string const& name, int const grade);
    Bureaucrat(Bureaucrat const& src);
    ~Bureaucrat();
    Bureaucrat& operator=(Bureaucrat const& right);

 private:
    Bureaucrat();

    std::string name_;
    int         grade_;
};

#endif  // EX00_BUREAUCRAT_HPP_
