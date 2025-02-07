
#pragma once
#include <iostream>
#include <string>
#include <exception>


class Bureaucrat{
    private:
        std::string const name;
        int grade;
    public:
    /*----------------------- Orthodox Canonical Form -----------------------*/
		Bureaucrat		();
		Bureaucrat		(Bureaucrat const & src);
		Bureaucrat&		operator =(const Bureaucrat& b);
		virtual 	~Bureaucrat();
	/*-----------------------------------------------------------------------*/

    /*----------------------- public member functions -----------------------*/
        std::string getName();
        std::string getGrade();
        void increment(Bureaucrat &bureaucrat);
        void decrement(Bureaucrat &bureaucrat);
	/*-----------------------------------------------------------------------*/
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj);