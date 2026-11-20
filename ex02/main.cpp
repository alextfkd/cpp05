/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 10:40:19 by tkatsuma          #+#    #+#             */
/*   Updated: 2026/11/12 11:47:43 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
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

int main() {
  const int kBobGrade = 140;

  std::cout << "=== Test ex02 ===" << std::endl;
  test_shrubbery();

  Bureaucrat             bob = Bureaucrat("Bob", kBobGrade);
  RobotomyRequestForm    robotomy("Bender");
  PresidentialPardonForm pardon("Arthur Dent");

  std::cout << "\n=== Form before signing ===" << std::endl;
  std::cout << robotomy << std::endl;
  std::cout << "=== Bureaucrat signing form ===" << std::endl;
  bob.signForm(robotomy);
  std::cout << "\n=== Form after signing ===" << std::endl;
  std::cout << robotomy << std::endl;

  (void)pardon;
  return 0;
}
