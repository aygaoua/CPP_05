#pragma once
#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm{
    private:
        std::string const   target;
    public:
    /*----------------------- Orthodox Canonical Form -----------------------*/
        PresidentialPardonForm		();
        PresidentialPardonForm		(PresidentialPardonForm const& src);
        PresidentialPardonForm&		operator =(const PresidentialPardonForm& b);
        ~PresidentialPardonForm();
    /*-----------------------------------------------------------------------*/

    /*----------------------- public member functions -----------------------*/
        PresidentialPardonForm		(std::string target__);
        void                        execute(Bureaucrat const & executor) const;
    /*-----------------------------------------------------------------------*/
};
