#include <iostream>
#include "graph_list.hpp"

int main()
{

	aisp::graph_list g(aisp::load_graph_list());


	std::cout << "=================DFS=================" << std::endl;
	aisp::dfs(g, 4);
	std::cout << "=================DFS=================" << std::endl;
	std::cout << "=================BFS=================" << std::endl;
	aisp::bfs(g, 4);
	std::cout << "=================BFS=================" << std::endl;

    return 0;
}