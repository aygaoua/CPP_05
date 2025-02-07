#pragma once
#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Form {
    private:
        std::string const   name;
        bool                is_signed;
        int const           required_to_sign;
        int const           required_to_execute;
    public:
    /*----------------------- Orthodox Canonical Form -----------------------*/
		Form		();
		Form		(Form const & src);
		Form&		operator =(const Form& b);
		~Form();
	/*-----------------------------------------------------------------------*/

    /*----------------------- exceptions for the ex01 -----------------------*/
		Form		(std::string name__, int grade__);
        class GradeTooHighException : public std::exception{
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception{
                const char* what() const throw();
        };
    /*-----------------------------------------------------------------------*/

};

std::ostream&	        operator<<(std::ostream& os, const Form& obj);
