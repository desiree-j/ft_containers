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
# include "utils.hpp"

namespace ft
{
	template <typename T, typename vector>
	class vectorIterator
	{
		public:
		typedef typename ft::iterator_traits<T>::pointer			pointer;
		typedef typename ft::iterator_traits<T>::reference			reference;
		typedef typename ft::iterator_traits<T>::value_type			value_type;
		typedef typename ft::iterator_traits<T>::difference_type	difference_type;
		typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;
		

		public:
		vectorIterator() : _ptr(NULL) {}
		vectorIterator(pointer ptr) : _ptr(ptr){}
		~vectorIterator(void){}
		vectorIterator(const vectorIterator& rhs) : _ptr(rhs._ptr){}
		template<typename t, typename vec>
		vectorIterator(vectorIterator<t, vec> copy) : _ptr(copy.getPtr()){}
		vectorIterator& operator=(const vectorIterator& rhs)
		{
			this->_ptr = rhs._ptr;
			return (*this);
		}

	
		//& (de)referencing
        pointer operator->() const
		{
			return (this->_ptr);
		}
        reference operator[](difference_type n) const
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
		vectorIterator operator+(difference_type n)
		{
			return (vectorIterator(this->_ptr + n));
		}
		vectorIterator operator-(difference_type n)
		{
			return (vectorIterator(this->_ptr - n));
		}
		difference_type operator-(const vectorIterator& it) const
		{
			return (this->_ptr - it._ptr);
		}
		difference_type operator+(const vectorIterator& it) const
		{
			return (this->_ptr + it._ptr);
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
		pointer getPtr() const
		{
			return (this->_ptr);
		}
		protected:
		pointer _ptr;
	};

	//& ----------------- non member comparison -----------------------
	
	template<typename T, typename vector>
	bool operator==(const vectorIterator<T, vector> &lhs, const vectorIterator<T, vector> &rhs) 
	{
		if(lhs.getPtr() == rhs.getPtr())
			return (true);
		return (false);
	}
	template<typename T, typename vector>
	bool operator!=(const vectorIterator<T, vector> &lhs, const vectorIterator<T, vector> &rhs) 
	{
		return(!(lhs == rhs));
	}
	template<typename T, typename vector>
	bool operator<(const vectorIterator<T, vector> &lhs, const vectorIterator<T, vector> &rhs) 
	{
		if (lhs.getPtr() < rhs.getPtr())
			return (true);
		return(false);
	}
	template<typename T, typename vector>
	bool operator>(const vectorIterator<T, vector> &lhs, const vectorIterator<T, vector> &rhs) 
	{
		return(rhs < lhs);
	}
	template<typename T, typename vector>
	bool operator<=(const vectorIterator<T, vector> &lhs, const vectorIterator<T, vector> &rhs) 
	{
		return(!(lhs > rhs));
	}
	template<typename T, typename vector>
	bool operator>=(const vectorIterator<T, vector> &lhs, const vectorIterator<T, vector> &rhs) 
	{
		return(!(lhs < rhs));
	}


	template<typename T,typename T2, typename vector>
	bool operator==(const vectorIterator<T, vector> &lhs, const vectorIterator<T2, vector> &rhs) 
	{
		if(lhs.getPtr() == rhs.getPtr())
			return (true);
		return (false);
	}
	template<typename T,typename T2, typename vector>
	bool operator!=(const vectorIterator<T, vector> &lhs, const vectorIterator<T2, vector> &rhs)  
	{
		return(!(lhs == rhs));
	}
	template<typename T,typename T2, typename vector>
	bool operator<(const vectorIterator<T, vector> &lhs, const vectorIterator<T2, vector> &rhs) 
	{
		if (lhs.getPtr() < rhs.getPtr())
			return (true);
		return(false);
	}
	template<typename T,typename T2, typename vector>
	bool operator>(const vectorIterator<T, vector> &lhs, const vectorIterator<T2, vector> &rhs) 
	{
		return(rhs < lhs);
	}
	template<typename T,typename T2, typename vector>
	bool operator<=(const vectorIterator<T, vector> &lhs, const vectorIterator<T2, vector> &rhs) 
	{
		return(!(lhs > rhs));
	}
	template<typename T,typename T2, typename vector>
	bool operator>=(const vectorIterator<T, vector> &lhs, const vectorIterator<T2, vector> &rhs) 
	{
		return(!(lhs < rhs));
	}

	template<typename T2, typename vector>
	vectorIterator<T2, vector> operator+(typename vectorIterator<T2, vector>::difference_type offset, const vectorIterator<T2, vector> &rhs) 
	{
		return (vectorIterator<T2, vector>(rhs.getPtr() + offset));
	}

	template<typename T1, typename vector>
	vectorIterator<T1, vector> operator+(const vectorIterator<T1, vector> &lhs, typename vectorIterator<T1, vector>::difference_type offset) 
	{
		return (vectorIterator<T1, vector>(lhs.getPtr + offset));
	}

	template<typename T2, typename vector>
	vectorIterator<T2, vector> operator-(typename vectorIterator<T2, vector>::difference_type offset, const vectorIterator<T2, vector> &rhs) 
	{
		return (vectorIterator<T2, vector>(rhs.getPtr - offset));
	}

	template<typename T1, typename vector>
	vectorIterator<T1, vector> operator-(const vectorIterator<T1, vector> &lhs, typename vectorIterator<T1, vector>::difference_type offset) 
	{
		return (vectorIterator<T1, vector>(lhs.getPtr - offset));
	}
}
#endif