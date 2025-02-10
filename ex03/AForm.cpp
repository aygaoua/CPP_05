#include "AForm.hpp"

AForm::AForm		(): name("Default name"), 
                    is_signed(false),
                    required_to_sign(10),
                    required_to_execute(10){

}

AForm::~AForm(){

}

AForm::AForm(AForm const & src): name(src.name) ,
                                is_signed(src.is_signed),
                                required_to_sign(src.required_to_sign),
                                required_to_execute(src.required_to_execute){

}


AForm&		AForm::operator=(const AForm& b) {

    if (this == &b)
        return (*this);
    this->is_signed = b.is_signed;
    return (*this);
}

AForm::AForm  (std::string name__, int grade_to_sign, int grade_to_ex): name(name__), 
                                                                        required_to_sign(grade_to_sign),
                                                                        required_to_execute(grade_to_ex){

    if (this->get_required_to_execute() < 1 || this->get_required_to_sign() < 1)
        throw GradeTooHighException();
    else if (this->get_required_to_execute() > 150 || this->get_required_to_sign() > 150)
        throw GradeTooLowException();
}

std::string AForm::getName() const {

    return (this->name);
}

bool    AForm::get_is_signed() const {

    return (this->is_signed);
}

int AForm::get_required_to_execute() const {

    return (this->required_to_execute);
}

int AForm::get_required_to_sign() const {

    return (this->required_to_sign);
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {

    if (bureaucrat.getGrade() <= this->get_required_to_sign())
        this->is_signed = true;
    else
        throw GradeTooLowException();
}

std::ostream&	        operator<<(std::ostream& os, const AForm& obj){

    os << "| " << obj.getName() << ", grade required to signed: `" << obj.get_required_to_sign() \
        << "`, grade required to execute: `" << obj.get_required_to_execute() << "` " << (obj.get_is_signed() ? "and is a singed form " : "and is not a signed form ") << "|";
    return os;
}

void        AForm::execute(Bureaucrat const & executor) const{

    if (executor.getGrade() > get_required_to_execute())
        throw GradeTooLowException();
    if (!get_is_signed())
        throw FormNotSignedException();
}

const char* AForm::GradeTooHighException::what() const throw(){

	return "The Grade is Too High !";
}

const char* AForm::GradeTooLowException::what() const throw(){

	return "The Grade is Too Low !";
}

const char* AForm::FormNotSignedException::what() const throw(){

    return "Form is not signed !";
}
