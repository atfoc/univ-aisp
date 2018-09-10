#ifndef UTIL_HPP_WQ63GFKH
#define UTIL_HPP_WQ63GFKH

#include <cstdlib>
#include <iostream>

#define assert(expr, msg, ...)\
	aisp::assert_impl(__FILE__, __LINE__, (expr), (msg) __VA_OPT__(,) __VA_ARGS__ )

namespace aisp
{

	inline void assert_impl(	const char *file,
								const int line,
								bool expr,
								const std::string &msg, 
								int exit_code = 1)
	{
		if(!expr)
		{
			std::cerr << "\x1b[31m[" << file << ":" << line << "] ";
			std::cerr  << msg << "\x1b[0m" << std::endl;
			std::exit(exit_code);
		}
	}
}//namespace aisp

#endif /* end of include guard: UTIL_HPP_WQ63GFKH */
