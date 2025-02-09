#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137),
                                                    target("default") {

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target__) : AForm("ShrubberyCreationForm", 145, 137),
                                                                        target(target__) {

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src),
                                                                                        target(src.target) {

}

ShrubberyCreationForm&	ShrubberyCreationForm::operator =(const ShrubberyCreationForm& b) {

    if (this == &b)
        return (*this);
    AForm::operator=(b);
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {

    AForm::execute(executor);
    std::ofstream chajara(target + "_shrubbery");

    if (!chajara.is_open())
        throw std::runtime_error("Error: could not open file");
    chajara << "      /\\      " << std::endl;
    chajara << "     /\\#\\     " << std::endl;
    chajara << "    /\\|\\#\\    " << std::endl;
    chajara << "   /#/\\/\\/\\   " << std::endl;
    chajara << "  /\\|\\/\\#\\/\\  " << std::endl;
    chajara << " /\\#\\/\\#\\/\\/\\ " << std::endl;
    chajara << "/\\|\\/\\/*/\\/|/\\" << std::endl;
    chajara << "      ||      " << std::endl;
    chajara << "      ||      " << std::endl;
    chajara << "      ||      " << std::endl;
    chajara << std::endl;

}
