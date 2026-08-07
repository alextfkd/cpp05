/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 10:58:00 by tkatsuma          #+#    #+#             */
/*   Updated: 2026/08/07 08:13:54 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
    : _name(name), _grade(grade) {
  // std::cout << "Bureaucrat default constructor called" << std::endl;
  validateGrade(grade);
  _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : _name(other._name), _grade(other._grade) {
  // std::cout << "Bureaucrat copy constructor called" << std::endl;
  validateGrade(other._grade);
  _grade = other._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  if (this != &other) {
    //_name = other.getName();
    _grade = other._grade;
  }
  validateGrade(other._grade);
  return *this;
}

Bureaucrat::~Bureaucrat() {
  // std::cout << "Bureaucrat destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, Bureaucrat bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
  return os;
}

int Bureaucrat::validateGrade(int grade) {
  if (grade < 1) {
    throw Bureaucrat::GradeTooHighException();
    return 1;
  }
  if (grade > 150) {
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
