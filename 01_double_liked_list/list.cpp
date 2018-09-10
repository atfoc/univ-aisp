#include <cstdlib>
#include "list.hpp"
#include "../util.hpp"

namespace aisp
{
	node::node(int val)
		:	val{val}
	{}

	list::list()
		:	first_element_{nullptr},
			last_element_{nullptr}
	{}

	void list::push_back(int val)
	{
		node *node_to_add{new node(val)};

		if(!first_element_ &&  !last_element_)
		{
			first_element_ = last_element_ = node_to_add;
		}
		else if(first_element_ &&  last_element_)
		{
			last_element_->next = node_to_add;
			node_to_add->prev = last_element_;
			last_element_ = node_to_add;
		}
		else
		{
			assert(false, "This shoud not happen something is wrong. First Element is null and last"
				"is not, or other way around");
		}
	}

	void list::push_front(int val)
	{
		node *node_to_add{new node(val)};

		if(!first_element_ &&  !last_element_)
		{
			first_element_ = last_element_ = node_to_add;
		}
		else if(first_element_ && last_element_)
		{
			first_element_->prev = node_to_add;
			node_to_add->next = first_element_;
			first_element_ = node_to_add;
		}
		else
		{
			assert(false, "This shoud not happen something is wrong. First Element is null and last"
				"is not, or other way around");
		}
	}

	void list::pop_back()
	{
		if(first_element_ && last_element_)
		{
			if(last_element_ == first_element_)
			{
				delete last_element_;
				first_element_ = last_element_ = nullptr;
			}
			else
			{
				node *tmp{last_element_};
				
				last_element_ = tmp->prev;
				last_element_->next = nullptr;
				delete tmp;
			}
		}
		else if(!first_element_ && !last_element_)
		{
			/*This is an empty list and there is nothing to do*/
			return ;
		}
		else 
		{
			assert(false, "This shoud not happen something is wrong. First Element is null and last"
				"is not, or other way around");
		}
	}

	void list::pop_front()
	{
		if(first_element_ && last_element_)
		{
			if(first_element_ == last_element_)
			{
				delete first_element_;
				first_element_ = last_element_ = nullptr;
			}
			else
			{
				node *tmp{first_element_};
					
				first_element_ = tmp->next;
				first_element_->prev= nullptr;
				delete tmp;
			}
		}
		else if(!first_element_ && !last_element_)
		{
			/*This is an empty list and there is nothing to do*/
			return ;
		}
		else 
		{
			assert(false, "This shoud not happen something is wrong. First Element is null and last"
				"is not, or other way around");
		}
		
	}

	void list::clear()
	{
		node *tmp;

		while(first_element_)
		{
			tmp = first_element_->next;
			delete first_element_;
			first_element_ = tmp;
		}

		first_element_ = last_element_ = nullptr;
	}

	int list::front() const
	{
		if(first_element_)
		{
			return first_element_->val;
		}
		else
		{
			assert(false, "List is empty you can not get front");
			/*This never happens it is just for compiler warining*/
			return -1;
		}
	}

	int list::back() const
	{
		if(last_element_)
		{
			return last_element_->val;
		}
		else
		{
			assert(false, "List is empty you an not get back");
			/*This never happens it is just for compiler warining*/
			return -1;
		}
	}

	bool list::empty() const
	{
		return !first_element_ && !last_element_? true : false;
	}

	node* list::begin() const
	{
		return first_element_;
	}

	node* list::end() const
	{
		return last_element_;
	}


	list::~list()
	{
		this->clear();
	}

	std::ostream& operator<<(std::ostream &out, const list &l)
	{
		for(node *curr = l.begin(); curr; curr = curr->next)
		{
			out << curr->val << (curr->next ? "->" : "");
		}

		return out;
	}

}//namespace aisp
