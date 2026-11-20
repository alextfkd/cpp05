/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 10:40:19 by tkatsuma          #+#    #+#             */
/*   Updated: 2026/11/20 12:20:09 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void test_shrubbery() {
  const int kAliceGrade = 10;
  const int kBobGrade   = 140;

  std::cout << "=== Shrubbery: sign and execute ===" << std::endl;
  Bureaucrat            alice("Alice", kAliceGrade);
  ShrubberyCreationForm home("home");
  alice.signForm(home);
  alice.executeForm(home);

  std::ifstream file("home_shrubbery");
  if (!file.is_open()) {
    std::cout << "home_shrubbery was not created" << std::endl;
  } else {
    std::cout << "=== home_shrubbery ===" << std::endl;
    std::string line;
    while (std::getline(file, line)) {
      std::cout << line << std::endl;
    }
  }

  std::cout << "\n=== Shrubbery: sign succeeds, execute grade too low ==="
            << std::endl;
  Bureaucrat            bob("Bob", kBobGrade);
  ShrubberyCreationForm garden("garden");
  bob.signForm(garden);
  bob.executeForm(garden);
}

void test_robotomy() {
  const int kExecutorGrade = 10;
  const int kSignerGrade   = 72;
  const int kAttempts      = 4;

  std::cout << "\n=== Robotomy: execute before signing ===" << std::endl;
  Bureaucrat          alice("Alice", kExecutorGrade);
  RobotomyRequestForm bender("Bender");
  alice.executeForm(bender);

  std::cout << "\n=== Robotomy: sign succeeds, execute grade too low ==="
            << std::endl;
  Bureaucrat          signer("Dave", kSignerGrade);
  RobotomyRequestForm marvin("Marvin");
  signer.signForm(marvin);
  signer.executeForm(marvin);

  std::cout << "\n=== Robotomy: sign and execute ===" << std::endl;
  alice.signForm(bender);
  for (int attempt = 0; attempt < kAttempts; ++attempt) {
    alice.executeForm(bender);
  }
}

void test_pardon() {
  const int kSignerGrade   = 10;
  const int kExecutorGrade = 5;

  std::cout << "\n=== Pardon: execute before signing ===" << std::endl;
  Bureaucrat             alice("Alice", kSignerGrade);
  PresidentialPardonForm arthur("Arthur Dent");
  alice.executeForm(arthur);

  std::cout << "\n=== Pardon: sign succeeds, execute grade too low ==="
            << std::endl;
  alice.signForm(arthur);
  alice.executeForm(arthur);

  std::cout << "\n=== Pardon: sign and execute ===" << std::endl;
  Bureaucrat             president("Zaphod", kExecutorGrade);
  PresidentialPardonForm ford("Ford Prefect");
  president.signForm(ford);
  president.executeForm(ford);
}

void test_intern() {
  std::cout << "=== Test intern ===" << std::endl;
  Intern intern;
  AForm* form = intern.makeForm("shrubbery creation", "home");
  Bureaucrat("Alice", 10).signForm(*form);
  Bureaucrat("Alice", 10).executeForm(*form);
  delete form;
  form = intern.makeForm("robotomy request", "bender");
  Bureaucrat("Alice", 10).signForm(*form);
  Bureaucrat("Alice", 10).executeForm(*form);
  delete form;
  form = intern.makeForm("presidential pardon", "arthur");
  Bureaucrat("Alice", 10).signForm(*form);
  Bureaucrat("Alice", 10).executeForm(*form);
  delete form;
  form = intern.makeForm("invalid form", "arthur");
  delete form;
}

int main() {
  std::cout << "=== Test ex03 ===" << std::endl;
  test_shrubbery();
  test_robotomy();
  test_pardon();
  test_intern();
  return 0;
}
