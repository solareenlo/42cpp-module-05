/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 04:14:28 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/06 05:16:03 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX03_PRESIDENTIALPARDONFORM_HPP_
#define EX03_PRESIDENTIALPARDONFORM_HPP_

#include <string>
#include "Form.hpp"

class   PresidentialPardonForm : public Form {
 public:
    PresidentialPardonForm(PresidentialPardonForm const& src);
    explicit PresidentialPardonForm(std::string const& target);
    ~PresidentialPardonForm();
    PresidentialPardonForm& operator=(PresidentialPardonForm const& right);

    void    execute(Bureaucrat const& executer) const;

 private:
    PresidentialPardonForm();
    static const char*  form_name_;
    static const int    sign_grade_ = 25;
    static const int    exec_grade_ = 5;
};

#endif  // EX03_PRESIDENTIALPARDONFORM_HPP_
