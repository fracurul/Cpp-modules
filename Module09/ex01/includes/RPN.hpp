#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>
#include <stack>
#include <sstream>

class	RPN
{
	private:
		std::stack<float>	_stack;

		float	_applyOp(float a, float b, char op);
		bool	_isOp(const std::string& str);
		bool	_isNum(const std::string& str);
	public:
		RPN();
		RPN(const RPN& copy);
		RPN&	operator=(const RPN& copy);
		~RPN();

		float	calculate(const std::string& exp);
};

#endif