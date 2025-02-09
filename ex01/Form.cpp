#include "Form.hpp"

Form::Form		(): name("Default name"), 
                    is_signed(false),
                    required_to_sign(10),
                    required_to_execute(10){

}

Form::~Form(){

}

Form::Form(Form const & src): name(src.name) ,
                                is_signed(src.is_signed),
                                required_to_sign(src.required_to_sign),
                                required_to_execute(src.required_to_execute){

}


Form&		Form::operator=(const Form& b) {

    if (this == &b)
        return (*this);
    this->is_signed = b.is_signed;
    return (*this);
}

Form::Form  (std::string name__, int grade_to_sign, int grade_to_ex): name(name__), 
                                                                        required_to_sign(grade_to_sign),
                                                                        required_to_execute(grade_to_ex){

    if (this->get_required_to_execute() < 1 || this->get_required_to_sign() < 1)
        throw GradeTooHighException();
    else if (this->get_required_to_execute() > 150 || this->get_required_to_sign() > 150)
        throw GradeTooLowException();
}

std::string Form::getName() const {

    return (this->name);
}

bool    Form::get_is_signed() const {

    return (this->is_signed);
}

int Form::get_required_to_execute() const {

    return (this->required_to_execute);
}

int Form::get_required_to_sign() const {

    return (this->required_to_sign);
}

void Form::beSigned(const Bureaucrat &bureaucrat) {

    if (bureaucrat.getGrade() <= this->get_required_to_sign())
        this->is_signed = true;
    else
        throw GradeTooLowException();
}

std::ostream&	        operator<<(std::ostream& os, const Form& obj){

    os << "| " << obj.getName() << ", grade required to signed: `" << obj.get_required_to_sign() \
        << "`, grade required to execute: `" << obj.get_required_to_execute() << "` |";
    return os;
}

const char* Form::GradeTooHighException::what() const throw(){

	return "The Grade is Too High !";
}

const char* Form::GradeTooLowException::what() const throw(){

	return "The Grade is Too Low !";
}
