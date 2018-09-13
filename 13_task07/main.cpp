#include <iostream>
#include "graph.hpp"

using namespace with_list_task07;


int main()
{
	aisp::graph g = aisp::load_graph_list();

	int start_node;
	int end_node;
	std::cin >> start_node >> end_node;

	std::cout << aisp::bfs(g, start_node, end_node);

	return 0;
}
