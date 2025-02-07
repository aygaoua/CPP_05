#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b("AYGAOUA", 13);
        b.increment(12);
        std::cout << b << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}