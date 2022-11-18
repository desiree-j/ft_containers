/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:53:38 by djedasch          #+#    #+#             */
/*   Updated: 2022/11/16 13:53:31 by djedasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft
{

	template <class Iter>
	class reverse_iterator : public Iter
	{
		public:
			typedef	Iter													iterator_type;
			typedef typename std::iterator_traits<Iter>::pointer			pointer;
			typedef typename std::iterator_traits<Iter>::reference			reference;
			typedef typename std::iterator_traits<Iter>::value_type			value_type;
			typedef typename std::iterator_traits<Iter>::difference_type	difference_type;
			typedef typename std::iterator_traits<Iter>::iterator_category	iterator_category;

		public:
			reverse_iterator() : _it(Iter()){}
			reverse_iterator(iterator_type it) : _it(it){}
			~reverse_iterator(void)
			{
				this->_it.~Iter();
			}
			reverse_iterator(const reverse_iterator& rhs) //! doesn't work
			{
				this->_it = rhs._it;
			}
			reverse_iterator& operator=(const reverse_iterator& rhs)
			{
				this->_it = rhs._it;
				return (*this);
			}
			iterator_type base() const
			{
				return (this->_it - 1);
			}
			reverse_iterator& operator++()
			{
				return (--this->_it);
			}
			reverse_iterator& operator++(int)
			{
				reverse_iterator &tmp = *this;
				this->_it--;
				return (tmp);
			}
			reverse_iterator& operator--()
			{
				return (++this->_it);
			}
			reverse_iterator& operator--(int)
			{
				reverse_iterator &tmp = *this;
				this->_it++;
				return (tmp);
			}
			reference operator[](difference_type n) const
			{
				return (this->_it[- 1 - n]);
			}
			reference operator*() const
			{
				return (*(this->_it - 1));
			}
			//! pointer operator->() const
			reverse_iterator& operator+(difference_type n)
			{
				return (this->_it - n);
			}
			reverse_iterator& operator-(difference_type n)
			{
				reverse_iterator &tmp = *this;
				tmp._it = tmp._it + n;
				//this->_it = this->_it + n;
				return (tmp);
			}
			reverse_iterator& operator-=(difference_type n)
			{
				return (this->_it += n);
			}
			reverse_iterator& operator+=(difference_type n)
			{
				return (this->_it -= n);
			}
			bool operator==(const reverse_iterator &rhs) const
			{
				return (this->_it == rhs._it);
			}
			bool operator!=(const reverse_iterator &rhs) const
			{
				return(!(*this == rhs));
			}
			bool operator<(const reverse_iterator &rhs) const
			{
				return(this->_it > rhs._it);
			}
			bool operator>(const reverse_iterator &rhs) const
			{
				return(rhs < *this);
			}
			bool operator<=(const reverse_iterator &rhs) const
			{
				return(!(*this > rhs));
			}
			bool operator>=(const reverse_iterator &rhs) const
			{
				return(!(*this < rhs));
			}

			private:
				iterator_type _it;

		};
}

#endif