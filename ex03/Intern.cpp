/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 09:50:13 by tkatsuma          #+#    #+#             */
/*   Updated: 2026/11/20 11:21:11 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& other) {
  (void)other;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& other) {
  (void)other;
  return *this;
}

AForm* Intern::createShrubberyCreationForm(std::string target) {
  return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(std::string target) {
  return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(std::string target) {
  return new PresidentialPardonForm(target);
}

/*
However, the intern has one key ability: the makeForm() function. This function
takes two strings as parameters: the first one represents the name of a form, and the
second one represents the target of the form. It returns a pointer to a AForm object
(corresponding to the form name passed as a parameter), with its target initialized to
the second parameter.
It should print something like:
Intern creates <form>
If the provided form name does not exist, print an explicit error message.

You must avoid unreadable and messy solutions, such as using an excessive if/elseif/else structure. This kind of approach will not be accepted during the evaluation
process. You’re not in the Piscine (pool) anymore. As usual, you must test everything
to ensure it works as expected.
*/
AForm* Intern::makeForm(std::string form_name, std::string target) {
  std::string form_names[] = {
    "shrubbery creation",
    "robotomy request",
    "presidential pardon"
  };
  AForm* (Intern::*createForms[])(std::string) = {
    &Intern::createShrubberyCreationForm,
    &Intern::createRobotomyRequestForm,
    &Intern::createPresidentialPardonForm
  };
  for (int i = 0; i < 3; i++) {
    if (form_name == form_names[i]) {
      std::cout << "Intern creates " << form_names[i] << std::endl;
      return (this->*createForms[i])(target);
    }
  }
  throw std::invalid_argument("Invalid form name");
}
