#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class	Bureaucrat;

class	AForm
{
	public:
		AForm();
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& copy);
		AForm&	operator=(const AForm& other);
		virtual ~AForm();

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

		class	FormNotSignedException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

		const std::string&		getName() const;
		bool					isSigned() const;
		int						getGradeToSign() const;
		int						getGradeToExecute() const;
		void					beSigned(Bureaucrat& bureaucrat);
		
		void					execute(Bureaucrat const & executor) const;
		virtual void			executeAction() const = 0;
	private:
		const std::string		_name;
		bool					_isSigned;
		const int				_gradeToSign;
		const int				_gradeToExecute;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif