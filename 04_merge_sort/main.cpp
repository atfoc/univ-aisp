#include <iostream>
#include <vector>
#include "../util.hpp"


void merge_sort(std::vector<int> &v, int l, int r);
void merge_sort(std::vector<int> &v);

int main()
{

    std::vector<int> v;
    int tmp;
    int n{5};
    //while(true)
    for(int i = 0; i < n; ++i)
    {
        std::cin >> tmp;
        if(!std::cin)
        {
           break;
        }

        v.push_back(tmp);
    }

    merge_sort(v);

    for(auto &&it : v)
    {
        std::cout << it << " ";
    }

    std::cout << std::endl;

    return 0;
}

void merge_sort(std::vector<int> &v, int l, int r)
{
    static std::vector<int> tmp(v.size());

    if(l >= r)
    {
        return ;
    }

    /*Middle*/
    int m = l + (r-l)/2;


    merge_sort(v, l, m);
    merge_sort(v, m+1, r);

    int tmp_it{0};
    int l_it{l};
    int r_it{m+1};

    for(; l_it <= m && r_it <= r; ++tmp_it)
    {
        if(v[l_it] <= v[r_it])
        {
            tmp[tmp_it] = v[l_it];
            ++l_it;
        }
        else
        {
            tmp[tmp_it] = v[r_it];
            ++r_it;
        }
    }

    while(l_it <= m)
    {
        tmp[tmp_it] = v[l_it];
        ++tmp_it;
        ++l_it;
    }

    while(r_it <= r)
    {
        tmp[tmp_it] = v[r_it];
        ++tmp_it;
        ++r_it;
    }

    for(int i = l, tmp_it = 0; i <= r; ++i, ++tmp_it)
    {
        v[i] = tmp[tmp_it];
    }
}

void merge_sort(std::vector<int> &v)
{
    merge_sort(v, 0, v.size()-1);
}

