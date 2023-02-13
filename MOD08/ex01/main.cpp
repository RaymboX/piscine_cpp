#include "Span.hpp"

int main()
{
	std::cout << GREEN << "Pdf example" << COLORDEF << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	std::cout << GREEN << "Adding one more over fixed limit" << COLORDEF << std::endl;
	sp.addNumber(34);

	Span	span2(5);
	std::cout << GREEN << "Trying smallestSpan on empty span" << COLORDEF << std::endl;
	try
	{
		std::cout << span2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED <<  e.what() << '\n' << COLORDEF;
	}
	std::cout << GREEN << "Trying shortestSpan on empty span" << COLORDEF << std::endl;
	try
	{
		std::cout << span2.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED <<  e.what() << '\n' << COLORDEF;
	}

	std::cout << GREEN << "Adding data with an array {3, 100, 2, 45, 0}" << std::endl
					   << "	and using longest and shortest function"	<< COLORDEF << std::endl;
	int arrint[] = {3, 100, 2, 45, 0};
	span2.addContainer(arrint, 5);
	std::cout << "LONGEST: " << span2.longestSpan() << std::endl;
	std::cout << "SHORTEST: "<< span2.shortestSpan() << std::endl;
	
	std::cout << GREEN << "Making error on function assing with negative number" << COLORDEF << std::endl;
	Span	span3(10);
	span3.addContainer(arrint, -2);

	return 0;
}