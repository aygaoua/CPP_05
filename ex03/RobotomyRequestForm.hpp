#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include "AForm.hpp"

class AForm;

class RobotomyRequestForm : public AForm{
    private:
        std::string const target;
    public:
    /*----------------------- Orthodox Canonical Form -----------------------*/
        RobotomyRequestForm     ();
        RobotomyRequestForm     (RobotomyRequestForm const& src);
        RobotomyRequestForm&    operator=(const RobotomyRequestForm& b);
        ~RobotomyRequestForm    ();
    /*-----------------------------------------------------------------------*/

    /*----------------------- public member functions -----------------------*/
    RobotomyRequestForm         (std::string target__);
    void                        execute(Bureaucrat const & executor) const;
    /*-----------------------------------------------------------------------*/
};
