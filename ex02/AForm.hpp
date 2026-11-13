/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 08:24:45 by tkatsuma          #+#    #+#             */
/*   Updated: 2026/11/13 11:02:09 by tkatsuma         ###   ########.fr       */
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

 public:
  static const int kHighestGrade = 1;
  static const int kLowestGrade  = 150;

  AForm(const std::string& name, int gradeToSign, int gradeToExecute);
  AForm(const AForm& other);
  AForm& operator=(const AForm& other);
  virtual ~AForm();

  std::string getName() const;
  bool        isSigned() const;
  int         getGradeToSign() const;
  int         getGradeToExecute() const;

  void beSigned(const Bureaucrat& bureaucrat);

  static void validateGrade(int grade);

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

  virtual void execute(Bureaucrat const& executor) const = 0;
};

std::ostream& operator<<(std::ostream& output_stream, const AForm& form);

#endif
