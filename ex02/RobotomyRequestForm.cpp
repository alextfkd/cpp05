/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 08:59:27 by tkatsuma          #+#    #+#             */
/*   Updated: 2026/11/13 09:06:26 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
In all cases, the base class Form must be an abstract class and should therefore be
renamed AForm. Keep in mind that the form’s attributes need to remain private and
that they belong to the base class.

Add the following concrete classes:
• ShrubberyCreationForm:
    Required grades: sign 145, exec 137
    Creates a file <target>_shrubbery in the working directory and writes ASCII trees
    inside it.

• RobotomyRequestForm: Required grades: sign 72, exec 45
Makes some drilling noises, then informs that <target> has been robotomized
successfully 50% of the time. Otherwise, it informs that the robotomy failed.

• PresidentialPardonForm: Required grades: sign 25, exec 5
Informs that <target> has been pardoned by Zaphod Beeblebrox.
All of them take only one parameter in their constructor: the target of the form.
For example, "home" if you want to plant shrubbery at home.
*/

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!getIsSigned())
    {
        std::cout << "RobotomyRequestForm is not signed" << std::endl;
        throw AForm::NotSignedException();
    }
    if (executor.getGrade() > getExecGrade())
    {
        std::cout << "RobotomyRequestForm is not executable" << std::endl;
        throw AForm::GradeTooLowException();
    }
    if (rand() % 2 == 0)
    {
        std::cout << target << " has been robotomized successfully" << std::endl;
    }
    else
    {
        std::cout << target << " has been robotomized failed" << std::endl;
    }
}
