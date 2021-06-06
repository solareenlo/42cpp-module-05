/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 20:35:16 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/06 05:15:57 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX03_SHRUBBERYCREATIONFORM_HPP_
#define EX03_SHRUBBERYCREATIONFORM_HPP_

#include <fstream>
#include <string>
#include "Form.hpp"

class   ShrubberyCreationForm : public Form {
 public:
    ShrubberyCreationForm(ShrubberyCreationForm const& src);
    explicit ShrubberyCreationForm(std::string const& target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm&  operator=(ShrubberyCreationForm const& right);

    void    execute(Bureaucrat const& executor) const;

 private:
    ShrubberyCreationForm();
    static const char*  form_name_;
    static const int    sign_grade_ = 145;
    static const int    exec_grade_ = 137;
    static const char*  ascii_tree_;
    char const*         getAsciiTree() const;
};

#endif  // EX03_SHRUBBERYCREATIONFORM_HPP_
