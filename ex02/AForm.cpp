/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 08:24:45 by tkatsuma          #+#    #+#             */
/*   Updated: 2026/09/01 11:50:31 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name),
      _signed(false),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
  validateGrade(gradeToSign);
  validateGrade(gradeToExecute);
}

Form::Form(const Form& other)
    : _name(other._name),
      _signed(other._signed),
      _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute) {
  validateGrade(other._gradeToSign);
  validateGrade(other._gradeToExecute);
}

Form& Form::operator=(const Form& other) {
  if (this != &other) {
    _signed = other._signed;
  }
  validateGrade(other._gradeToSign);
  validateGrade(other._gradeToExecute);
  return *this;
}

Form::~Form() {}

std::ostream& operator<<(std::ostream& os, const Form& form) {
  os << "Form name: " << form.getName() << "\n"
     << "Form status: " << (form.isSigned() ? "signed" : "not signed") << "\n"
     << "Form grade to sign: " << form.getGradeToSign() << "\n"
     << "Form grade to execute: " << form.getGradeToExecute() << "\n";
  return os;
}

std::string Form::getName() const { return _name; }

bool AForm::isSigned() const { return _signed; }

int AForm::getGradeToSign() const { return _gradeToSign; }

int AForm::getGradeToExecute() const { return _gradeToExecute; }

const char* AForm::GradeTooLowException::what() const throw() {
  return "the grade is too low";
}

const char* AForm::GradeTooHighException::what() const throw() {
  return "the grade is too high";
}

void AForm::validateGrade(int grade) {
  if (grade < 1) {
    throw Form::GradeTooHighException();
  }
  if (grade > 150) {
    throw Form::GradeTooLowException();
  }
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
  if (bureaucrat.getGrade() <= _gradeToSign) {
    _signed = true;
  } else {
    throw Form::GradeTooLowException();
  }
}
