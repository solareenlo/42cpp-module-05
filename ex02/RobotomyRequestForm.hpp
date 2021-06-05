/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 02:18:30 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/06 03:58:21 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX02_ROBOTOMYREQUESTFORM_HPP_
#define EX02_ROBOTOMYREQUESTFORM_HPP_

#include <string>
#include <cstdlib>
#include <ctime>
#include "Form.hpp"

class   RobotomyRequestForm : public Form {
 public:
    explicit RobotomyRequestForm(std::string const& target);
    RobotomyRequestForm(RobotomyRequestForm const& src);
    ~RobotomyRequestForm();
    RobotomyRequestForm&    operator=(RobotomyRequestForm const& right);

    void    execute(Bureaucrat const& executer) const;

 private:
    RobotomyRequestForm();
    static const char*  form_name_;
    static const int    sign_grade_ = 72;
    static const int    exec_grade_ = 45;
};

#endif  // EX02_ROBOTOMYREQUESTFORM_HPP_
