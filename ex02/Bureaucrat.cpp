/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 10:58:00 by tkatsuma          #+#    #+#             */
/*   Updated: 2026/11/13 09:12:18 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : _name(name), _grade(grade) {
  validateGrade(grade);
  _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : _name(other._name), _grade(other._grade) {
  validateGrade(other._grade);
  _grade = other._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  if (this != &other) {
    _grade = other._grade;
  }
  validateGrade(other._grade);
  return *this;
}

Bureaucrat::~Bureaucrat() {}

std::ostream& operator<<(std::ostream&     output_stream,
                         const Bureaucrat& bureaucrat) {
  output_stream << bureaucrat.getName() << ", bureaucrat grade "
                << bureaucrat.getGrade() << ".";
  return output_stream;
}

int Bureaucrat::validateGrade(int grade) {
  if (grade < kHighestGrade) {
    throw Bureaucrat::GradeTooHighException();
    return 1;
  }
  if (grade > kLowestGrade) {
    throw Bureaucrat::GradeTooLowException();
    return 1;
  }
  return 0;
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
void Bureaucrat::signForm(AForm& form) const {
  try {
    form.beSigned(*this);
    std::cout << getName() << " signed " << form.getName() << "." << std::endl;
  } catch (std::exception& e) {
    std::cout << getName() << " couldn't sign " << form.getName() << " because "
              << e.what() << "." << std::endl;
  }
}
