#include <iostream>
#include <vector>


void solve(unsigned n);
void solve(unsigned n, std::vector<int> &elements, int i, int sum);

int main()
{
	unsigned n;

	std::cout << "Insert n: ";
	std::cin >> n;

	solve(n);
}

void solve(unsigned n)
{
	std::vector<int> elements(n, 0);
	solve(n, elements, 0, 0);
}

void solve(unsigned n, std::vector<int> &elements, int i, int sum)
{
	if(sum > 3*n)
	{
		return;
	}

	if(i == n)
	{
		for(auto &&it : elements)
		{
			std::cout << it << " ";
		}
		std::cout << std::endl;
	}


	for(int j = 0; j < 10; ++j)
	{
		if(i == 0)
		{
			elements[i] = j;
			solve(n, elements, i+1, sum + j);
		}
		else
		{
			if(j % 2 == 0 && elements[i-1] % 2 == 0)
			{
				continue;
			}
			elements[i] = j;
			solve(n, elements, i+1, sum + j);
		}

	}

}
