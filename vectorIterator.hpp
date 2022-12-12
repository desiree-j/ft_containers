/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_vectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:01:48 by djedasch          #+#    #+#             */
/*   Updated: 2022/11/22 15:05:25 by djedasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

	template <typename vector>
	class vectorIterator
	{
		public:
		typedef typename vector::pointer					pointer;
		typedef typename vector::reference					reference;
		typedef typename vector::value_type					value_type;
		typedef std::ptrdiff_t 								difference_type;
		typedef std::random_access_iterator_tag				iterator_category;
		typedef typename vector::size_type					size_type;
		

		public:
		vectorIterator() : _ptr(NULL) {}
		vectorIterator(pointer ptr) : _ptr(ptr){}
		~vectorIterator(void){}
		vectorIterator(const vectorIterator& rhs)
		{
			this->_ptr = rhs._ptr;
		}
		vectorIterator& operator=(const vectorIterator& rhs)
		{
			this->_ptr = rhs._ptr;
			return (*this);
		}
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
        reference operator[](int n) const
		{
			return (*(this->_ptr + n));
		}
		reference operator*(void) const
		{
			return (*(this->_ptr));
		}
		//& increment, decrement
		vectorIterator &operator++()
		{
			this->_ptr++;
			return (*this);
		}
		vectorIterator operator++(int)
		{
			vectorIterator tmp = *this;
			this->_ptr++;
			return (tmp);
		}
		vectorIterator &operator--()
		{
			this->_ptr--;
			return (*this);
		}
		vectorIterator operator--(int)
		{
			vectorIterator tmp = *this;
			--(*this);
			return (tmp);
		}
		friend vectorIterator operator+(difference_type n , const vectorIterator& it)
		{
			return(vectorIterator(it._ptr + n));
		}
		vectorIterator operator+(difference_type n)
		{
			return (this->_ptr + n);
		}
		vectorIterator operator-(difference_type n)
		{
			return (this->_ptr - n);
		}
		difference_type operator-(const vectorIterator& it)
		{
			return (this->_ptr - it._ptr);
		}
		vectorIterator operator-=(difference_type n)
		{
			this->_ptr = this->_ptr - n;
			return (*this);
		}
		vectorIterator operator+=(difference_type n)
		{
			this->_ptr = this->_ptr + n;
			return (*this);
		}
		private:
		pointer _ptr;
	};

	template <typename vector>
	class const_vectorIterator
	{
		public:
		typedef typename vector::pointer				pointer;
		typedef typename vector::value_type				value_type;
		typedef const value_type&						reference;
		typedef std::ptrdiff_t 							difference_type;
		typedef std::random_access_iterator_tag			iterator_category;
		typedef typename vector::size_type				size_type;
		

		public:
		const_vectorIterator() : _ptr(NULL) {}
		const_vectorIterator(pointer ptr) : _ptr(ptr){}
		~const_vectorIterator(void){}
		const_vectorIterator(const const_vectorIterator& rhs)
		{
			this->_ptr = rhs._ptr;
		}
		const_vectorIterator& operator=(const const_vectorIterator& rhs)
		{
			this->_ptr = rhs._ptr;
			return (*this);
		}
		//& comparison
		bool operator==(const const_vectorIterator &rhs) const
		{
			if(this->_ptr == rhs._ptr)
				return (true);
			return (false);
		}
		bool operator!=(const const_vectorIterator &rhs) const
		{
			return(!(*this == rhs));
		}
		bool operator<(const const_vectorIterator &rhs) const
		{
			if (this->_ptr < rhs._ptr)
				return (true);
			return(false);
		}
		bool operator>(const const_vectorIterator &rhs) const
		{
			return(rhs < *this);
		}
		bool operator<=(const const_vectorIterator &rhs) const
		{
			return(!(*this > rhs));
		}
		bool operator>=(const const_vectorIterator &rhs) const
		{
			return(!(*this < rhs));
		}
		//& (de)referencing
        const pointer operator->() const
		{
			return (this->_ptr);
		}
        reference operator[](int n) const
		{
			const value_type ret= *(this->_ptr + n);
			return (ret);
		}
		reference operator*(void) const
		{
			const value_type *tmp = (this->_ptr);
			return (*tmp);
		}
		//& increment, decrement
		const_vectorIterator &operator++()
		{
			this->_ptr++;
			return (*this);
		}
		const_vectorIterator operator++(int)
		{
			const_vectorIterator tmp = *this;
			this->_ptr++;
			return (tmp);
		}
		const_vectorIterator &operator--()
		{
			this->_ptr--;
			return (*this);
		}
		const_vectorIterator operator--(int)
		{
			const_vectorIterator tmp = *this;
			--(*this);
			return (tmp);
		}
		friend const_vectorIterator operator+(difference_type n , const const_vectorIterator& it)
		{
			return(const_vectorIterator(it._ptr + n));
		}
		const_vectorIterator operator+(difference_type n)
		{
			return (this->_ptr + n);
		}
		const_vectorIterator operator-(difference_type n)
		{
			return (this->_ptr - n);
		}
		difference_type operator-(const const_vectorIterator& it)
		{
			return (this->_ptr - it._ptr);
		}
		const_vectorIterator operator-=(difference_type n)
		{
			this->_ptr = this->_ptr - n;
			return (*this);
		}
		const_vectorIterator operator+=(difference_type n)
		{
			this->_ptr = this->_ptr + n;
			return (*this);
		}
		
		private:
		pointer _ptr;
	};

#endif