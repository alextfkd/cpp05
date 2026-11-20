/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 09:50:16 by tkatsuma          #+#    #+#             */
/*   Updated: 2026/11/20 10:23:06 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
 private:
  AForm* createShrubberyCreationForm(std::string target);
  AForm* createRobotomyRequestForm(std::string target);
  AForm* createPresidentialPardonForm(std::string target);

 public:
  Intern();
  Intern(const Intern& other);
  ~Intern();
  Intern& operator=(const Intern& other);


  AForm* makeForm(std::string form_name, std::string target);

};

#endif
