
#pragma once
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat{
    private:
        std::string const   name;
        int                 grade;
    public:
    /*----------------------- Orthodox Canonical Form -----------------------*/
		Bureaucrat		();
		Bureaucrat		(std::string name__, int grade__);
		Bureaucrat		(Bureaucrat const & src);
		Bureaucrat&		operator =(const Bureaucrat& b);
		~Bureaucrat();
	/*-----------------------------------------------------------------------*/

    /*----------------------- public member functions -----------------------*/
        std::string     getName() const;
        int             getGrade() const;
        void            increment(int grades);
        void            decrement(int grades);
	/*-----------------------------------------------------------------------*/

    /*----------------------- exceptions for the ex00 -----------------------*/
        class GradeTooHighException : public std::exception{
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception{
                const char* what() const throw();
        };
	/*-----------------------------------------------------------------------*/
};

std::ostream&	        operator<<(std::ostream& os, const Bureaucrat& obj);
