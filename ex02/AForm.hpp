/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 08:24:45 by tkatsuma          #+#    #+#             */
/*   Updated: 2026/11/13 09:04:17 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

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

 public:
  AForm(const std::string& name, int gradeToSign, int gradeToExecute);
  AForm(const AForm& other);
  AForm& operator=(const AForm& other);
  ~AForm();

  std::string getName() const;
  bool        isSigned() const;
  int         getGradeToSign() const;
  int         getGradeToExecute() const;

  void beSigned(const Bureaucrat& bureaucrat);

  void validateGrade(int grade);

  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw();
  };
  void execute(Bureaucrat const& executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
