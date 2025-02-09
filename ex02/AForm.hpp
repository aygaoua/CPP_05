#pragma once
#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        std::string const   name;
        bool                is_signed;
        int const           required_to_sign;
        int const           required_to_execute;
    public:
    /*----------------------- Orthodox Canonical AForm -----------------------*/
		AForm		        ();
		AForm		        (AForm const & src);
		AForm&		        operator =(const AForm& b);
		~AForm();
	/*-----------------------------------------------------------------------*/

    /*----------------------- public member functions -----------------------*/
		AForm		        (std::string name__, int grade_to_sign, int grade_to_ex);
        std::string         getName() const;
        bool                get_is_signed() const;
        int                 get_required_to_sign() const;
        int                 get_required_to_execute() const;
        void                beSigned(const Bureaucrat &bureaucrat);
        virtual void        execute(Bureaucrat const & executor) const = 0;
	/*-----------------------------------------------------------------------*/

    /*----------------------- exceptions for the ex01 -----------------------*/
        class GradeTooHighException : public std::exception{
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception{
                const char* what() const throw();
        };
        class FormNotSignedException : public std::exception{
                const char* what() const throw();
        };
    /*-----------------------------------------------------------------------*/

};

std::ostream&	        operator<<(std::ostream& os, const AForm& obj);
