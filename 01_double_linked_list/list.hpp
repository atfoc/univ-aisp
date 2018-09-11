#ifndef LIST_HPP_71VFPGQ3
#define LIST_HPP_71VFPGQ3



#include <iostream>

namespace aisp
{
	struct node
	{
		explicit node(int val);

		node *next;
		node *prev;
		int val;
	};


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
			node* begin() const;
			node* end() const;

			~list();


		private:
			node *first_element_;
			node *last_element_;
	};


	std::ostream& operator<<(std::ostream &out, const list &l);
}//namespace aisp

#endif /* end of include guard: LIST_HPP_71VFPGQ3 */
