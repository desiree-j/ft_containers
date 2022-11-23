/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 06:56:54 by djedasch          #+#    #+#             */
/*   Updated: 2022/11/23 15:18:43 by djedasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

namespace ft
{
	template < class Key, class T, class Compare = less<Key>, class Alloc = allocator<pair<const Key,T> > >
	class map
	{
		public:

		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
		template <class InputIterator>  map (InputIterator first, InputIterator last,       const key_compare& comp = key_compare(),       const allocator_type& alloc = allocator_type());	
		map (const map& x);
		~map();
		allocator_type get_allocator() const;
		map& operator= (const map& x);
		//& position
		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;
		//& modifiers
		void clear();
		void erase (iterator position);
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