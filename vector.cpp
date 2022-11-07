/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 06:58:36 by djedasch          #+#    #+#             */
/*   Updated: 2022/11/07 20:17:18 by djedasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

		//todo constructor
		explicit vector::vector (const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0)
		{

		}
		explicit vector::vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){}
		template <class InputIterator> vector::vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()){}	
		vector::vector (const vector& x){}
		//todo destructor
		vector::~vector(){}

		//& iterators
		//todo begin
		iterator vector::begin(){}
		const_iterator vector::begin() const{}
		//todo end
		iterator vector::end(){}
		const_iterator vector::end() const{}
		//todo rbegin
		reverse_iterator vector::rbegin(){}
		const_reverse_iterator vector::rbegin() const{}
		//todo rend
		reverse_iterator vector::rend(){}
		const_reverse_iterator vector::rend() const{}

		//& modifiers
		//todo clear
		void vector::clear(){}
		//todo swap
		void vector::swap (vector& x){}	
		//todo assign
		template <class InputIterator>  void vector::assign (InputIterator first, InputIterator last){}	
		void vector::assign (size_type n, const value_type& val){}
		//todo pop_back
		void pop_back(){}
		//todo push_back
		void vector::push_back (const value_type& val){}
		//todo erase
		iterator vector::erase (iterator position){}
		iterator vector::erase (iterator first, iterator last){}
		//todo insert	
		iterator vector::insert (iterator position, const value_type& val){}	
		void vector::insert (iterator position, size_type n, const value_type& val){}
		template <class InputIterator> void vector::insert (iterator position, InputIterator first, InputIterator last){}

		//& element access	
		//todo operator[]
		reference vector::operator[] (size_type n){}
		const_reference vector::operator[] (size_type n) const{}
		//todo at
		reference vector::at (size_type n){}
		const_reference vector::at (size_type n) const{}
		//todo back
		reference vector::back(){}
		const_reference vector::back() const{}
		//todo front
		reference vector::front(){}
		const_reference vector::front() const{}
		
		//& capacity
		size_type vector::size() const
		{
			return (this->_size);
		}
		//todo max_size
		size_type vector::max_size() const{}
		//todo resize
		void vector::resize (size_type n, value_type val = value_type()){}
		bool vector::empty() const
		{
			return (this->_size == 0);
		}
		//todo reserve
		void vector::reserve (size_type n){}
		size_type vector::capacity() const
		{
			return (this->capacity);
		}
		
		//& others
		//todo get_allocator
		allocator_type vector::get_allocator() const{}
		//todo operator=
		vector& vector::operator= (const vector& x){}