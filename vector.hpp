/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 06:57:50 by djedasch          #+#    #+#             */
/*   Updated: 2022/12/15 14:32:28 by djedasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <stdexcept> 
# include "utils.hpp"
# include "reverse_iterator.hpp"
# include "vectorIterator.hpp"

namespace ft
{
	template <class T, class Alloc =  std::allocator<T> >
	class vector
	{
		public:
		//& typedefs
		typedef T																value_type;
		typedef Alloc															allocator_type;
		typedef typename allocator_type::reference								reference;
		typedef typename allocator_type::const_reference						const_reference;
		typedef typename allocator_type::pointer								pointer;
		typedef typename allocator_type::const_pointer							const_pointer;
		typedef typename allocator_type::size_type								size_type;
		typedef typename allocator_type::difference_type						difference_type;
		typedef vectorIterator<T*, vector>										iterator;
		typedef vectorIterator<const T*, const vector>							const_iterator;
		typedef ft::reverse_iterator<iterator>									reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>							const_reverse_iterator;

		public:
		explicit vector (const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _array(NULL), _alloc(alloc){}
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _capacity (n), _alloc(alloc)
		{
			this->_array = this->_alloc.allocate(this->_capacity);
			for (size_type i = 0; i < this->_capacity; i++)
			{
				this->_alloc.construct(&this->_array[i], val);
			}
		}
		template <class InputIterator> 
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename enable_if<!is_integral<InputIterator>::value>::type* = 0) : _size(0), _capacity (0), _alloc(alloc)
		{
			this->assign(first, last);
		}
		vector (const vector& x) : _size(x._size), _capacity(x._size), _alloc(x._alloc)
		{
			this->_array = this->_alloc.allocate(this->_capacity);
			for (size_type i = 0; i < this->_size; i++)
			{
				this->_alloc.construct(&this->_array[i], x._array[i]);
			}
		}
		~vector()
		{
			if (this->_size < this->_capacity)
			{
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.destroy(&this->_array[i]);
			}
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
				this->_alloc.construct(&this->_array[i], x._array[i]);
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
			return (const_iterator(&this->_array[0]));
		}
		iterator end()
		{
			return (iterator(&this->_array[this->_size]));
		}
		const_iterator end() const
		{
			return (const_iterator(&this->_array[this->_size]));
		}
		reverse_iterator rbegin()
		{
			return (reverse_iterator(iterator(&this->_array[this->_size])));
		}
		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(const_iterator(&this->_array[this->_size])));
		}
		reverse_iterator rend()
		{
			return (reverse_iterator(iterator(&this->_array[0])));
		}
		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(const_iterator(&this->_array[0])));
		}

		//& modifiers
		void clear()
		{
			for (size_type i = 0; i < this->_size; i++)
			{
				this->_alloc.destroy(&this->_array[i]);
			}
			this->_size = 0;
		}
		void swap (vector& x)
		{
			size_type 	tmpSize = this->_size;
			T 			*tmpArray = this->_array;
			size_type 	tmpCapacity = this->_capacity;
			
			this->_size = x._size;
			this->_array = x._array;
			this->_capacity = x._capacity;
			x._size = tmpSize;
			x._array = tmpArray;
			x._capacity = tmpCapacity;
		}
		template <class InputIterator>  
		void assign (InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value>::type* = 0)
		{ 
			if (last == first)
				return;
			InputIterator tmp = first;
			size_type n = 0;
			while (tmp != last)
			{
				tmp++;
				n++;
			}
			if (n > this->_capacity)
			{
				T* temp = this->_alloc.allocate(n);
				for (size_type i = 0; i < this->_size; i++)
				{
					this->_alloc.construct(&temp[i], *first);
					this->_alloc.destroy(&this->_array[i]);
					first++;
				}
				for (size_type i = this->_size; i < n; i++)
				{
					this->_alloc.construct(&temp[i], *first);
					first++;
				}
				if (this->_capacity > 0)
					this->_alloc.deallocate(this->_array, this->_capacity);
				this->_array = temp;
				this->_capacity = n;
			}
			else
			{
				for (size_type i = 0; i < n; i++)
				{
					this->_alloc.destroy(&this->_array[i]);
					this->_alloc.construct(&this->_array[i], *first);
					first++;
				}
				for (size_type i = n; i < this->_size; i++)
				{
					this->_alloc.destroy(&(this->_array[i]));
				}
			}
			this->_size = n;
			
		}
		void assign (size_type n, const value_type& val)
		{
			if (n > this->_capacity)
			{
				if (this->_capacity == 0)
					this->_capacity = n;					
				while (this->_capacity < n)
				{
					this->_capacity *=2;
				}
				T* temp = this->_alloc.allocate(this->_capacity);
				for (size_type i = 0; i < this->_size; i++)
				{
					this->_alloc.construct(&temp[i], val);
					this->_alloc.destroy(&(this->_array[i]));
				}
				for (size_type i = this->_size; i < n; i++)
				{
					this->_alloc.construct(&temp[i], val);
				}
				this->_alloc.deallocate(this->_array, this->_capacity);
				this->_array = temp;
			}
			else
			{
				for (size_type i = 0; i < n; i++)
				{
					this->_alloc.destroy(&this->_array[i]);
					this->_alloc.construct(&this->_array[i], val);
				}
				for (size_type i = n; i < this->_size; i++)
				{
					this->_alloc.destroy(&(this->_array[i]));
				}
			}
			this->_size = n;
		}
		void pop_back()
		{
			this->_alloc.destroy(&this->_array[this->_size - 1]);
			this->_size--;
		}
		void push_back (const value_type& val)
		{
			if (this->_size < this->_capacity)
			{
				this->_alloc.construct(&this->_array[this->_size], val);
				this->_size++;
			}
			else
			{
				size_type newCapa = 1;
				if (this->_capacity > 0)
					newCapa = this->_capacity * 2; 
				realloc(newCapa);
				this->_alloc.construct(&this->_array[this->_size], val);
				this->_size++;
			}
		}
		iterator erase (iterator position)
		{
			this->_alloc.destroy(&(*position));
			iterator tmp = position;
			for (; position < (this->end() - 1); position++)
			{
				this->_alloc.construct(&(*(position)), position[1]);
			}
			this->_size--;
			return(tmp);
		}
		iterator erase (iterator first, iterator last)
		{
			size_type len = &(*(last)) - &(*(first));
			iterator tmp = first;
			for (; first < (this->end() - len); first++)
			{
				if (first < last)
					this->_alloc.destroy(&(*first));
				this->_alloc.construct(&(*first), first[len]);
			}
			this->_size -= len;
			return(tmp);
		}
		iterator insert (iterator position, const value_type& val)
		{
			if (this->_capacity == 0)
			{
				this->push_back(val);
				return (this->begin());
			}
			if (this->_size == this->_capacity)
			{
				size_type elem = &(*position)- &(*this->begin());
				realloc(this->_capacity * 2);
				position = this->begin() + elem;
			}
			for (iterator it = this->end() - 1; it > (position - 1); it--)
			{
				this->_alloc.construct(&it[1], it[0]);
			}
			this->_size++;
			this->_alloc.construct(&(*position), val);
			return (position);
		}
		void insert (iterator position, size_type n, const value_type& val)
		{
			if (this->_capacity == 0)
			{
				this->realloc(n);
				position = this->begin();
			}
			else if (this->_size + n > this->_capacity)
			{
				size_type elem = &(*position) - &(*this->begin());
				realloc(this->_size + n);
				position = this->begin() + elem;
			}
			this->_size += n;
			
			reverse_iterator end = reverse_iterator(position + n);
			for (reverse_iterator it = this->rbegin(); it != end; it++)
			{
				this->_alloc.construct(&(*it), *(it + n));
			}
			for (size_type i = 0; i < n; i++)
			{
				this->_alloc.construct(&position[i], val);
			}
		}	
		template <class InputIterator>    
		void insert (iterator position, InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value>::type* = 0)
		{
			if (last == first)
				return;
			InputIterator tmp = first;
			size_type n = 0;
			while (tmp != last)
			{
				tmp++;
				n++;
			}
			if (this->_capacity == 0)
			{
				this->realloc(n);
				position = this->begin();
			}
			else if (this->_size + n > this->_capacity)
			{
				size_type elem = &(*position) - &(*this->begin());
				realloc(this->_size + n);
				position = this->begin() + elem;
			}
			this->_size += n;
			reverse_iterator end = reverse_iterator(position + n);
			for (reverse_iterator it = this->rbegin(); it != end; it++)
			{
				this->_alloc.construct(&(*it), *(it + n));
			}
			for (size_type i = 0; i < n; i++)
			{
				this->_alloc.construct(&position[i], *first);
				first++;
			}
		}

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
		void resize (size_type n, value_type val = value_type())
		{
			if (n < this->_size)
			{
				for (size_type i = n; i < this->_size; i++)
				{
					this->_alloc.destroy(&(this->_array[i]));
				}
			}
			else if (n > this->_size)
			{
				if (n > this->_capacity)
				{
					if (n < 2 * this->_size)
						realloc(2 * this->_size);
					else
						realloc(n);
				}
				for (size_type i = this->_size; i < n; i++)
				{
					this->_alloc.construct(&this->_array[i], val);
				}
			}
			this->_size = n;
		}
		bool empty() const
		{
			return (this->_size == 0);
		}
		void reserve (size_type n)
		{
			if (this->_capacity >= n)
				return;
			realloc(n);
			this->_capacity = n;
		}
		size_type capacity() const
		{
			return (this->_capacity);
		}
		
		protected:
		size_type				_size;
		size_type				_capacity;
		T*						_array;
		allocator_type			_alloc;

		void	realloc(size_type capa)
		{
			if (capa == 0)
				capa = 1;
			T* temp = this->_alloc.allocate(capa);
			for (size_type i = 0; i < this->_size; i++)
			{
				this->_alloc.construct(&temp[i], this->_array[i]);
			}
			if (this->_capacity > 0)
				this->_alloc.deallocate(this->_array, this->_capacity);
			this->_capacity = capa;
			this->_array = temp;
		}
		
	};
	template <class T, class Alloc>  
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()) && ft::equal(rhs.begin(), rhs.end(), lhs.begin()));
	}
	template <class T, class Alloc>  
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}
	template <class T, class Alloc>  
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	template <class T, class Alloc>  
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs > rhs));
	}
	template <class T, class Alloc>  
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}
	template <class T, class Alloc>  
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}
	template <class T, class Alloc>  
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}
}



#endif