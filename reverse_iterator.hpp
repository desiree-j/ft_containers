/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:53:38 by djedasch          #+#    #+#             */
/*   Updated: 2022/12/13 13:51:37 by djedasch         ###   ########.fr       */
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
			typedef	Iter										iterator_type;
			typedef typename iterator_type::pointer				pointer;
			typedef typename iterator_type::reference			reference;
			typedef typename iterator_type::value_type			value_type;
			typedef typename iterator_type::difference_type		difference_type;
			typedef typename iterator_type::iterator_category	iterator_category;

		public:
			reverse_iterator() : _it(Iter()){}
			reverse_iterator(iterator_type it) : _it(it){}
			~reverse_iterator(void)
			{
				this->_it.~Iter();
			}
			reverse_iterator(const reverse_iterator& rhs) : Iter(rhs)
			{
				this->_it = rhs._it;
			}
			template <class It> 
			reverse_iterator (const reverse_iterator<It>& other) : _it(other.base()) {}
			reverse_iterator& operator=(const reverse_iterator& rhs)
			{
				this->_it = rhs._it;
				return (*this);
			}
			iterator_type base() const
			{
				return (this->_it);
			}
			reverse_iterator &operator++()
			{
				--this->_it;
				return (*this);
			}
			reverse_iterator operator++(int)
			{
				reverse_iterator tmp(*this);
				this->_it--;
				return (tmp);
			}
			reverse_iterator &operator--()
			{
				++this->_it;
				return (*this);
			}
			reverse_iterator operator--(int)
			{
				reverse_iterator tmp = *this;
				this->_it++;
				return (tmp);
			}
			reference operator[](difference_type n) const
			{
				return (this->_it[- 1 - n]);
			}
			reference operator*() const
			{
				iterator_type it = this->_it;
				it--;
				return (*(it));
			}
			pointer operator->() const 
			{
				return (&(operator*()));
			}
			reverse_iterator operator+(difference_type n)
			{
				return (this->_it - n);
			}
			reverse_iterator operator-(difference_type n)
			{
				return (this->_it + n);
			}
			reverse_iterator operator-=(difference_type n)
			{
				return (this->_it += n);
			}
			reverse_iterator operator+=(difference_type n)
			{
				return (this->_it -= n);
			}
			
			protected:
				iterator_type _it;

	};		
		template<typename iterator>
		bool operator==(const reverse_iterator<iterator> &lhs, const reverse_iterator<iterator> &rhs) 
		{
			return (lhs.base() == rhs.base());
		}
		template<typename iterator>
		bool operator!=(const reverse_iterator<iterator> &lhs, const reverse_iterator<iterator> &rhs) 
		{
			return(!(lhs == rhs));
		}
		template<typename iterator>
		bool operator<(const reverse_iterator<iterator> &lhs, const reverse_iterator<iterator> &rhs) 
		{
			return(lhs.base() > rhs.base() );
		}
		template<typename iterator>
		bool operator>(const reverse_iterator<iterator> &lhs, const reverse_iterator<iterator> &rhs) 
		{
			return(rhs < lhs);
		}
		template<typename iterator>
		bool operator<=(const reverse_iterator<iterator> &lhs, const reverse_iterator<iterator> &rhs) 
		{
			return(!(lhs > rhs));
		}
		template<typename iterator>
		bool operator>=(const reverse_iterator<iterator> &lhs, const reverse_iterator<iterator> &rhs)  
		{
			return(!(lhs < rhs));
		}

}

#endif