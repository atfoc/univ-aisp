#ifndef PROJECT_AVL1_HPP
#define PROJECT_AVL1_HPP


namespace aisp
{
	namespace avl_detail
	{
		struct node
		{
			explicit  node(int value);

			int value;
			int height;
			node *left;
			node *right;
		};
		/*left right root*/
		template<typename Callable>
		void postorder(node *root, Callable &&c)
		{
			if(!root)
			{
				return ;
			}

			postorder(root->left, std::forward<Callable>(c));
			postorder(root->right, std::forward<Callable>(c));
			c(root);
		}

		/*root left right*/
		template<typename Callable>
		void preorder(node *root, Callable &&c)
		{
			if(!root)
			{
				return ;
			}

			c(root);
			preorder(root->left, std::forward<Callable>(c));
			preorder(root->right, std::forward<Callable>(c));

		}


	}//avl_detail namespace


	class avl
	{
		private:
			avl_detail::node *root_;
		public:
			avl();

			void insert(int value);
			void remove(int value);
			~avl();

			template<typename Callable>
			friend void avl_detail::postorder(avl &s, Callable &&c);

			template<typename Callable>
			friend void avl_detail::preorder(avl &s, Callable &&c);
	};
	namespace avl_detail
	{
		template<typename Callable>
		void postorder(avl &s, Callable &&c)
		{
			postorder(s.root_, [&](auto &&it) { c(it->value); });
		}

		template<typename Callable>
		void preorder(avl &s, Callable &&c)
		{
			preorder(s.root_, [&](auto &&it) { c(it->value); });
		}
	}
}


#endif //PROJECT_AVL1_HPP
