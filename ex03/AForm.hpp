/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 08:24:45 by tkatsuma          #+#    #+#             */
/*   Updated: 2026/11/20 09:09:48 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <ostream>
#include <string>

class Bureaucrat;

/*
In all cases, the base class Form must be an abstract class and should therefore
be renamed AForm. Keep in mind that the form’s attributes need to remain private
and that they belong to the base class.
*/

class AForm {
 private:
  const std::string _name;
  bool              _signed;
  const int         _gradeToSign;
  const int         _gradeToExecute;

  void validateGrade(int grade) const;

 public:
  AForm(const std::string& name, int gradeToSign, int gradeToExecute);
  AForm(const AForm& other);
  AForm& operator=(const AForm& other);
  virtual ~AForm();

  // Getters and setters
  std::string getName() const;
  bool        isSigned() const;
  int         getGradeToSign() const;
  int         getGradeToExecute() const;

  // beSigned() should be a public member function,
  // so it can be called by the Bureaucrat class.
  void beSigned(const Bureaucrat& bureaucrat);

  virtual void execute(Bureaucrat const& executor) const = 0;

  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw();
  };

  class NotSignedException : public std::exception {
   public:
    const char* what() const throw();
  };

  class ExecutionFailedException : public std::exception {
   public:
    const char* what() const throw();
  };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
