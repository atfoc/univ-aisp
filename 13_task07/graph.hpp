#ifndef UNIV_AISP_GRAPH_HPP
#define UNIV_AISP_GRAPH_HPP

#include <vector>
#include <list>
#include <ostream>

namespace with_list_task07
{
	namespace aisp
	{
		class graph {
		private:
			std::vector<std::list<int>> edges_;

		public:
			explicit graph(int node_number);

			void add_branch(int i, int j);

			const std::list<int> &get_neighbours(int i) const;

			int number_of_nodes() const;


		};


		int bfs(const aisp::graph &g, int start_node, int end_node);

		graph load_graph_list();

	}
}
#endif //UNIV_AISP_GRAPH_HPP
