/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 10:59:59 by tkatsuma          #+#    #+#             */
/*   Updated: 2026/11/13 09:07:27 by tkatsuma         ###   ########.fr       */
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
All of them take only one parameter in their constructor: the target of the form. For
example, "home" if you want to plant shrubbery at home.
*/

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!getIsSigned())
    {
        std::cout << "ShrubberyCreationForm is not signed" << std::endl;
        throw AForm::NotSignedException();
    }
    if (executor.getGrade() > getExecGrade())
    {
        std::cout << "ShrubberyCreationForm is not executable" << std::endl;
        throw AForm::GradeTooLowException();
    }
    std::ofstream file(target + "_shrubbery");
    file << "ASCII trees" << std::endl;
    file.close();
    std::cout << "ShrubberyCreationForm is executed" << std::endl;
}
