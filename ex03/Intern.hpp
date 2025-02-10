#pragma once
#include <iostream>
#include <string>
#include "AForm.hpp"


class Intern {
    private:
        AForm* makeShrubberyCreationForm(std::string target);
        AForm* makeRobotomyRequestForm(std::string target);
        AForm* makePresidentialPardonForm(std::string target);
    public:
    /*----------------------- Orthodox Canonical AForm -----------------------*/
        Intern();
        ~Intern();
        Intern(Intern const & src);
        Intern& operator=(const Intern& b);
    /*-----------------------------------------------------------------------*/

    /*----------------------- public member functions -----------------------*/
        AForm* makeForm(std::string form_name, std::string target);
        class FormNotFoundException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
    /*-----------------------------------------------------------------------*/
};