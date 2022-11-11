/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 06:57:50 by djedasch          #+#    #+#             */
/*   Updated: 2022/11/11 10:09:44 by djedasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <cmath>
# include <stdexcept> 

namespace ft
{

	template <typename vector>
	class vectorIterator
	{
		public:
		typedef typename vector::pointer					pointer;
		typedef typename vector::reference					reference;
		typedef typename vector::value_type					value_type;
		typedef typename std::ptrdiff_t 					difference_type;
		typedef typename std::random_access_iterator_tag	iterator_category;
		typedef typename vector::size_type					size_type;
		

		public:
		vectorIterator(pointer ptr) : _ptr(ptr){}
		~vectorIterator(void){}
		//todo copy constructor, copy assignment operator
		//vectorIterator(const vectorIterator&);
		//vectorIterator& operator=(const vectorIterator&);
		//& comparison
		bool operator==(const vectorIterator &rhs) const
		{
			if(this->_ptr == rhs._ptr)
				return (true);
			return (false);
		}
		bool operator!=(const vectorIterator &rhs) const
		{
			return(!(*this == rhs));
		}
		bool operator<(const vectorIterator &rhs) const
		{
			if (this->_ptr < rhs._ptr)
				return (true);
			return(false);
		}
		bool operator>(const vectorIterator &rhs) const
		{
			return(rhs < *this);
		}
		bool operator<=(const vectorIterator &rhs) const
		{
			return(!(*this > rhs));
		}
		bool operator>=(const vectorIterator &rhs) const
		{
			return(!(*this < rhs));
		}
		//& (de)referencing
        pointer operator->() const
		{
			return (this->_ptr);
		}
        reference operator[](size_type n) const
		{
			return (*(this->_ptr + n));
		}
		reference operator*(void) const
		{
			return (*this->_ptr);
		}
		//& increament, decrement
		vectorIterator& operator++()
		{
			this->_ptr++;
			return (*this);
		}
		vectorIterator& operator++(int)
		{
			vectorIterator &tmp = *this;
			++(*this);
			return (tmp);
		}
		vectorIterator& operator--()
		{
			this->_ptr--;
			return (*this);
		}
		vectorIterator& operator--(int)
		{
			vectorIterator tmp = *this;
			--(*this);
			return (tmp);
		}
		friend vectorIterator operator+(size_type n , const vectorIterator& it)
		{
			return(vectorIterator(it._ptr + n));
		}
		vectorIterator& operator+(size_type n)
		{
			this->_ptr = this->_ptr + n;
			return (*this);
		}
		vectorIterator& operator-(size_type n)
		{
			this->_ptr = this->_ptr - n;
			return (*this);
		}
		vectorIterator& operator-=(size_type n)
		{
			this->_ptr = this->_ptr - n;
			return (*this);
		}
		vectorIterator& operator+=(size_type n)
		{
			this->_ptr = this->_ptr + n;
			return (*this);
		}

		private:
		pointer _ptr;
	};


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
		typedef vectorIterator<vector>						iterator;
		typedef const vectorIterator<vector>				const_iterator;
		public:
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
				this->_array[i] = x._array[i];
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

		vector& operator= (const vector& x)
		{
			this->_alloc = x._alloc;
			this->_size = x._size;
			if (this->_capacity < x._size)
			{
				this->_alloc.deallocate(this->_array, this->_capacity);
				this->_capacity = x._capacity;
				this->_array = this->_alloc.allocate(this->_capacity);
			}
			for (size_type i = 0; i < this->_size; i++)
			{
				this->_array[i] = x._array[i];
			}
			return (*this);
		}

		//& position
		iterator begin()
		{
			return (iterator(&this->_array[0]));
		}
		const_iterator begin() const
		{
			return (iterator(&this->_array[0]));
		}
		iterator end()
		{
			return (iterator(&this->_array[this->_size]));
		}
		const_iterator end() const
		{
			return (iterator(&this->_array[this->_size]));
		}
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
		void assign (size_type n, const value_type& val)
		{
			if (n > this->_capacity)
			{
				while (this->_capacity < n)
				{
					this->_capacity *=2;
				}
				T* temp = this->_alloc.allocate(this->_capacity);
				for (size_type i = 0; i < this->_size; i++)
				{
					temp[i] = val;
					this->_alloc.destroy(this->_array.at(i));
				}
				for (size_type i = this->_size; i < n; i++)
				{
					temp[i] = val;
				}
				this->_alloc.deallocate(this->_array, this->_capacity);
				this->_array = temp;
			}
			else
			{
				for (int i = 0; i < min(n, this->_size); i++)
				{
					this->_alloc.destroy(this->_array[i]);
					this->_array[i] = val;
				}
			}
			if (this->_size < n)
				this->_size = n;
		}
		//todo pop_back
		void pop_back()
		{
			this->_size--;
		}

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
					newCapa = this->_capacity * 2; 
				realloc(newCapa);
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

		//& element access	
		reference operator[] (size_type n)
		{
			return(this->_array[n]);
		}
		const_reference operator[] (size_type n) const
		{
			return(this->_array[n]);
		}
		reference at (size_type n)
		{
			if (n >= this->_size)
				throw std::out_of_range("vector::_M_range_check");
			return(this->_array[n]);
		}
		const_reference at (size_type n) const
		{
			if (n >= this->_size)
				throw std::out_of_range("vector::_M_range_check");
			return(this->_array[n]);
		}
		reference back()
		{
			return(this->_array[this->_size - 1]);
		}
		const_reference back() const
		{
			return(this->_array[this->_size - 1]);
		}
		reference front()
		{
			return(this->_array[0]);
		}
		const_reference front() const
		{
			return(this->_array[0]);
		}
		
		//& capacity
		size_type size() const
		{
			return (this->_size);
		}
		size_type max_size() const
		{
			return (this->_alloc.max_size());
		}
		////todo resize
		//void resize (size_type n, value_type val = value_type());
		bool empty() const
		{
			return (this->_size == 0);
		}
		void reserve (size_type n)
		{
			if (this->_capacity >= n)
				return;
			size_type capa = this->_capacity;
			while (capa < n)
			{
				capa *=2;
			}
			realloc(capa);
		}
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
		bool operator< (const vector &rhs) const
		{
			int end = rhs._size;
			if (this->_size < rhs._size)
				end = this->_size;
			for (int i = 0; i < end; i++)
			{
				if (this->_array[i] < rhs._array[i])
					return (true);
				else if (this->_array[i] > rhs._array[i])
					return (false);
			}
			if (this->_size < rhs._size)
				return (true);
			return (false);
		}
		bool operator<= (const vector &rhs) const
		{
			return (!(*this < rhs));
		}
		bool operator> (const vector &rhs) const
		{
			return (rhs < *this);
		}
		bool operator>= (const vector &rhs) const
		{
			return (!(*this > rhs));
		}

		private:
		size_type				_size;
		size_type				_capacity;
		T*						_array;
		allocator_type			_alloc;

		void	realloc(size_type capa)
		{
			T* temp = this->_alloc.allocate(capa);
			for (size_type i = 0; i < this->_size; i++)
			{
				temp[i] = this->_array[i];
			}
			this->_alloc.deallocate(this->_array, this->_capacity);
			this->_capacity = capa;
			this->_array = temp;
		}
		

	};

}



#endif