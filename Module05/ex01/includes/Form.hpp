#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

class	Bureaucrat;

class	Form
{
	public:
		Form();
		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		Form(const Form& copy);
		Form&	operator=(const Form& other);
		~Form();

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

		const std::string&		getName() const;
		bool					isSigned() const;
		int						getGradeToSign() const;
		int						getGradeToExecute() const;
		void					beSigned(Bureaucrat& bureaucrat);
	private:
		const std::string		_name;
		bool					_isSigned;
		const int				_gradeToSign;
		const int				_gradeToExecute;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif