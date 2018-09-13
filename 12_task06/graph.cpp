#include <algorithm>
#include <queue>
#include "graph.hpp"
#include "../util.hpp"

namespace with_list_task06
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
			std::queue<int> node_queue;
			std::vector<bool> marked(g.number_of_nodes(), false);
			int curr_node;
			int sum = 0;

			node_queue.push(start_node);
			marked[start_node] = true;

			while (!node_queue.empty())
			{
				curr_node = node_queue.front();
				node_queue.pop();

				for (auto &&it : g.get_neighbours(curr_node))
				{
					if(it == end_node)
					{
						++sum;
					}
					if (!marked[it])
					{
						node_queue.push(it);
						marked[it] = true;
					}
				}
			}
			return sum;
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
