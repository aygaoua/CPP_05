#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    Bureaucrat corrector("Corrector", 1);
    Bureaucrat me("Me", 70);

    try {
        std::cout << "\n******* Testing invalid form *******\n" << std::endl;
        AForm* invalid = someRandomIntern.makeForm("invalid form", "test");
        if (invalid == NULL)
            std::cout << "Form creation failed as expected" << std::endl;
        delete invalid;
    }
    catch (std::exception& e) {
        std::cout << "Exception1 caught: " << e.what() << std::endl;
    }

    try{
        std::cout << "\n********* shrubbery creation *******\n" << std::endl;
        AForm* SCF = someRandomIntern.makeForm("shrubbery creation", "test1");
        std::cout << *SCF << std::endl;
        me.signForm(*SCF);
        me.executeForm(*SCF);
        std::cout << *SCF << std::endl;
        delete SCF;
    }
    catch (std::exception& e) {
        std::cout << "Exception2 caught: " << e.what() << std::endl;
    }

    try{
        std::cout << "\n******** presidential pardon *******\n" << std::endl;
        AForm* PPF = someRandomIntern.makeForm("presidential pardon", "test2");
        std::cout << *PPF << std::endl;
        corrector.signForm(*PPF);
        corrector.executeForm(*PPF);
        std::cout << *PPF << std::endl;
        delete PPF;
    }
    catch (std::exception& e) {
        std::cout << "Exception3 caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n********* robotomy request *********\n" << std::endl;
        AForm* RRF = someRandomIntern.makeForm("robotomy request", "test3");
        std::cout << *RRF << std::endl;
        corrector.signForm(*RRF);
        corrector.executeForm(*RRF);
        corrector.executeForm(*RRF);
        std::cout << *RRF << std::endl;
        delete RRF;
    }
    catch (std::exception& e) {
        std::cout << "Exception4 caught: " << e.what() << std::endl;
    }
    std::cout << "\n********** Exiting program **********" << std::endl;
    return 0;
}