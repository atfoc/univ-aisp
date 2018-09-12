#include <iostream>
#include "graph_matrix.hpp"

int main()
{

	aisp::graph_matrix g(aisp::load_graph_matrix());


	std::cout << "=================DFS=================" << std::endl;
	aisp::dfs(g, 4);
	std::cout << "=================DFS=================" << std::endl;
	std::cout << "=================BFS=================" << std::endl;
	aisp::bfs(g, 4);
	std::cout << "=================BFS=================" << std::endl;

    return 0;
}