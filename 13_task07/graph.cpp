#include <algorithm>
#include <queue>
#include "graph.hpp"
#include "../util.hpp"

namespace with_list_task07
{
	namespace aisp
	{
		graph::graph(int node_number)
				: edges_(node_number)
		{}

		void graph::add_branch(int i, int j)
		{
			AISP_ASSERT(i >= 0 && i < number_of_nodes(), "Node is not in range");
			AISP_ASSERT(j >= 0 && j < number_of_nodes(), "Node is not in range");

			edges_[i].push_back(j);
		}


		int graph::number_of_nodes() const
		{
			return edges_.size();
		}

		const std::list<int> &graph::get_neighbours(int i) const
		{
			AISP_ASSERT(i >= 0 && i < number_of_nodes(), "Node is not in range");
			return edges_[i];
		}

		int bfs(const aisp::graph &g, int start_node, int end_node)
		{
			std::queue<std::pair<int, int>> node_queue;
			std::vector<bool> marked(g.number_of_nodes(), false);
			std::pair<int, int> curr_node;
			int min_length = INT32_MAX;

			node_queue.push(std::make_pair(start_node, 1));
			marked[start_node] = true;

			while (!node_queue.empty())
			{
				curr_node = node_queue.front();
				node_queue.pop();

				for (auto &&it : g.get_neighbours(curr_node.first))
				{
					if(it == end_node)
					{
						if(curr_node.second < min_length)
						{
							min_length = curr_node.second;
						}
					}
					if (!marked[it])
					{
						node_queue.push(std::make_pair(it, curr_node.second+1));
						marked[it] = true;
					}
				}
			}
			return min_length;
		}

		graph load_graph_list()
		{
			int n;
			std::cout << "Input number of nodes: ";
			std::cin >> n;

			graph g(n);

			int m;
			int k;

			for (int i = 0; i < n; ++i)
			{
				std::cout << "Number of neighbours for node " << i << " : ";
				std::cin >> m;
				std::cout << "Input neighbours for node " << i << ":" << std::endl;

				for (int j = 0; j < m; ++j)
				{
					std::cin >> k;
					g.add_branch(i, k);
				}
			}

			return g;
		}
	}
}
