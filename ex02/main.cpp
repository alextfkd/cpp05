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

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  const int kAliceGrade = 10;
  const int kBobGrade   = 140;

  std::cout << "=== Test ex02 ===" << std::endl;
  Bureaucrat             alice = Bureaucrat("Alice", kAliceGrade);
  Bureaucrat             bob   = Bureaucrat("Bob", kBobGrade);
  ShrubberyCreationForm  shrubbery("home");
  RobotomyRequestForm    robotomy("Bender");
  PresidentialPardonForm pardon("Arthur Dent");

  std::cout << "=== Form before signing ===" << std::endl;
  std::cout << shrubbery << std::endl;
  std::cout << "=== Bureaucrat signing form ===" << std::endl;
  alice.signForm(shrubbery);
  std::cout << "\n=== Form after signing ===" << std::endl;
  std::cout << shrubbery << std::endl;

  std::cout << "=== Form before signing ===" << std::endl;
  std::cout << robotomy << std::endl;
  std::cout << "=== Bureaucrat signing form ===" << std::endl;
  bob.signForm(robotomy);
  std::cout << "\n=== Form after signing ===" << std::endl;
  std::cout << robotomy << std::endl;

  (void)pardon;
  return 0;
}
