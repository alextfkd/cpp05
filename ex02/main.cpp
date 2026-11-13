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
  // test_ex00();
  std::cout << "=== Test ex01, full functionality test ===" << std::endl;
  Bureaucrat            alice_10 = Bureaucrat("Alice", 10);
  Bureaucrat            bob_30   = Bureaucrat("Bob", 30);
  ShrubberyCreationForm alice_math_form =
      ShrubberyCreationForm("Math Test", 20, 150);
  RobotomyRequestForm bob_english_form =
      RobotomyRequestForm("English Test", 20, 150);
  PresidentialPardonForm charlie_presidential_form =
      PresidentialPardonForm("Presidential Test", 20, 150);

  std::cout << "=== Form before signing ===" << std::endl;
  std::cout << alice_math_form << std::endl;
  std::cout << "=== Bureaucrat signing form ===" << std::endl;
  alice_10.signForm(alice_math_form);
  std::cout << "\n=== Form after signing ===" << std::endl;
  std::cout << alice_math_form << std::endl;

  std::cout << "=== Form before signing ===" << std::endl;
  std::cout << bob_english_form << std::endl;
  std::cout << "=== Bureaucrat signing form ===" << std::endl;
  bob_30.signForm(bob_english_form);
  std::cout << "\n=== Form after signing ===" << std::endl;
  std::cout << bob_english_form << std::endl;
  return 0;
}
