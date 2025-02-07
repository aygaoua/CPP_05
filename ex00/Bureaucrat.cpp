#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat (): name("default name") {

}

Bureaucrat::Bureaucrat (std::string name__, int grade__): name(name__), grade(grade__) {

}

Bureaucrat::Bureaucrat (Bureaucrat const & src): name(src.name), grade(src.grade) {

}

Bureaucrat::~Bureaucrat() {

}

Bureaucrat&		Bureaucrat::operator=(const Bureaucrat& b) {

    this->grade = b.grade;
    return (*this);
}

std::string     Bureaucrat::getName() const{

    return (this->name);
}

int Bureaucrat::getGrade() const{

    return (this->grade);
}

void            Bureaucrat::increment(int grades){

    if (getGrade()  - grades < 1)
    {
        throw(GradeTooHighException());
    }
    grade -= grades;
}

void            Bureaucrat::decrement(int grades){

    if (getGrade() + grades > 150)
    {
        throw(GradeTooLowException());
    }
    grade += grades;
}

std::ostream&	        operator<<(std::ostream& os, const Bureaucrat& obj){

    os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){

	return "The Grade is Too High!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){

	return "The Grade is Too Low!";
}