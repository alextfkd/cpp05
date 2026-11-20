/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 10:58:00 by tkatsuma          #+#    #+#             */
/*   Updated: 2026/11/20 08:29:28 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : _name(name), _grade(grade) {
  validateGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : _name(other._name), _grade(other._grade) {
  validateGrade(other._grade);
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  if (this != &other) {
    _grade = other._grade;
  }
  validateGrade(other._grade);
  return *this;
}

Bureaucrat::~Bureaucrat() {}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()
     << ".";
  return os;
}

void Bureaucrat::validateGrade(int grade) const {
  if (grade < 1) {
    throw Bureaucrat::GradeTooHighException();
  }
  if (grade > 150) {
    throw Bureaucrat::GradeTooLowException();
  }
}

std::string Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

int Bureaucrat::incrementGrade() {
  validateGrade(_grade - 1);
  _grade--;
  return _grade;
}

int Bureaucrat::decrementGrade() {
  validateGrade(_grade + 1);
  _grade++;
  return _grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "Exception: Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "Exception: Grade too low!";
}

/*
Then, add a signForm() member function in the Bureaucrat class.
This function must call Form::beSigned() to attempt to sign the form.
If the form is signed successfully, it will print something like:
  <bureaucrat> signed <form>
Otherwise, it will print something like:
  <bureaucrat> couldn’t sign <form> because <reason>.
*/
void Bureaucrat::signForm(AForm& form) {
  try {
    form.beSigned(*this);
    std::cout << getName() << " signed " << form.getName() << "." << std::endl;
  } catch (std::exception& e) {
    std::cout << getName() << " couldn't sign " << form.getName() << " because "
              << e.what() << "." << std::endl;
  }
}

void Bureaucrat::executeForm(AForm const& form) const {
  try {
    form.execute(*this);
    std::cout << getName() << " executed " << form.getName() << "."
              << std::endl;
  } catch (std::exception& e) {
    std::cout << getName() << " couldn't execute " << form.getName()
              << " because " << e.what() << "." << std::endl;
  }
}
