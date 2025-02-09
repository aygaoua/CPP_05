#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm{
    private:
        std::string const   target;
    public:
    /*----------------------- Orthodox Canonical Form -----------------------*/
        ShrubberyCreationForm		();
        ShrubberyCreationForm		(ShrubberyCreationForm const& src);
        ShrubberyCreationForm&		operator =(const ShrubberyCreationForm& b);
        ~ShrubberyCreationForm();
    /*-----------------------------------------------------------------------*/

    /*----------------------- public member functions -----------------------*/
        ShrubberyCreationForm		(std::string target__);
        void                        execute(Bureaucrat const & executor) const;
    /*-----------------------------------------------------------------------*/
};
