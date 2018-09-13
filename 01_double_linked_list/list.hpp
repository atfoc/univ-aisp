#ifndef LIST_HPP_71VFPGQ3
#define LIST_HPP_71VFPGQ3



#include <iostream>

namespace aisp
{
	namespace list_detail
	{
		struct node
		{
			explicit node(int val);

			node *next;
			node *prev;
			int val;
		};
	}//namespace list_detail


	class list
	{
		public:
			list();
			void push_back(int val);
			void push_front(int val);
			void pop_back();
			void pop_front();
			void clear();
			int front() const;
			int back() const;
			bool empty() const;
			/* Iterators are not in scope of the course so
			 * we will use this for iterating over the list*/
			list_detail::node* begin() const;
			list_detail::node* end() const;

			~list();

		private:
			list_detail::node *first_element_;
			list_detail::node *last_element_;
	};


	std::ostream& operator<<(std::ostream &out, const list &l);
}//namespace aisp

#endif /* end of include guard: LIST_HPP_71VFPGQ3 */
