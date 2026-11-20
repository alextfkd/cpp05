/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 08:59:31 by tkatsuma          #+#    #+#             */
/*   Updated: 2026/11/13 09:05:19 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
In all cases, the base class Form must be an abstract class and should therefore
be renamed AForm. Keep in mind that the form’s attributes need to remain private
and that they belong to the base class.

Add the following concrete classes:
• ShrubberyCreationForm:
    Required grades: sign 145, exec 137
    Creates a file <target>_shrubbery in the working directory and writes ASCII
trees inside it.

• RobotomyRequestForm: Required grades: sign 72, exec 45
Makes some drilling noises, then informs that <target> has been robotomized
successfully 50% of the time. Otherwise, it informs that the robotomy failed.

• PresidentialPardonForm: Required grades: sign 25, exec 5
Informs that <target> has been pardoned by Zaphod Beeblebrox.
All of them take only one parameter in their constructor: the target of the
form. For example, "home" if you want to plant shrubbery at home.
*/

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 public:
  static const int kGradeToSign    = 145;
  static const int kGradeToExecute = 137;

  ShrubberyCreationForm(const std::string& target);
  ShrubberyCreationForm(const ShrubberyCreationForm& other);
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
  ~ShrubberyCreationForm();

  void execute(Bureaucrat const& executor) const;

 private:
  std::string _target;
};

#endif
