#include <iostream>
#include "graph.hpp"

using namespace with_list_task06;

int main()
{
	int n;
	int start_node;
	int end_node;

	aisp::graph g = aisp::load_graph_list();

	std::cout << "start node: ";
	std::cin >> start_node;
	std::cout << "end node: ";
	std::cin >> end_node;

	std::cout << aisp::bfs(g,start_node, end_node) << std::endl;
	return 0;
}
