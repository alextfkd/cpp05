/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 06:10:24 by tkatsuma          #+#    #+#             */
/*   Updated: 2026/11/20 07:18:05 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {
 private:
  // Private members: name and grade
  const std::string _name;
  int               _grade;

  // Validation of grade
  void validateGrade(int grade) const;

 public:
  Bureaucrat(const std::string& name, int grade);
  Bureaucrat(const Bureaucrat& other);
  Bureaucrat& operator=(const Bureaucrat& other);
  ~Bureaucrat();

  // Getters and setters
  std::string getName() const;
  int         getGrade() const;
  int         incrementGrade();
  int         decrementGrade();

  // Exception classes
  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw();
  };
};

// Declaration of output stream operator overloading
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
