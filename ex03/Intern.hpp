/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 05:16:37 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/06 10:58:02 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX03_INTERN_HPP_
#define EX03_INTERN_HPP_

#include <string>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class   Intern {
 public:
    Intern();
    Intern(Intern const& src);
    ~Intern();
    Intern& operator=(Intern const& right);

    Form*   makeForm(std::string const& name, std::string const& target);

 private:
    Form*   makeShrubberyCreationForm_(std::string const& target);
    Form*   makeRobotomyRequestForm_(std::string const& target);
    Form*   makePresidentialPardonForm_(std::string const& target);

    typedef Form*   (Intern::* f)(std::string const&);
    struct  makeFormType_ {
        std::string const   name;
        f const             func;
    };
    static const makeFormType_    makeFormTypeList_[];
};

#endif  // EX03_INTERN_HPP_
