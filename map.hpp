/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 06:56:54 by djedasch          #+#    #+#             */
/*   Updated: 2022/11/25 10:20:40 by djedasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
#include "bst.hpp"
#include "mapIterator.hpp"
#include "reverse_iterator.hpp"
# include <stdexcept> 

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
	class map
	{
		public:
		//& typedefs
		typedef T													mapped_type;
		typedef pair <Key,T>										value_type;
		typedef Key													key_type;
		typedef Compare												key_compare;
		typedef Alloc												allocator_type;
		typedef typename allocator_type::reference					reference;
		typedef typename allocator_type::const_reference			const_reference;
		typedef typename allocator_type::pointer					pointer;
		typedef typename allocator_type::const_pointer				const_pointer;
		typedef typename allocator_type::size_type					size_type;
		typedef typename allocator_type::difference_type			difference_type;
		typedef mapIterator<map>									iterator;
		typedef const_mapIterator<const map>						const_iterator;
		typedef ft::reverse_iterator<iterator>						reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;

		//template <class Key, class T, class Compare, class Alloc>
		//class map<Key,T,Compare,Alloc>::value_compare : binary_function<value_type,value_type,bool>
		//{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
		//	friend class map;
		//	public:
		//	typedef bool result_type;
		//	typedef value_type first_argument_type;
		//	typedef value_type second_argument_type;
		//	bool operator() (const value_type& x, const value_type& y) const
		//	{
		//		return comp(x.first, y.first);
		//	}
		//	protected:
		//	Compare comp;
		//	value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
		//}

		public:
		//& constructor, destructor
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _root(NULL), _alloc(alloc), _comp(comp), _size(0){}
		//todo constructor
		template <class InputIterator>  
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());	
		map (const map& x);
		//todo destructor
		~map();
		allocator_type get_allocator() const
		{
			return (this->_alloc);
		}
		//todo copy assignment overload
		map& operator= (const map& x);
		//& position
		iterator begin()
		{
			Node *tmp = this->_root;
			while(tmp->left != NULL)
				tmp = tmp->left;
			return (iterator(tmp));
		}
		const_iterator begin() const
		{
			Node *tmp = this->_root;
			while(tmp->left != NULL)
				tmp = tmp->left;
			return (const_iterator(tmp));
		}
		iterator end()
		{
			return (iterator(NULL));
		}
		const_iterator end() const
		{
			return (const_iterator(NULL));
		}
		reverse_iterator rbegin()
		{
			Node *tmp = this->_root;
			while(tmp->right != NULL)
				tmp = tmp->right;
			return (reverse_iterator(tmp));
		}
		const_reverse_iterator rbegin() const
		{
			Node *tmp = this->_root;
			while(tmp->right != NULL)
				tmp = tmp->right;
			return (const_reverse_iterator(tmp));
		}
		reverse_iterator rend()
		{
			return(reverse_iterator(NULL));
		}
		const_reverse_iterator rend() const
		{
			return(const_reverse_iterator(NULL));
		}
		//& modifiers
		//todo clear
		void clear()
		{
			//iterator it = this->begin();
			
		}
		void erase (iterator position)
		{
			if (*position->_left == NULL && *position->_right == NULL)
			{
				this->_alloc.destroy(&(*position));
				this->_alloc.deallocate(&(*position));
				this->_size--;
			}
			else if (*position->_left == NULL || *position->_right == NULL)
			{
				if  (*position->_left == NULL)
				{
					*position->_data = *position->_right->_data;
					this->erase(iterator(*position->_right));
				}
				else
				{
					*position->_data = *position->_left->_data;
					this->erase(iterator(*position->_right));
				}
			}
			else
			{
				iterator next = position;
				next++;
				*position->_data = *(next)->_data;
				this->erase(next);
			}
		}
		size_type erase (const key_type& k)
		{
			for (iterator it = this->begin(); it != this->end(); i++)
			{
				if (*it->_data->_first == k)
				{
					this->erase(it);
					return (1);
				}
			}
			return (0);
		}
	    void erase (iterator first, iterator last)
		{
			for (; first != last; first++)
				erase(first);
		}
		//todo insert
		pair<iterator,bool> insert (const value_type& val);
		iterator insert (iterator position, const value_type& val);
		template <class InputIterator>  void insert (InputIterator first, InputIterator last);
		//todo swap
		void swap (map& x);
		//& element access	
		//todo find
		iterator find (const key_type& k);
		const_iterator find (const key_type& k) const;
		//todo operator[]
		mapped_type& operator[] (const key_type& k);
		//& capacity
		size_type count (const key_type& k) const
		{
			if (this->lower_bound() == k)
				return (1);
			return (0)
		}
		bool empty() const
		{
			if (this->_size == 0)
				return (true);
			return (false);
		}
		size_type max_size() const
		{
			return (this->_alloc.max_size());
		}
		size_type size() const
		{
			return (this->_size);
		}
		//& comparision
		//todo equal range
		pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
		pair<iterator,iterator> equal_range (const key_type& k);
		key_compare key_comp() const
		{
			return (this->_comp);
		}
		iterator lower_bound (const key_type& k)
		{
			for (iterator it = this->_begin(); it != this->end(); it++)
			{
				if(!this->_comp(*it->_data->first, k))
					return (it);
			}
			return (iterator(this->end()));
		}
		const_iterator lower_bound (const key_type& k) const
		{
			for (const_iterator it = this->_begin(); it != this->end(); it++)
			{
				if(!this->_comp(*it->_data->first, k))
					return (it);
			}
			return (const_iterator(this->end()));
		}
		iterator upper_bound (const key_type& k)
		{
			for (iterator it = this->_begin(); it != this->end(); it++)
			{
				if(this->_comp(k, *it->_data->first))
					return (it);
			}
			return (iterator(this->end()));
		}
		const_iterator upper_bound (const key_type& k) const
		{
			for (const_iterator it = this->_begin(); it != this->end(); it++)
			{
				if(this->_comp(k, *it->_data->first))
					return (it);
			}
			return (const_iterator(this->end()));
		}
		//todo value_comp()
		value_compare value_comp() const;
		

		private:
		ft::Node 		*_root;
		allocator_type 	_alloc;
		key_compare		_comp;
		size_type 		_size:

	};
	template <class Key, class T, class Compare, class Alloc>  bool operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs );
	template <class Key, class T, class Compare, class Alloc>  bool operator!= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs );
	template <class Key, class T, class Compare, class Alloc>  bool operator<  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs );
	template <class Key, class T, class Compare, class Alloc>  bool operator<= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs );
	template <class Key, class T, class Compare, class Alloc>  bool operator>  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs );
	template <class Key, class T, class Compare, class Alloc>  bool operator>= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs );
	template <class Key, class T, class Compare, class Alloc>  void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y);
}

#endif