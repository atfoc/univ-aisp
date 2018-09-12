#include <iostream>
#include "graph.hpp"

int main()
{

	aisp::graph g(aisp::load_graph());


	std::cout << "=================DFS=================" << std::endl;
	aisp::dfs(g, 4);
	std::cout << "=================DFS=================" << std::endl;
	std::cout << "=================BFS=================" << std::endl;
	aisp::bfs(g, 4);
	std::cout << "=================BFS=================" << std::endl;

    return 0;
}