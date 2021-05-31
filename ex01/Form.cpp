/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 02:54:52 by tayamamo          #+#    #+#             */
/*   Updated: 2021/06/01 04:17:03 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name_("Test"), signableGrade_(10), executableGrade_(10) {
    this->signed_ = false;
}

std::string const&  Form::getName() const {
    return (this->name_);
}
