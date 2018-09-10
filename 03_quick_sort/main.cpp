#include <iostream>
#include <vector>
#include <iterator>
#include <type_traits>
#include "../util.hpp"

void quick_sort(std::vector<int> &v, int b, int e);
void quick_sort(std::vector<int> &v);

template<typename Random0, typename Random1>
void quick_sort(Random0 b, Random1 e);

int main()
{
	
	std::vector<int> v;
	int x;

	while(true)
	{
		

		std::cin >> x;

		if(!std::cin)
		{
			break;
		}

		v.push_back(x);
	}

	quick_sort(v.begin(), v.end());

	for(auto &&it : v)
	{
		std::cout << it << " ";
	}

	std::cout << std::endl;
}

void quick_sort(std::vector<int> &v, int b, int e)
{
	if(b >= e)
	{
		return ;
	}

	int pivot{b};

	int it = b;
	
	++b;

	while(b <= e)
	{
		if(v[b] <= v[pivot])
		{
			++it;
			std::swap(v[it], v[b]);
		}
		++b;
	}

	std::swap(v[it], v[pivot]);
	quick_sort(v, 0, it-1);
	quick_sort(v, it+1, e);

}

void quick_sort(std::vector<int> &v)
{
	quick_sort(v, 0, v.size()-1);
}

template<typename Random0, typename Random1>
void quick_sort(Random0 b, Random1 e)
{
	static_assert(std::is_same<
			typename std::iterator_traits<Random0>::iterator_category,
			std::random_access_iterator_tag>::value
			, "Random0 has to be random access iterator");

	static_assert(std::is_same<
			typename std::iterator_traits<Random1>::iterator_category,
			std::random_access_iterator_tag>::value
			, "Random1 has to be random access iterator");

	if(std::distance(b, e) <= 0)
	{
		return ;
	}

	auto start(b);
	auto pivot(b);	
	auto it(b);	

	std::advance(b, 1);

	while(b != e)
	{
		if(*b <= *pivot)
		{
			std::advance(it,1);
			std::swap(*it, *b);
		}
		std::advance(b, 1);
	}

	std::swap(*it, *pivot);
	quick_sort(start, it);
	quick_sort(std::next(it), e);
}
