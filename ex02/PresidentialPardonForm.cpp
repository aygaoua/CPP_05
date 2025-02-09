#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5),
                                                    target("default") {

}

PresidentialPardonForm::PresidentialPardonForm(std::string target__) : AForm("PresidentialPardonForm", 25, 5),
                                                                        target(target__) {

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm(src),
                                                                                        target(src.target) {

}

PresidentialPardonForm&	PresidentialPardonForm::operator =(const PresidentialPardonForm& b) {

    if (this == &b)
        return (*this);
    AForm::operator=(b);
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {

}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {

    AForm::execute(executor);
    std::cout << "`" << target << "` has been pardoned by Zafod Beeblebrox !!" << std::endl;
}
