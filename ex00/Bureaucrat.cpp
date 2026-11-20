/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 10:58:00 by tkatsuma          #+#    #+#             */
/*   Updated: 2026/11/20 07:37:21 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
