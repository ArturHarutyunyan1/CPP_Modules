#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _sign;
        const int _exec;
    public:
        AForm();
        AForm(const std::string name, bool isSigned, const int sign, const int exec);
        AForm(const AForm &copy);
        AForm &operator=(const AForm &copy);
        virtual ~AForm();
        std::string getName() const;
        bool getStatus() const;
        void setStatus(bool status);
        int getSign() const;
        int getExec() const;
        void beSigned(Bureaucrat b);
        virtual void execute(Bureaucrat const &executor) const = 0;
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
        class UnsignedFormException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &o, AForm &f);

#endif