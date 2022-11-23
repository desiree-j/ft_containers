/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 06:57:34 by djedasch          #+#    #+#             */
/*   Updated: 2022/11/23 14:59:01 by djedasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP
# include "vector.hpp"
namespace ft
{
	template <class T, class Container = vector<T> > 
	class stack
	{
		public:
		typedef Container									container_type;
		typedef T											value_type;
		typedef typename Container::allocator_type			allocator_type;
		typedef typename Container::reference				reference;
		typedef typename Container::const_reference			const_reference;
		typedef typename Container::pointer					pointer;
		typedef typename Container::const_pointer			const_pointer;
		typedef typename Container::size_type				size_type;
		typedef typename Container::difference_type			difference_type;
	

		public:
		bool empty() const
		{
			return (c.empty());
		}
		void pop()
		{
			c.erase(c.end() - 1);
		}
		void push (const value_type& val)
		{
			c.insert(c.end(), val);
		}
		size_type size() const
		{
			return (c.size());
		}
		value_type& top()
		{
			return (*(c.end() - 1));
		}
		const value_type& top() const
		{
			return (*(c.end() - 1));
		}

		protected:
		container_type c;

	};
	template <class T, class Container>  
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (equal(lhs.c.begin(), lhs.c.end(), rhs.c.begin()));
	}
	//template <class T, class Container>  bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
	//template <class T, class Container>  bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
	//template <class T, class Container>  bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
	//template <class T, class Container>  bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
	//template <class T, class Container>  bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

}

#endif