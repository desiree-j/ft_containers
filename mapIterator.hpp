/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:03:50 by djedasch          #+#    #+#             */
/*   Updated: 2022/11/24 15:46:04 by djedasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATOR_HPP
# define MAPITERATOR_HPP

	template <typename map>
	class mapIterator
	{
		public:
		typedef typename map::pointer					pointer;
		typedef typename map::reference					reference;
		typedef typename map::value_type				value_type;
		typedef std::ptrdiff_t 							difference_type;
		typedef std::bidirectional_iterator_tag			iterator_category;
		typedef typename map::size_type					size_type;
		typedef typename map::key_type					key_type;
		

		public:
		mapIterator() : _ptr(NULL) {}
		mapIterator(pointer ptr) : _ptr(ptr){}
		~mapIterator(void){}
		mapIterator(const mapIterator& rhs)
		{
			this->_ptr = rhs._ptr;
		}
		mapIterator& operator=(const mapIterator& rhs)
		{
			this->_ptr = rhs._ptr;
			return (*this);
		}
		//& comparison
		bool operator==(const mapIterator &rhs) const
		{
			if(this->_ptr == rhs._ptr)
				return (true);
			return (false);
		}
		bool operator!=(const mapIterator &rhs) const
		{
			return(!(*this == rhs));
		}
		//& (de)referencing
        pointer operator->() const
		{
			return (this->_ptr);
		}
        reference operator[](int n) const
		{
			return (*(this->_ptr + n));
		}
		reference operator*(void) const
		{
			return (*(this->_ptr));
		}
		//& increment, decrement
		//! change increment and decrement operator
		mapIterator operator++()
		{
			if (this->_ptr->right != NULL)
			{
				
				while ()
			}
			return (*this);
		}
		mapIterator operator++(int)
		{
			mapIterator tmp = *this;
			this->_ptr++;
			return (tmp);
		}
		mapIterator operator--()
		{
			
			return (*this);
		}
		mapIterator operator--(int)
		{
			mapIterator tmp = *this;
			--(*this);
			return (tmp);
		}
		private:
		pointer _ptr;
	};

	template <typename map>
	class const_mapIterator
	{
		public:
		typedef typename map::key_type				key_type;
		typedef typename map::pointer				pointer;
		typedef typename map::value_type			value_type;
		typedef const value_type&					reference;
		typedef std::ptrdiff_t 						difference_type;
		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef typename map::size_type				size_type;
		

		public:
		const_mapIterator() : _ptr(NULL) {}
		const_mapIterator(pointer ptr) : _ptr(ptr){}
		~const_mapIterator(void){}
		const_mapIterator(const const_mapIterator& rhs)
		{
			this->_ptr = rhs._ptr;
		}
		const_mapIterator& operator=(const const_mapIterator& rhs)
		{
			this->_ptr = rhs._ptr;
			return (*this);
		}
		//& comparison
		bool operator==(const const_mapIterator &rhs) const
		{
			if(this->_ptr == rhs._ptr)
				return (true);
			return (false);
		}
		bool operator!=(const const_mapIterator &rhs) const
		{
			return(!(*this == rhs));
		}
		//& (de)referencing
        const pointer operator->() const
		{
			return (this->_ptr);
		}
		reference operator*(void) const
		{
			const value_type *tmp = (this->_ptr);
			return (*tmp);
		}
		//& increment, decrement
		//! change increment and decrement operator
		const_mapIterator operator++()
		{
			this->_ptr++;
			return (*this);
		}
		const_mapIterator operator++(int)
		{
			const_mapIterator tmp = *this;
			this->_ptr++;
			return (tmp);
		}
		const_mapIterator operator--()
		{
			this->_ptr--;
			return (*this);
		}
		const_mapIterator operator--(int)
		{
			const_mapIterator tmp = *this;
			--(*this);
			return (tmp);
		}
		private:
		pointer _ptr;
	};

#endif