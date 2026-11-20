/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 08:57:27 by tkatsuma          #+#    #+#             */
/*   Updated: 2026/11/13 09:00:01 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#include <iostream>

#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", kGradeToSign, kGradeToExecute),
      _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& other)
    : AForm(other), _target(other._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& other) {
  if (this != &other) {
    AForm::operator=(other);
    _target = other._target;
  }
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
  if (!isSigned()) throw AForm::NotSignedException();
  if (executor.getGrade() > getGradeToExecute())
    throw AForm::GradeTooLowException();
  std::cout << _target << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}
