#include <iostream>
#include "list.hpp"



int main()
{
	aisp::list l;

	for(int i = 0; i < 10; ++i)
	{
		l.push_front(i);
	}
	std::cout << l << std::endl;

	l.pop_back();
	std::cout << l << std::endl;

	l.pop_front();
	std::cout << l << std::endl;

	l.clear();
	std::cout << l << std::endl;

	for(int i = 10; i < 20; ++i)
	{
		l.push_back(i);
	}
	std::cout << l << std::endl;

	while(!l.empty())
	{
		l.pop_back();
		std::cout << l << std::endl;
	}

}

