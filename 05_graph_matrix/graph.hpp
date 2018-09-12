#ifndef UNIV_AISP_GRAPH_HPP
#define UNIV_AISP_GRAPH_HPP

#include <vector>
#include <ostream>
#include "../06_graph_list/graph.hpp"

namespace with_matrix
{
	namespace aisp
	{
		class graph
		{
			private:
				std::vector<std::vector<bool>> edge_matrix_;

			public:
				explicit graph(int node_number);

				void add_branch(int i, int j);

				int get_branch(int i, int j) const;

				int number_of_nodes() const;


		};

		std::ostream &operator<<(std::ostream &os, const graph &g);

		void dfs(const graph &g, int start_node);

		void bfs(const graph &g, int start_node);

		graph load_graph_matrix();


	}
}

#endif //UNIV_AISP_GRAPH_HPP
