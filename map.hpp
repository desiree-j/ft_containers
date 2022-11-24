/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 06:56:54 by djedasch          #+#    #+#             */
/*   Updated: 2022/11/24 15:03:23 by djedasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
#include "bst.hpp"

namespace ft
{
	template < class Key, class T, class Compare = less<Key>, class Alloc = allocator<pair<const Key,T> > >
	class map
	{
		public:
		//& typedefs
		typedef T													value_type;
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
				*position->_data = *(position + 1)->_data;
				this->erase(position + 1);
			}
		}
		size_type erase (const key_type& k);
	    void erase (iterator first, iterator last);
		pair<iterator,bool> insert (const value_type& val);
		iterator insert (iterator position, const value_type& val);
		template <class InputIterator>  void insert (InputIterator first, InputIterator last);
		void swap (map& x);
		//& element access	
		iterator find (const key_type& k);
		const_iterator find (const key_type& k) const;
		mapped_type& operator[] (const key_type& k);
		//& capacity
		size_type count (const key_type& k) const;
		bool empty() const;
		size_type max_size() const;
		size_type size() const;
		//& comparision
		pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
		pair<iterator,iterator>             equal_range (const key_type& k);
		key_compare key_comp() const;
		iterator lower_bound (const key_type& k);
		const_iterator lower_bound (const key_type& k) const;
		iterator upper_bound (const key_type& k);
		const_iterator upper_bound (const key_type& k) const;
		value_compare value_comp() const;
		

		private:
		Node 			*_root;
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