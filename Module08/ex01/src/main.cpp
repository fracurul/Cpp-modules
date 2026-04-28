#include "Span.hpp"

int main(void)
{
	srand(time(NULL));


	std::cout << "=== Subject test ===" << std::endl;
	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;


	std::cout << "== Test 1: small quantity ==" << std::endl;
	Span span1(10);
	std::vector<int> vec1;
	for (int i = 0; i < 10; i++)
		vec1.push_back(rand() % 100);

	span1.addNumberLoop(vec1.begin(), vec1.end());
	std::cout << "Shortest span: " << span1.shortestSpan() << std::endl;
	std::cout << "Longest span: " << span1.longestSpan() << std::endl;


	std::cout << "\n== Test 2: 10,000 aleatory numbers ==" << std::endl;
	Span span2(10000);
	std::vector<int> vec2;
	for (int i = 0; i < 10000; i++)
		vec2.push_back(rand());

	span2.addNumberLoop(vec2.begin(), vec2.end());
	std::cout << "Shortest span: " << span2.shortestSpan() << std::endl;
	std::cout << "Longest span: " << span2.longestSpan() << std::endl;


	std::cout << "\n== Test 3: Exception (less than 2 numbers) ==" << std::endl;
	Span span3(5);
	span3.addNumber(5);
	try
	{
		span3.shortestSpan();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception captured: " << e.what() << std::endl;
	}

	std::cout << "\n== Test 4: Exception (Full Span) ==" << std::endl;
	Span span4(3);
	span4.addNumber(1);
	span4.addNumber(2);
	span4.addNumber(3);
	try
	{
		span4.addNumber(4);
	}
	catch (std::out_of_range &e)
	{
		std::cout << "Exception captured: " << e.what() << std::endl;
	}

	std::cout << "\n=== OCF TEST ===" << std::endl;
	std::cout << "\n== Test 1: Copy Constructor ==" << std::endl;
	Span span5(5);
	span5.addNumber(10);
	span5.addNumber(20);
	span5.addNumber(30);
	span5.addNumber(40);
	span5.addNumber(50);
	Span span5Copy(span5);
	std::cout << "Original - Shortest: " << span5.shortestSpan() << ", Longest: " << span5.longestSpan() << std::endl;
	std::cout << "Copy - Shortest: " << span5Copy.shortestSpan() << ", Longest: " << span5Copy.longestSpan() << std::endl;

	std::cout << "\n== Test 2: Assignment Operator ==" << std::endl;
	Span span6(3);
	span6.addNumber(100);
	span6.addNumber(200);
	span6.addNumber(300);
	Span span6Assigned(10);
	span6Assigned = span6;
	std::cout << "Assigned - Shortest: " << span6Assigned.shortestSpan() << ", Longest: " << span6Assigned.longestSpan() << std::endl;

	return (0);
}
