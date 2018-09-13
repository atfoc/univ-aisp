#include <iostream>
#include <set>

int main()
{
	int n0, n1;
	std::string s;
	std::set<std::string> set;

	std::cout << "Insert n0: ";
	std::cin >> n0;

	for(int i = 0; i < n0; ++i)
	{
		std::cin >> s;
		set.insert(s);
	}

	std::cout << "Insert n1: ";
	std::cin >> n1;


	for(int i = 0; i < n1; ++i)
	{
		std::cin >> s;
		auto it = set.insert(s);
		if(it.second)
		{
			std::cout << "In B not in A: ";
			std::cout << s << std::endl;
		}
	}


	return 0;
}