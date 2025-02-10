#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

// int main()
// {
//     try
//     {
//         Intern someRandomIntern;
//         AForm* rrf;
//         rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");

//         delete rrf;
//     }
//     catch (const std::exception& e)
//     {
//         std::cout << e.what() << std::endl;
//     }
//     return 0;
// }

void ff (void) {
    std::cout << "Exiting program" << std::endl;
}

int main()
{
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);
    Bureaucrat clerk("Clerk", 70);
    atexit(ff);
    try {
        std::cout << "\n=== Testing invalid form ===\n" << std::endl;
        AForm* invalid = someRandomIntern.makeForm("invalid form", "test");
        if (invalid == NULL)
            std::cout << "Form creation failed as expected" << std::endl;
        delete invalid;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    try{
        AForm* scf = someRandomIntern.makeForm("shrubbery creation", "garden");
        std::cout << *scf << std::endl;
        clerk.signForm(*scf);
        clerk.executeForm(*scf);
        std::cout << *scf << std::endl;
        delete scf;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    try{
        AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Alice");
        std::cout << "\n" << *ppf << std::endl;
        boss.signForm(*ppf);
        boss.executeForm(*ppf);
        std::cout << *ppf << std::endl;
        delete ppf;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    try {
        // Test Intern creating different forms
        AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << "\n" << *rrf << std::endl;
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        boss.executeForm(*rrf); // Execute twice to see different results
        std::cout << *rrf << std::endl;
        delete rrf;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}