#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat b1("B1", 1);
        ShrubberyCreationForm f1("F1");
        RobotomyRequestForm f2("F2");
        PresidentialPardonForm f3("F3");

        b1.signForm(f1);
        std::cout << "\n***************\n" << std::endl;
        b1.executeForm(f1);
        std::cout << "\n***************\n" << std::endl;
        b1.executeForm(f2);
        std::cout << "\n***************\n" << std::endl;
        b1.signForm(f2);
        std::cout << "\n***************" << std::endl;
        b1.executeForm(f2);
        std::cout << "\n***************\n" << std::endl;
        b1.signForm(f3);
        std::cout << "\n***************\n" << std::endl;
        b1.executeForm(f3);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}