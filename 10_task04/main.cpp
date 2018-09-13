#include <iostream>
#include <vector>

int solve(const std::vector<int> &v);
void solve(const std::vector<int> &v, int l, int r, int &sum);

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> v(n);

	for(int i = 0; i < n; ++i)
	{
		std::cin >> v[i];
	}

	std::cout << solve(v);


}

int solve(const std::vector<int> &v)
{
	int sum = 0;

	solve(v, 0, v.size() - 1, sum);

	return sum;
}

void solve(const std::vector<int> &v, int l, int r, int &sum)
{
	if(l == r)
	{
		sum += v[l];
		return;
	}
	if(l > r)
	{
		return ;
	}
	int middle = l + (r-l)/2;
	solve(v, l, middle, sum);
	solve(v, middle+1, r,sum);
}
