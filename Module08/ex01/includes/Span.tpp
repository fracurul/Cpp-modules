#ifndef SPAN_TPP
#define SPAN_TPP

template<typename Iterator>
void	Span::addNumberLoop(Iterator begin, Iterator end)
{
	for (Iterator it = begin; it != end; ++it)
		addNumber(*it);
}

#endif
