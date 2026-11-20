/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 08:24:45 by tkatsuma          #+#    #+#             */
/*   Updated: 2026/09/01 09:18:36 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Now that you have bureaucrats, let’s give them something to do. What better
activity could there be than filling out a stack of forms? Let’s create a Form
class. It has: • A constant name. • A boolean indicating whether it is signed
(at construction, it is not). • A constant grade required to sign it. • A
constant grade required to execute it. All these attributes are private, not
protected. The grades of the Form follow the same rules as those of the
Bureaucrat. Thus, the following exceptions will be thrown if a form’s grade is
out of bounds: Form::GradeTooHighException and Form::GradeTooLowException. As
before, write getters for all attributes and overload the insertion («) operator
to print all the form’s information.
*/

#include "Form.hpp"

#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
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

bool Form::isSigned() const { return _signed; }

int Form::getGradeToSign() const { return _gradeToSign; }

int Form::getGradeToExecute() const { return _gradeToExecute; }

const char* Form::GradeTooLowException::what() const throw() {
  return "the grade is too low";
}

const char* Form::GradeTooHighException::what() const throw() {
  return "the grade is too high";
}

void Form::validateGrade(int grade) const {
  if (grade < 1) {
    throw Form::GradeTooHighException();
  }
  if (grade > 150) {
    throw Form::GradeTooLowException();
  }
}

/*
Also, add a beSigned() member function to the Form that takes a Bureaucrat as a
parameter. It changes the form’s status to signed if the bureaucrat’s grade is
high enough (greater than or equal to the required one). Remember, grade 1 is
higher than grade 2. If the grade is too low, throw a
Form::GradeTooLowException.

Then, add a signForm() member function in the Bureaucrat class. This function
must call Form::beSigned() to attempt to sign the form. If the form is signed
successfully, it will print something like: <bureaucrat> signed <form>
Otherwise, it will print something like:
  <bureaucrat> couldn’t sign <form> because <reason>.
*/
void Form::beSigned(const Bureaucrat& bureaucrat) {
  if (bureaucrat.getGrade() <= _gradeToSign) {
    _signed = true;
  } else {
    throw Form::GradeTooLowException();
  }
}
