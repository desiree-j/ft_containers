/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseIterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:53:38 by djedasch          #+#    #+#             */
/*   Updated: 2022/11/14 15:52:20 by djedasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft
{

	template <class Iter>
	class reverseIterator : public Iter
	//class reverseIterator : std::iterator<std::iterator_traits<Iter>::iterator_category
	//, std::iterator_traits<Iter>::value_type
	//, std::iterator_traits<Iter>::difference_type
	//, std::iterator_traits<Iter>::pointer
	//, std::iterator_traits<Iter>::reference>
	{
		public:
			typedef	Iter													iterator_type;
			typedef typename std::iterator_traits<Iter>::pointer			pointer;
			typedef typename std::iterator_traits<Iter>::reference			reference;
			typedef typename std::iterator_traits<Iter>::value_type			value_type;
			typedef typename std::iterator_traits<Iter>::difference_type	difference_type;
			typedef typename std::iterator_traits<Iter>::iterator_category	iterator_category;

		public:
			reverseIterator() : _it(Iter()){}
			reverseIterator(Iter it) : _it(it){}
			//~reverseIterator(void) : ~Iter(){}
			//reverseIterator(const reverseIterator& rhs){}
			//reverseIterator& operator=(const reverseIterator& rhs){}
			reverseIterator& operator++()
			{
	
				return (--this->_it);
			}
			reverseIterator& operator++(int)
			{
				reverseIterator &tmp = *this;
				this->_it--;
				return (tmp);
			}
			reverseIterator& operator--()
			{
				return (++this->_it);
			}
			reverseIterator& operator--(int)
			{
				reverseIterator &tmp = *this;
				this->_it++;
				return (tmp);
			}
			 reference operator[](int n) const
			{
				return (this->_it[-n]);
			}
		//	friend reverseIterator operator+(size_type n , const reverseIterator& it)
		//	{
		//		return(reverseIterator(it._ptr + n));
		//	}
		//	reverseIterator& operator+(size_type n)
		//	{
		//		this->_ptr = this->_ptr + n;
		//		return (*this);
		//	}
		//	reverseIterator& operator-(size_type n)
		//	{
		//		this->_ptr = this->_ptr - n;
		//		return (*this);
		//	}
		//	reverseIterator& operator-=(size_type n)
		//	{
		//		this->_ptr = this->_ptr - n;
		//		return (*this);
		//	}
		//	reverseIterator& operator+=(size_type n)
			private:
				Iter _it;

		};
}

#endif