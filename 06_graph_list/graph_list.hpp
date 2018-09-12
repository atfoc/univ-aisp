#ifndef UNIV_AISP_GRAPH_HPP
#define UNIV_AISP_GRAPH_HPP

#include <vector>
#include <list>
#include <ostream>

namespace aisp
{
	class graph_list
	{
		private:
			std::vector<std::list<int>> edges_;

		public:
			explicit graph_list(int node_number);

			void add_branch(int i, int j);
			const std::list<int>& get_neighbours(int i) const;
			int number_of_nodes() const;



	};

	void dfs(const graph_list &g, int start_node);
	void bfs(const graph_list &g, int start_node);
	graph_list load_graph_list();

}

#endif //UNIV_AISP_GRAPH_HPP
