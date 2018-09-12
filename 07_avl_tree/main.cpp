#include <iostream>
#include "avl.hpp"


int main()
{
	int n;
	aisp::avl set;

	std::cout << "Insert n: ";
	std::cin >> n;

	int tmp;
	for(int  i = 0; i < n; ++i)
	{
		std::cin >> tmp;
		set.insert(tmp);
	}

	aisp::avl_detail::preorder(set, [](auto &&it){std::cout << it << std::endl;});

}
