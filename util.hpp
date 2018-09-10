#ifndef UTIL_HPP_WQ63GFKH
#define UTIL_HPP_WQ63GFKH

#include <cstdlib>
#include <iostream>

#define AISP_ASSERT2(expr, msg)\
	aisp::assert_impl(__FILE__, __LINE__, (expr), (msg))
#define AISP_ASSERT3(expr, msg, exit_code)\
	aisp::assert_impl(__FILE__, __LINE__, (expr), (msg), (exit_code))

#define AISP_ASSERT_OVERIDE(_1, _2, _3,NAME, ...) NAME
#define AISP_ASSERT(...)\
	AISP_ASSERT_OVERIDE(__VA_ARGS__, AISP_ASSERT3, AISP_ASSERT2, 1, 0)(__VA_ARGS__)


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
