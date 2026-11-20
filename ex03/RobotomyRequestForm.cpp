/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 08:59:27 by tkatsuma          #+#    #+#             */
/*   Updated: 2026/11/13 09:06:26 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <iostream>

#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", kGradeToSign, kGradeToExecute),
      _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& other) {
  if (this != &other) {
    AForm::operator=(other);
    _target = other._target;
  }
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
  if (!isSigned()) throw AForm::NotSignedException();
  if (executor.getGrade() > getGradeToExecute())
    throw AForm::GradeTooLowException();
  std::cout << "GAGAGAGA" << std::endl;
  if (std::rand() % 2 == 0)
    std::cout << _target << " has been robotomized successfully" << std::endl;
  else
    std::cout << _target << " robotomy failed" << std::endl;
}
