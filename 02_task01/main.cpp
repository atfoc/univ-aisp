#include <iostream>
#include <list>
#include <algorithm>


int main()
{
	std::list<int> l{1,2,3,4,5,6,7,8,9};
	std::list<int> l1(l);

	for(auto it = l.begin(), end = l.end(); it != end;)
	{
		if(*it % 2 == 0)
		{
			it = l.erase(it);
		}
		else
		{
			++it;
		}
	}


	for(auto&& it : l)
	{
		std::cout << it << " ";
	}

	std::cout << std::endl;

	/*More fun way*/
	
	std::remove_if(l1.begin(), l1.end(), [](const auto &x)
			{
				return x % 2 == 0; 
			});

	for(auto&& it : l)
	{
		std::cout << it << " ";
	}

	std::cout << std::endl;

}
