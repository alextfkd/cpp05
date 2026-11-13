/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 08:57:27 by tkatsuma          #+#    #+#             */
/*   Updated: 2026/11/13 09:00:01 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
In all cases, the base class Form must be an abstract class and should therefore be
renamed AForm. Keep in mind that the form’s attributes need to remain private and
that they belong to the base class.

• PresidentialPardonForm: Required grades: sign 25, exec 5
Informs that <target> has been pardoned by Zaphod Beeblebrox.

All of them take only one parameter in their constructor: the target of the form.
For example, "home" if you want to plant shrubbery at home.
*/

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), target(other.target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!getIsSigned())
    {
        throw AForm::NotSignedException();
    }
    if (executor.getGrade() > getExecGrade())
    {
        throw AForm::GradeTooLowException();
    }
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
