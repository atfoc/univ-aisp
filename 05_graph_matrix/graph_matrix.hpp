#ifndef UNIV_AISP_GRAPH_HPP
#define UNIV_AISP_GRAPH_HPP

#include <vector>
#include <ostream>
#include "../06_graph_list/graph_list.hpp"

namespace aisp
{
	class graph_matrix
	{
		private:
			std::vector<std::vector<bool>> edge_matrix_;

		public:
			explicit graph_matrix(int node_number);

			void add_branch(int i, int j);
			int get_branch(int i, int j) const;
			int number_of_nodes() const;



	};

	std::ostream &operator<<(std::ostream &os, const graph_matrix &g);

	void dfs(const graph_matrix &g, int start_node);
	void bfs(const graph_matrix &g, int start_node);
	graph_matrix load_graph_matrix();


}


#endif //UNIV_AISP_GRAPH_HPP
