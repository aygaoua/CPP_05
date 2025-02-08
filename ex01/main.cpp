#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b("AYGAOUA", 3);
        std::cout << b << std::endl;

        Form f("cdd", 1, 6);
        b.signForm(f);
        b.increment(2);
        b.signForm(f);

    }
    catch(const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "\n      ******************\n" << std::endl;
        Bureaucrat b("AYGAOUA1", 3);
        Bureaucrat c;
        c = b;
        std::cout << b << std::endl;
        std::cout << c << std::endl;

        c.increment(5);
        b.increment(5);
        std::cout << c << std::endl;
        std::cout << b << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "\n      ******************\n" << std::endl;
        Bureaucrat b("AYGAOUA2", 15);
        Bureaucrat c;
        b.decrement(136);
        std::cout << b << std::endl;
        std::cout << c << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}