/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 06:56:54 by djedasch          #+#    #+#             */
/*   Updated: 2022/12/08 14:15:26 by djedasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
#include "mapIterator.hpp"
#include "reverse_iterator.hpp"
#include "utils.hpp"
# include <stdexcept> 

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map
	{
		public:
		//& typedefs
		typedef T													mapped_type;
		typedef pair <const Key,T>									value_type;
		typedef Key													key_type;
		typedef Compare												key_compare;
		typedef Alloc												allocator_type;
		typedef value_type&											reference;
		typedef const value_type&									const_reference;
		typedef typename allocator_type::pointer					pointer;
		typedef const value_type*									const_pointer;
		typedef typename allocator_type::size_type					size_type;
		typedef typename allocator_type::difference_type			difference_type;
		typedef mapIterator<map>									iterator;
		typedef const_mapIterator<const map>						const_iterator; 
		typedef ft::reverse_iterator<iterator>						reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
		typedef ft::Node<key_type, mapped_type>						Node;

		class value_compare : std::binary_function<value_type,value_type,bool>
		{
			friend class map;
			public:
			bool operator() (const value_type& x, const value_type& y) const
			{
				return _comp(x.first, y.first);
			}
			protected:
			Compare _comp;
			value_compare (Compare c) : _comp(c) {}  
		};

		public:
		//& constructor, destructor
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _root(NULL), _alloc(alloc), _comp(comp), _size(0){}
		template <class InputIterator>  
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _root(NULL), _alloc(alloc), _comp(comp), _size(0)
		{
			this->insert(first, last);
			//for (; first != last; first++)
			//{
			//	this->insert(*first);
			//}
		}
		map (const map& x)
		{
			this->_alloc = x._alloc;
			this->_comp = x._comp;
			this->_size = 0;
			this->_root = NULL;
			if (x._root != NULL)
				this->copyTree(x._root);

		}
		~map() 
		{
			this->clear();
		}
		allocator_type get_allocator() const
		{
			return (this->_alloc);
		}
		map& operator= (const map& x)
		{
			this->_alloc = x._alloc;
			this->_comp = x._comp;
			this->clear();
			if (x._root != NULL)
				this->copyTree(x._root);
			return (*this);
		}
		//& position
		iterator begin()
		{
			Node *tmp = this->_root;
			while(tmp->_left != NULL)
				tmp = tmp->_left;
			return (iterator(tmp, this->_root));
		}
		const_iterator begin() const
		{
			Node *tmp = this->_root;
			while(tmp != NULL && tmp->_left != NULL)
			{
				tmp = tmp->_left;
			}
			//std::cout << C_GREEN << "begin" << C_DEF << std::endl;
			return (const_iterator(tmp, this->_root));
		}
		iterator end()
		{
			return (iterator(NULL, this->_root));
		}
		const_iterator end() const
		{
			return (const_iterator(NULL, this->_root));
		}
		reverse_iterator rbegin()
		{
			Node *tmp = this->_root;
			while(tmp->right != NULL)
				tmp = tmp->right;
			return (reverse_iterator(tmp, this->_root));
		}
		const_reverse_iterator rbegin() const
		{
			Node *tmp = this->_root;
			while(tmp->right != NULL)
				tmp = tmp->right;
			return (const_reverse_iterator(tmp, this->_root));
		}
		reverse_iterator rend()
		{
			return(reverse_iterator(NULL, this->_root));
		}
		const_reverse_iterator rend() const
		{
			return(const_reverse_iterator(NULL, this->_root));
		}
		//& modifiers
		void clear()
		{
			while (this->size() > 0)
			//for(iterator it = this->begin(); it != this->end(); it++)
			{
				this->erase(this->begin());
			}
			
		}
		void erase (iterator position)
		{
			std::allocator<Node> tmp;
			if (position.left() == NULL && position.right() == NULL)
			{
				if (position.parent() == NULL)
					this->_root = NULL;
				else if(position.getNode() == position.parent()->left())
					position.parent()->_left = NULL;
				else
					position.parent()->_right = NULL;
				this->_alloc.destroy(&(*position));
				this->_alloc.deallocate(&(*position), 1);
				tmp.deallocate(position.getNode(),1);
			}
			else if (position.left() == NULL || position.right() == NULL)
			{
				iterator next = position;
				next++;
				Node *pos = position.getNode();
				if (position.getNode() == this->_root)
					this->_root = next.getNode();
				else if (pos->_parent->_left == position.getNode())
					pos->_parent->_left = position.left();
				else
					pos->_parent->_right = position.right();
				if  (position.left() == NULL)
				{
					pos->_right->_parent = position.parent();
					this->_alloc.destroy(&(*position));
					this->_alloc.deallocate(&(*position), 1);
					tmp.deallocate(position.getNode(),1);
				}
				else
				{
					pos->_left->_parent = position.parent();
					this->_alloc.destroy(&(*position));
					this->_alloc.deallocate(&(*position), 1);
					tmp.deallocate(position.getNode(),1);
				}
			}
			else
			{
				//if root -> this->root = next
				// baum links von position wird an ganz linkes blatt von next gehangen
				iterator next = position;
				next++;
				Node *temp = next.getNode();
				Node *pos = position.getNode();
				if (position.getNode() == this->_root)
					this->_root = next.getNode();
				else if (pos->_parent->_left == position.getNode())
					pos->_parent->_left = position.left();
				else
					pos->_parent->_right = position.right();
				temp->_parent = position.parent();
				while (temp->left() != NULL)
					temp = temp->left();
				temp->_left = position.left();
				pos->_left->_parent = temp;
				this->_alloc.destroy(&(*position));
				this->_alloc.deallocate(&(*position), 1);
				tmp.deallocate(position.getNode(),1);
			}
			this->_size--;
		}
		size_type erase (const key_type& k)
		{
			for (iterator it = this->begin(); it != this->end(); it++)
			{
				if (it->first == k)
				{
					this->erase(it);
					return (1);
				}
			}
			return (0);
		}
	    void erase (iterator first, iterator last)
		{
			iterator tmp = first;
			while (first != last)
			{
				first++;
				this->erase(tmp);
				tmp = first;
			}
			//for (; first != last; first++)
			//	erase(first);
		}
		pair<iterator,bool> insert (const value_type& val)
		{	
			iterator it = this->find(val.first);
			if (it != this->end())
				return (ft::make_pair(it, false));
			else
			{
				Node *node = this->find_next(this->_root, val.first);
				node->_data = this->_alloc.allocate(1);
				this->_alloc.construct(node->_data, val);
				this->_size++;
				it = this->find(val.first);
				return(ft::make_pair(it, true));
			}
		}
		iterator insert (iterator position, const value_type& val)
		{
			iterator it = this->find();
			Node *node;
			if (it != this->end())
				return (it);
			else
			{
				if (this->_comp(position->first, val->first))
					node = this->find_next(position, val->first);
				else
					node = this->find_next(this->_root, val->first);
				node->_data = this->_alloc.allocate(1);
				this->_alloc.construct(node->_data, val);
				this->_size++;
			}
			return(this->find(val.first));
		}
		template <class InputIterator>  
		void insert (InputIterator first, InputIterator last)
		{
			for (; first != last; first++)
				insert(*first);
		}
		void swap (map& x)
		{
			Node 			*tmpRoot = this->_root;
			allocator_type 	tmpAlloc = this->_alloc;
			key_compare		tmpComp = this->_comp;
			size_type 		tmpSize = this->_size;
			this->_alloc = x._alloc;
			this->_comp = x._comp;
			this->_root = x._root;
			this->_size = x._size;
			x._alloc = tmpAlloc;
			x._comp = tmpComp;
			x._root = tmpRoot;
			x._size = tmpSize;
		}
		//& element access	
		iterator find (const key_type& k)
		{
			if (this->count(k) == 1)
			{
				return (this->lower_bound(k));
			}
			return (this->end());
		}
		const_iterator find (const key_type& k) const
		{
			if (this->count(k) == 1)
				return (this->lower_bound(k));
			return (this->end());
		}
		mapped_type& operator[] (const key_type& k)
		{
			iterator it = insert(ft::make_pair(k, mapped_type())).first;
			return (it->second);
		}
		//& capacity
		size_type count (const key_type& k) const
		{
			if (this->_size == 0)
				return(0);
			const_iterator it = this->lower_bound(k);
			const_iterator it2 = this->upper_bound(k);
			if (it == it2)
				return (0);
			return (1);
		}
		bool empty() const
		{
			if (this->_size == 0)
				return (true);
			return (false);
		}
		size_type max_size() const
		{
			std::allocator<Node> tmp;
			return (tmp.max_size());
		}
		size_type size() const
		{
			return (this->_size);
		}
		//& comparision
		pair<const_iterator,const_iterator> equal_range (const key_type& k) const
		{
			return(ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
		}
		pair<iterator,iterator> equal_range (const key_type& k)
		{
			return(ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
		}
		key_compare key_comp() const
		{
			return (this->_comp);
		}
		iterator lower_bound (const key_type& k)
		{
			for (iterator it = this->begin(); it != this->end(); it++)
			{
				if(!this->_comp(it->first, k))
					return (it);
			}
			return (iterator(this->end()));
		}
		const_iterator lower_bound (const key_type& k) const
		{				
			for (const_iterator it  = this->begin(); it != this->end(); it++)
			{
				if(!this->_comp(it->first, k))
					return (it);
			}
			return (const_iterator(this->end()));
		}
		iterator upper_bound (const key_type& k)
		{
			for (iterator it = this->begin(); it != this->end(); it++)
			{
				if(this->_comp(k, it->first))
					return (it);
			}
			return (iterator(this->end()));
		}
		const_iterator upper_bound (const key_type& k) const
		{
			for (const_iterator it = this->begin(); it != this->end(); it++)
			{

				if(this->_comp(k, it->first))
					return (it);
			}
			return (const_iterator(this->end()));
		}
		value_compare value_comp() const
		{
			return(value_compare(this->_comp));
		}
		

		private:
		Node 			*_root;
		allocator_type 	_alloc;
		key_compare		_comp;
		size_type 		_size;

		Node *find_next(Node *start, const key_type &k)
		{
			std::allocator<Node> tmp;
			//std::allocator<Node*> p;
			if (start == NULL) //empty map
			{
				this->_root = tmp.allocate(1);
				this->_root->_left = NULL;
				this->_root->_right = NULL;
				this->_root->_parent = NULL;
				return (this->_root);
			}
			if (this->_comp(start->_data->first, k)) //new element is bigger than start
			{
				if (start->_right != NULL)
					return(find_next(start->_right, k));

				else
				{
					start->_right = tmp.allocate(1);
					start->_right->_parent = start;
					start->_right->_left = NULL;
					start->_right->_right = NULL;
					return (start->_right);
				}
			}
			else // new element is smaller than start
			{
				if (start->_left != NULL)
					return(this->find_next(start->_left, k));
				else
				{
					start->_left = tmp.allocate(1);
					start->_left->_parent =  start;
					start->_left->_left = NULL;
					start->_left->_right = NULL;
					return (start->_left);
				}
			}
			return (start);
		}
		void	copyTree(Node *root)
		{
			this->insert(*(root->_data));
			if (root->left() != NULL)
				copyTree(root->left());
			if (root->right() != NULL)
				copyTree(root->right());
		}
	};
	template <class Key, class T, class Compare, class Alloc>  
	bool operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename map<Key,T,Compare,Alloc>::const_iterator it = lhs.begin();
		typename map<Key,T,Compare,Alloc>::const_iterator it2 = rhs.begin();
		while (it != lhs.end())
		{
			if (it->first != it2->first || it->second != it2->second)
				return (false);
			it++;
			it2++;
		}
		return (true);
	}
	template <class Key, class T, class Compare, class Alloc>  
	bool operator!= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		return (!(lhs==rhs));
	}
	template <class Key, class T, class Compare, class Alloc>  
	bool operator<  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		typename map<Key,T,Compare,Alloc>::const_iterator first1 = lhs.begin();
		typename map<Key,T,Compare,Alloc>::const_iterator first2 = rhs.begin();
		typename map<Key,T,Compare,Alloc>::const_iterator last1 = lhs.end();
		typename map<Key,T,Compare,Alloc>::const_iterator last2 = rhs.end();
		while (first1!=last1)
		{
			if (first2==last2 || (first2->first < first1->first || first2->second < first1->second)) 
				return false;
			else if (first1->first < first2->first || (first1->first == first2->first && first1->second < first2->second)) 
				return true;
			++first1;
			++first2;
		}
		return (first2!=last2);
	}
	template <class Key, class T, class Compare, class Alloc>  
	bool operator<= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		return (!(lhs > rhs));
	}
	template <class Key, class T, class Compare, class Alloc>  
	bool operator>  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		return (rhs < lhs);
	}
	template <class Key, class T, class Compare, class Alloc>  
	bool operator>= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		return (!(lhs < rhs));
	}
	template <class Key, class T, class Compare, class Alloc>  
	void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
	{
		x.swap(y);
	}
}

#endif