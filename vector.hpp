/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 06:57:50 by djedasch          #+#    #+#             */
/*   Updated: 2022/11/07 16:00:13 by djedasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

namespace ft
{
	template <class T, class Alloc =  std::allocator<T> >
	class vector
	{
		public:
		//& typedefs
		typedef T											value_type;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::size_type			size_type;

		//todo constructor
		explicit vector ();	
		explicit vector (size_type n, const value_type& val = value_type());
		template <class InputIterator> vector (InputIterator first, InputIterator last);	
		vector (const vector& x);
		//todo destructor
		~vector();

		//& position
		//todo begin
		iterator begin();const_iterator begin() const;
		//todo end
		iterator end();
		const_iterator end() const;
		//todo rbegin
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		//todo rend
		reverse_iterator rend();
		const_reverse_iterator rend() const;

		//& modifiers
		//todo clear
		void clear();
		//todo swap
		void swap (vector& x);	
		//todo assign
		template <class InputIterator>  void assign (InputIterator first, InputIterator last);	
		void assign (size_type n, const value_type& val);
		//todo pop_back
		void pop_back();
		//todo push_back
		void push_back (const value_type& val);
		//todo erase
		iterator erase (iterator position);
		iterator erase (iterator first, iterator last);
		//todo insert	
		iterator insert (iterator position, const value_type& val);	
		void insert (iterator position, size_type n, const value_type& val);
		template <class InputIterator>    void insert (iterator position, InputIterator first, InputIterator last);

		//& element access	
		//todo operator[]
		reference operator[] (size_type n);
		const_reference operator[] (size_type n) const;
		//todo at
		reference at (size_type n);
		const_reference at (size_type n) const;
		//todo back
		reference back();
		const_reference back() const;
		//todo front
		reference front();
		const_reference front() const;
		
		//& capacity
		//todo size
		size_type size() const;
		//todo max_size
		size_type max_size() const;
		//todo resize
		void resize (size_type n, value_type val = value_type());
		//todo empty
		bool empty() const;
		//todo reserve
		void reserve (size_type n);
		//todo capacity
		size_type capacity() const;
		
		//& others
		//todo get_allocator
		allocator_type get_allocator() const;
		//todo operator=
		vector& operator= (const vector& x);
		
		
		




		private:

	};
}



#endif