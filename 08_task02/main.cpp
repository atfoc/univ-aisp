#include <iostream>

unsigned solve(unsigned n);
void solve(unsigned n, unsigned curr, unsigned &res, unsigned last);


int main()
{
	unsigned n;
	std::cout << "Input n: ";
	std::cin >> n;

	std::cout << "Solution is: " << solve(n) << std::endl;

}

unsigned solve(unsigned n)
{
	unsigned res = 0;
	solve(n, 0, res, 1);
	return res;
}

void solve(unsigned n, unsigned curr, unsigned &res, unsigned last)
{
	if(curr > n)
	{
		return ;
	}
	for(int i = last; i <= 9; i += 2)
	{
		if(curr + i > n)
		{
			return;
		}

		if(curr + i == n)
		{
			++res;
			return ;
		}

		solve(n , curr + i, res, i);

	}
}
