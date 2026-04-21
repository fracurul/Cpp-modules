#include "RPN.hpp"

float	RPN::_applyOp(float a, float b, char op)
{

	if (op == '+')
		return (a + b);
	else if (op == '-')
		return (a - b);
	else if (op == '*')
		return (a * b);
	else
		return (a / b);
}

bool	RPN::_isOp(const std::string& str)
{
	return (str == "+" || str == "-" || str == "*" || str == "/");
}

bool	RPN::_isNum(const std::string& str)
{
	if (str.empty())
		return (false);
	try
	{
		std::stringstream	ss(str);
		float	num;
		return (ss >> num && ss.eof());
	}
	catch (const std::invalid_argument& e)
	{
		return (false);
	}
	catch (const std::out_of_range& e)
	{
		return (false);
	}
}


RPN::RPN() {}

RPN::RPN(const RPN& copy) : _stack(copy._stack) {}

RPN&	RPN::operator=(const RPN& copy)
{
	if (this != &copy)
		_stack = copy._stack;
	return (*this);
}

RPN::~RPN() {}


float	RPN::calculate(const std::string& exp)
{

	std::istringstream	iss(exp);
	std::string			token;
	float				n1;
	float				n2;

	while (iss >> token)
	{
		if (_isNum(token))
		{
			std::stringstream	ss(token);
			float	num;
			ss >> num;
			_stack.push(num);
		}
		else if (_isOp(token))
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error");
			n2 = _stack.top();
			_stack.pop();
			n1 = _stack.top();
			_stack.pop();
			_stack.push(_applyOp(n1, n2, token[0]));
		}
		else
		{
			throw std::runtime_error("Error");
		}
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error");
	return (_stack.top());

}