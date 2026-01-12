#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

// Constructor por defecto
AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
}

// Constructor parametrizado
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

// Constructor de copia
AForm::AForm(const AForm& copy) : _name(copy._name), _isSigned(copy._isSigned),
	_gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
}

// Operador de asignación
AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

// Destructor
AForm::~AForm()
{
	std::cout << "AForm " << this->_name << " destroyed" << std::endl;
}

// Getter para nombre
const std::string& AForm::getName() const
{
	return this->_name;
}

// Getter para isSigned
bool AForm::isSigned() const
{
	return this->_isSigned;
}

// Getter para gradeToSign
int AForm::getGradeToSign() const
{
	return this->_gradeToSign;
}

// Getter para gradeToExecute
int AForm::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

// Método beSigned
void AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_isSigned = true;
}

// Método execute
void AForm::execute(Bureaucrat const & executor) const
{
	if (!this->_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > this->_gradeToExecute)
		throw GradeTooLowException();
	this->executeAction();
}

// Implementación del what() para las excepciones
const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Form grade too high!");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Form grade too low!");
}

const char*	AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed!");
}

// Sobrecarga del operator<<
std::ostream&	operator<<(std::ostream& os, const AForm& form)
{
	os << "AForm " << form.getName() << ", signed: " << (form.isSigned() ? "yes" : "no")
	<< ", grade to sign: " << form.getGradeToSign()
	<< ", grade to execute: " << form.getGradeToExecute();
	return (os);
}
