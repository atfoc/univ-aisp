#include <iostream>
#include <queue>
#include "../util.hpp"
#include "graph.hpp"

namespace aisp
{

	graph::graph(int node_number)
		:	edge_matrix_(node_number, std::vector<bool>(node_number, false))
	{}

	void graph::add_branch(int i, int j)
	{
		AISP_ASSERT(i >= 0 && i < number_of_nodes(), "Node is not in range");
		AISP_ASSERT(j >= 0 && j < number_of_nodes(), "Node is not in range");
		edge_matrix_[i][j] = true;
	}

	int graph::get_branch(int i, int j) const
	{
		AISP_ASSERT(i >= 0 && i < number_of_nodes(), "Node is not in range");
		AISP_ASSERT(j >= 0 && j < number_of_nodes(), "Node is not in range");
		return edge_matrix_[i][j];
	}

	int graph::number_of_nodes() const
	{
		return edge_matrix_.size();
	}



	std::ostream &operator<<(std::ostream &os, const graph &g)
	{
		int n{g.number_of_nodes()};

		for (int i = 0; i < n; ++i)
		{
			os << i << std::endl;
			for(int j = 0; j < n; ++j)
			{
				if(g.get_branch(i, j))
				{
					os << j << " ";
				}
			}
			os<< "------------------" << std::endl;
		}
		return os;
	}

	void dfs(const graph &g, int node, std::vector<bool> &marked)
	{
		int n{g.number_of_nodes()};

		std::cout << "Dolazna numeracija: " << node << std::endl;
		marked[node] = true;

		for(int i = 0; i < n; ++i)
		{
			if(g.get_branch(node, i) && !marked[i])
			{
				dfs(g, i, marked);
			}
		}

		std::cout << "Odlazna numeracija: " << node << std::endl;
	}

	void dfs(const graph &g, int start_node)
	{
		std::vector<bool> makred(g.number_of_nodes(), false);

		dfs(g, start_node, makred);
	}


	void bfs(const graph &g, int start_node)
	{
		std::queue<int> node_queue;
		int number_of_nodes = g.number_of_nodes();
		std::vector<bool> makred(number_of_nodes, false);
		int curr_node;

		node_queue.push(start_node);
		makred[start_node] = true;

		while(!node_queue.empty())
		{
			curr_node = node_queue.front();
			node_queue.pop();

			for(int i = 0; i < number_of_nodes; ++i)
			{
				if(g.get_branch(curr_node, i) && !makred[i])
				{
					node_queue.push(i);
					makred[i] = true;
				}
			}

			std::cout << "Dolazna numeracija: " << curr_node << std::endl;
		}
	}

	graph load_graph()
	{
		int n;
		std::cout << "Input number of nodes: ";
		std::cin >> n;

		graph g(n);

		int m;
		int k;

		for(int i = 0; i < n; ++i)
		{
			std::cout << "Number of neighbours for node " << i << " : ";
			std::cin >> m;
			std::cout << "Input neighbours for node " << i << ":" << std::endl;

			for(int j = 0; j < m; ++j)
			{
				std::cin >> k;
				g.add_branch(i, k);
			}
		}

		return g;
	}
}
