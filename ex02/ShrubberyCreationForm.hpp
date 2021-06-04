/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 20:35:16 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/04 08:50:34 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX02_SHRUBBERYCREATIONFORM_HPP_
#define EX02_SHRUBBERYCREATIONFORM_HPP_

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
    const char* ascii_tree_;
};

#endif  // EX02_SHRUBBERYCREATIONFORM_HPP_
