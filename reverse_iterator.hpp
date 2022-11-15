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
			reverseIterator(iterator_type it) : _it(it){}
			~reverseIterator(void)
			{
				~this->_it;
			}
			reverseIterator(const reverseIterator& rhs)
			{
				this->_it = rhs._it;
			}
			reverseIterator& operator=(const reverseIterator& rhs)
			{
				this->_it = rhs._it;
				return (*this);
			}
			iterator_type base() const
			{
				return (this->_it);
			}
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
			reference operator[](difference_type n) const
			{
				return (this->_it[- n - 1]);
			}
			reference operator*() const
			{
				return (*(this->_it - 1));
			}
			//! pointer operator->() const
			reverseIterator& operator+(difference_type n)
			{
				return (this->_it - n);
			}
			reverseIterator& operator-(difference_type n)
			{
				return (this->_it + n);
			}
			reverseIterator& operator-=(difference_type n)
			{
				return (this->_it += n);
			}
			reverseIterator& operator+=(difference_type n)
			{
				return (this->_it -= n);
			}
			bool operator==(const reverseIterator &rhs) const
			{
				return (this->_it == rhs._it);
			}
			bool operator!=(const reverseIterator &rhs) const
			{
				return(!(*this == rhs));
			}
			bool operator<(const reverseIterator &rhs) const
			{
				return(this->_it > rhs._it);
			}
			bool operator>(const reverseIterator &rhs) const
			{
				return(rhs < *this);
			}
			bool operator<=(const reverseIterator &rhs) const
			{
				return(!(*this > rhs));
			}
			bool operator>=(const reverseIterator &rhs) const
			{
				return(!(*this < rhs));
			}

			private:
				iterator_type _it;

		};
}

#endif