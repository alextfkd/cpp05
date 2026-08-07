/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 10:40:19 by tkatsuma          #+#    #+#             */
/*   Updated: 2026/08/07 08:06:00 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Let’s design an artificial nightmare of offices, corridors, forms, and waiting
queues.

Sounds fun? No? Too bad.

First, start with the smallest cog in this vast bureaucratic machine: the
Bureaucrat. A Bureaucrat must have: • A constant name. • A grade that ranges
from 1 (highest possible grade) to 150 (lowest possible grade). Any attempt to
instantiate a Bureaucrat with an invalid grade must throw an exception: either a
Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.

You will provide getters for both attributes: getName() and getGrade(). You must
also implement two member functions to increment or decrement the bureaucrat’s
grade. If the grade goes out of range, both functions must throw the same
exceptions as the constructor.

Remember, since grade 1 is the highest and 150 the lowest,
incrementing a grade 3 should result in a grade 2 for the bureaucrat.
The thrown exceptions must be catchable using try and catch blocks:

try
{
  do some stuff with bureaucrats
}
catch (std::exception & e)
{
  handle exception
}
You must implement an overload of the insertion («) operator to print output in
the following format (without the angle brackets): <name>, bureaucrat grade
<grade>. As usual, submit some tests to prove that everything works as expected.

*/

#include "Bureaucrat.hpp"

int main() {
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
  return 0;
}
