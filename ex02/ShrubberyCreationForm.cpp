/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 10:59:59 by tkatsuma          #+#    #+#             */
/*   Updated: 2026/11/20 09:08:21 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <iostream>

#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", kGradeToSign, kGradeToExecute),
      _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& other) {
  if (this != &other) {
    AForm::operator=(other);
    _target = other._target;
  }
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
  if (!isSigned()) throw AForm::NotSignedException();
  if (executor.getGrade() > getGradeToExecute())
    throw AForm::GradeTooLowException();

  std::string filename = _target + "_shrubbery";
  const std::string ascii_trees =
      "      ccee88oo\n"
      "   C8O8O8Q8PoOb o8oo\n"
      " dOB69QO8PdUOpugoO9bD\n"
      "CgggbU8OU qOp qOdoUOdcb\n"
      "    6OuU  /p u gcoUodpP\n"
      "      \\\\//  /douUP\n"
      "        \\\\////\n"
      "         |||/\\\n"
      "         |||\\/\n"
      "         |||||\n"
      "   ....//||||\\....\n";
      std::ofstream file(filename.c_str());
      if (!file.is_open()) {
        throw AForm::ExecutionFailedException();
      }
      file << ascii_trees;
      file.close();
}
