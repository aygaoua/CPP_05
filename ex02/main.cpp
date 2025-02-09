#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat b1("b1", 1);
        ShrubberyCreationForm f1("f1");
        RobotomyRequestForm f2("f2");

        b1.signForm(f1);
        std::cout << "***************" << std::endl;
        b1.executeForm(f2);
        std::cout << "***************" << std::endl;
        b1.signForm(f2);
        // std::cout << "***************" << std::endl;
        // b1.executeForm(f1);
        std::cout << "***************" << std::endl;
        b1.executeForm(f2);

    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}