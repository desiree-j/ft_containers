/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 06:57:50 by djedasch          #+#    #+#             */
/*   Updated: 2022/11/08 13:45:00 by djedasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <cmath>

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

	
		explicit vector (const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _array(NULL), _alloc(alloc)
		{
		}

		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _capacity (n), _alloc(alloc)
		{
			this->_array = this->_alloc.allocate(this->_capacity);
			for (size_type i = 0; i < this->_capacity; i++)
			{
				this->_array[i] = val;
			}
		}

		//todo constructor 3
		//template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
		//{}

		vector (const vector& x) : _size(x._size), _capacity(x._capacity), _alloc(x._alloc)
		{
			this->_array = this->_alloc.allocate(this->_capacity);
			for (size_type i = 0; i < this->_size; i++)
			{
				this->_array[i] = x->_array[i];
			}
		}

		~vector()
		{
			this->_alloc.deallocate(this->_array, this->_capacity);
		}

		allocator_type get_allocator() const
		{
			return (this->_alloc);
		}

		//todo operator=
		vector& operator= (const vector& x)
		{
		}

		////& position
		////todo begin
		//iterator begin();
		//const_iterator begin() const;
		////todo end
		//iterator end();
		//const_iterator end() const;
		////todo rbegin
		//reverse_iterator rbegin();
		//const_reverse_iterator rbegin() const;
		////todo rend
		//reverse_iterator rend();
		//const_reverse_iterator rend() const;

		////& modifiers
		////todo clear
		//void clear();
		////todo swap
		//void swap (vector& x);	
		////todo assign
		//template <class InputIterator>  void assign (InputIterator first, InputIterator last);	
		//void assign (size_type n, const value_type& val);
		////todo pop_back
		//void pop_back();

		void push_back (const value_type& val)
		{
			if (this->_size < this->_capacity)
			{
				this->_array[this->_size] = val;
				this->_size++;
			}
			else
			{
				size_type newCapa = 1;
				if (this->_capacity > 0)
					newCapa = pow(2, (floor(log2(this->_capacity)) + 1));
				T* temp = this->_alloc.allocate(newCapa);
				for (size_type i = 0; i < this->_size; i++)
				{
					temp[i] = this->_array[i];
				}
				this->_alloc.deallocate(this->_array, this->_capacity);
				this->_capacity = newCapa;
				this->_array = temp;
				this->_array[this->_size] = val;
				this->_size++;
			}
		}
		////todo erase
		//iterator erase (iterator position);
		//iterator erase (iterator first, iterator last);
		////todo insert	
		//iterator insert (iterator position, const value_type& val);	
		//void insert (iterator position, size_type n, const value_type& val);
		//template <class InputIterator>    void insert (iterator position, InputIterator first, InputIterator last);

		////& element access	
		////todo operator[]
		//reference operator[] (size_type n);
		//const_reference operator[] (size_type n) const;
		////todo at
		//reference at (size_type n);
		//const_reference at (size_type n) const;
		////todo back
		//reference back();
		//const_reference back() const;
		////todo front
		//reference front();
		//const_reference front() const;
		
		//& capacity
		size_type size() const
		{
			return (this->_size);
		}
		////todo max_size
		//size_type max_size() const;
		////todo resize
		//void resize (size_type n, value_type val = value_type());
		bool empty() const
		{
			return (this->_size == 0);
		}
		////todo reserve
		//void reserve (size_type n);
		size_type capacity() const
		{
			return (this->_capacity);
		}
		
		
		//& comparisons
		bool operator== (const vector &rhs) const
		{
			if(this->size() != rhs.size())
				return (false);
			for (int i = 0; i < this->size(); i++)
			{
				if (this->_array[i] != rhs->_array[i])
					return (false);
			}
			return (true);
		}

		bool operator!= (const vector &rhs) const
		{
			return (!(*this == rhs));
		}
		//bool operator< (const vector &rhs) const;
		//bool operator<= (const vector &rhs) const;
		//bool operator> (const vector &rhs) const;
		//bool operator>= (const vector &rhs) const;

		private:
		size_type				_size;
		size_type				_capacity;
		T*						_array;
		allocator_type			_alloc;
		

	};

}



#endif