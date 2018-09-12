#include "../util.hpp"
#include "avl.hpp"

namespace aisp
{
	namespace avl_detail
	{
		node::node(int value)
			:	value{value},
				height{1},
				left{nullptr},
				right{nullptr}

		{}

		int height_of(node *root)
		{
			return (!root) ? 0 : root->height;
		}

		int diff(node *root)
		{

			return (!root) ? 0 :  height_of(root->right) - height_of(root->left);
		}

		void left_roatate(node *&root)
		{
			node *tmp = root->right;
			root->right = tmp->left;
			tmp->left = root;
			root = tmp;
		}

		void right_rotate(node *&root)
		{
			node *tmp = root->left;
			root->left = tmp->right;
			tmp->right = root;
			root = tmp;
		}

		void fix(node *&root)
		{

			/*RR*/
			if(diff(root) > 1 && diff(root->right) > 0)
			{
				left_roatate(root);
			}
			/*LL*/
			if(diff(root) < -1 && diff(root->left) < 0)
			{
				right_rotate(root);
			}
			/*RL*/
			if(diff(root) > 1 && diff(root->right) < 0)
			{
				right_rotate(root->right);
				left_roatate(root);
			}
			/*LR*/
			if(diff(root) < -1 && diff(root->left) > 0)
			{
				left_roatate(root->left);
				right_rotate(root);
			}

		}

		void insert_node(node *&root, node *node_to_insert)
		{
			if(!root)
			{
				root = node_to_insert;
			}
			else if(node_to_insert->value < root->value)
			{
				insert_node(root->left, node_to_insert);
			}
			else if(node_to_insert->value > root->value)
			{
				insert_node(root->right, node_to_insert);
			}
			else
			{
				AISP_ASSERT(false, "Cant have two nodes of the same value");
			}

			fix(root);
			root->height = std::max(height_of(root->left), height_of(root->right)) + 1;
		}


	}//avl_detail namespace

	avl::avl()
		:	root_{nullptr}
	{

	}

	void avl::insert(int value)
	{
		avl_detail::node *n{new avl_detail::node(value)};

		avl_detail::insert_node(root_, n);

	}

	void avl::remove(int value)
	{
	}

	avl::~avl()
	{
		avl_detail::postorder(root_, [](auto &c){delete c;});
	}
}//aisp namespace
