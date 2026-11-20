/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 10:40:19 by tkatsuma          #+#    #+#             */
/*   Updated: 2026/11/20 07:47:45 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void test_ex00() {
  std::cout << "\n=== Test ex00 ===" << std::endl;
  std::cout << "=== Instanciation test: Normal ===" << std::endl;
  Bureaucrat* bureaucrat = new Bureaucrat("Alice", 1);
  std::cout << *bureaucrat << std::endl;
  delete bureaucrat;

  std::cout << "\n=== Instanciation test: Normal ===" << std::endl;
  Bureaucrat* bureaucrat2 = new Bureaucrat("Bob", 150);
  std::cout << *bureaucrat2 << std::endl;
  delete bureaucrat2;

  std::cout << "\n=== Increment test: Normal ===" << std::endl;
  Bureaucrat* bureaucrat3 = new Bureaucrat("Charlie", 1);
  std::cout << "Before decrement: " << *bureaucrat3 << std::endl;
  bureaucrat3->decrementGrade();
  std::cout << "After decrement: " << *bureaucrat3 << std::endl;
  delete bureaucrat3;

  std::cout << "\n=== Decrement test: Normal ===" << std::endl;
  Bureaucrat* bureaucrat4 = new Bureaucrat("Dave", 150);
  std::cout << "Before increment: " << *bureaucrat4 << std::endl;
  bureaucrat4->incrementGrade();
  std::cout << "After increment: " << *bureaucrat4 << std::endl;
  delete bureaucrat4;

  std::cout << "\n=== Exception test: GradeTooHighException ===" << std::endl;
  std::cout << "=== GradeTooHighException upon instantiation ===" << std::endl;
  try {
    Bureaucrat* bureaucrat5 = new Bureaucrat("Eve", 0);
    std::cout << *bureaucrat5 << std::endl;
    delete bureaucrat5;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "=== GradeTooHighException upon increment ===" << std::endl;
  try {
    Bureaucrat bureaucrat7 = Bureaucrat("Frank", 1);
    bureaucrat7.incrementGrade();
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "\n=== Exception test: GradeTooLowException ===" << std::endl;
  std::cout << "=== GradeTooLowException upon instantiation ===" << std::endl;
  try {
    Bureaucrat* bureaucrat6 = new Bureaucrat("Frank", 151);
    std::cout << *bureaucrat6 << std::endl;
    delete bureaucrat6;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "=== GradeTooLowException upon decrement ===" << std::endl;
  try {
    Bureaucrat bureaucrat8 = Bureaucrat("Frank", 150);
    bureaucrat8.decrementGrade();
    std::cout << bureaucrat8 << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}

void test_ex01() {
  std::cout << "\n=== Test ex01, for Form class ===" << std::endl;
  std::cout << "=== instantiate Form class ===" << std::endl;
  Form form = Form("Test Form", 1, 150);
  std::cout << form << std::endl;
  std::cout << "=== copy constructor ===" << std::endl;
  Form form2 = form;
  std::cout << form2 << std::endl;
  std::cout << "=== copy assignment operator ===" << std::endl;
  Form form3 = Form("Test Form 2", 1, 150);
  form3      = form;
  std::cout << form3 << std::endl;
  std::cout << "=== instantiate Form class with grade too high ==="
            << std::endl;
  try {
    Form form4 = Form("Test Form 3", 0, 150);
    std::cout << form4 << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "=== instantiate Form class with grade too low ===" << std::endl;
  try {
    Form form5 = Form("Test Form 4", 151, 150);
    std::cout << form5 << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "=== instantiate Form class with execute grade too high ==="
            << std::endl;
  try {
    Form form6 = Form("Test Form 5", 1, 0);
    std::cout << form6 << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "=== instantiate Form class with execute grade too low ==="
            << std::endl;
  try {
    Form form7 = Form("Test Form 6", 1, 151);
    std::cout << form7 << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}

int main() {
  // test_ex00();
  test_ex01();
  std::cout << "=== Test ex01, full functionality test ===" << std::endl;
  Bureaucrat alice_10         = Bureaucrat("Alice", 10);
  Bureaucrat bob_30           = Bureaucrat("Bob", 30);
  Form       alice_math_test  = Form("Math Test", 20, 150);
  Form       bob_english_test = Form("English Test", 20, 150);

  std::cout << "=== Form before signing ===" << std::endl;
  std::cout << alice_math_test << std::endl;
  std::cout << "=== Bureaucrat signing form ===" << std::endl;
  alice_10.signForm(alice_math_test);
  std::cout << "\n=== Form after signing ===" << std::endl;
  std::cout << alice_math_test << std::endl;

  std::cout << "=== Form before signing ===" << std::endl;
  std::cout << bob_english_test << std::endl;
  std::cout << "=== Bureaucrat signing form ===" << std::endl;
  bob_30.signForm(bob_english_test);
  std::cout << "\n=== Form after signing ===" << std::endl;
  std::cout << bob_english_test << std::endl;

  std::cout << "=== Sign when bureaucrat grade equals required grade ==="
            << std::endl;
  Bureaucrat carol_20       = Bureaucrat("Carol", 20);
  Form       carol_science  = Form("Science Test", 20, 150);
  std::cout << "=== Form before signing ===" << std::endl;
  std::cout << carol_science << std::endl;
  carol_20.signForm(carol_science);
  std::cout << "\n=== Form after signing ===" << std::endl;
  std::cout << carol_science << std::endl;
  return 0;
}
