#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
}

Intern::~Intern() {
}

Intern::Intern(Intern const & src) {
    *this = src;
}

Intern& Intern::operator=(const Intern& b) {
    if (this == &b)
        return (*this);
    return (*this);
}

AForm* Intern::makeShrubberyCreationForm(std::string target) {
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeRobotomyRequestForm(std::string target) {
    return (new RobotomyRequestForm(target));
}

AForm* Intern::makePresidentialPardonForm(std::string target) {
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string form_name, std::string target) {
    int i = ((form_name == "shrubbery creation") + 
        (form_name == "robotomy request") * 2 + \
        (form_name == "presidential pardon") * 3) - 1;

    AForm *(Intern::*form[3]) (std::string) = {
        &Intern::makeShrubberyCreationForm,
        &Intern::makeRobotomyRequestForm,
        &Intern::makePresidentialPardonForm
    };

    if (i == -1)
        throw FormNotFoundException();
    std::cout << "Intern creates " << form_name << " form" << std::endl;
    return (this->*form[i])(target);
}

const char* Intern::FormNotFoundException::what() const throw() {
    return ("Error: Form not found");
}
