#include <iostream>
#include "graph.hpp"

using namespace with_matrix;

int main()
{

	aisp::graph g(aisp::load_graph_matrix());


	std::cout << "=================DFS=================" << std::endl;
	aisp::dfs(g, 4);
	std::cout << "=================DFS=================" << std::endl;
	std::cout << "=================BFS=================" << std::endl;
	aisp::bfs(g, 4);
	std::cout << "=================BFS=================" << std::endl;

    return 0;
}