#ifndef FORM
#define FORM

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _sign;
        const int _exec;
    public:
        Form();
        Form(std::string name, int sign, int exec);
        Form(const Form &copy);
        Form &operator=(const Form &copy);
        ~Form();
        std::string getName() const;
        bool getStatus() const;
        void setStatus(bool status);
        int getSign() const;
        int getExec() const;
        void beSigned(Bureaucrat b);
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &o, Form &f);

#endif