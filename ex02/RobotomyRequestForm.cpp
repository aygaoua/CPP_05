#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45),
                                                    target("default") {

}

RobotomyRequestForm::RobotomyRequestForm(std::string target__) : AForm("RobotomyRequestForm", 72, 45),
                                                                        target(target__) {

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src),
                                                                                        target(src.target) {

}

RobotomyRequestForm&	RobotomyRequestForm::operator =(const RobotomyRequestForm& b) {

    if (this == &b)
        return (*this);
    AForm::operator=(b);
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {

}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {

    AForm::execute(executor);
    std::cout << "zzzgrrrvrrrbzz ..." << std::endl;
    if (system("say -v Zosia \"zzzgrrrvrrrbzz\"") == 0)
        std::cout << "zzzgrrrvrrrbzz ..." << std::endl;
    std::srand(std::time(0));
    if (std::rand() % 2)
        std::cout << "`" << target << "` has been robotomized successfully !" << std::endl;
    else
        std::cout << "`" << target << "` robotomization has failed !" << std::endl;
}
