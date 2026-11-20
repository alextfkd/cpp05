/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 08:24:45 by tkatsuma          #+#    #+#             */
/*   Updated: 2026/09/01 07:52:55 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Now that you have bureaucrats, let’s give them something to do. What better
activity could there be than filling out a stack of forms? Let’s create a Form
class. It has: • A constant name. • A boolean indicating whether it is signed
(at construction, it is not). • A constant grade required to sign it. • A
constant grade required to execute it. All these attributes are private, not
protected. The grades of the Form follow the same rules as those of the
Bureaucrat. Thus, the following exceptions will be thrown if a form’s grade is
out of bounds: Form::GradeTooHighException and Form::GradeTooLowException. As
before, write getters for all attributes and overload the insertion («) operator
to print all the form’s information.

Also, add a beSigned() member function to the Form that takes a Bureaucrat as a
parameter. It changes the form’s status to signed if the bureaucrat’s grade is
high enough (greater than or equal to the required one).

Remember, grade 1 is higher than grade 2.
If the grade is too low, throw a Form::GradeTooLowException.
*/

#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <ostream>
#include <string>

class Bureaucrat;

class Form {
 private:
  const std::string _name;
  bool              _signed;
  const int         _gradeToSign;
  const int         _gradeToExecute;

  void validateGrade(int grade) const;

 public:
  Form(const std::string& name, int gradeToSign, int gradeToExecute);
  Form(const Form& other);
  Form& operator=(const Form& other);
  ~Form();

  std::string getName() const;
  bool        isSigned() const;
  int         getGradeToSign() const;
  int         getGradeToExecute() const;

  void beSigned(const Bureaucrat& bureaucrat);

  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw();
  };
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
