/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 06:57:34 by djedasch          #+#    #+#             */
/*   Updated: 2022/12/16 09:31:30 by djedasch         ###   ########.fr       */
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
		explicit stack (const container_type& ctnr = container_type()) : c(ctnr) {}
		stack( const stack& other ) : c(other.c) {}
		~stack(void){}
		bool empty() const
		{
			return (c.empty());
		}
		void pop()
		{
			c.pop_back();
		}
		void push (const value_type& val)
		{
			c.push_back(val);
		}
		size_type size() const
		{
			return (c.size());
		}
		value_type& top()
		{
			return (c.back());
		}
		const value_type& top() const
		{
			return (c.back());
		}
		template <class fT, class fContainer>  
		friend bool operator== (const stack<fT,fContainer>& lhs, const stack<fT,fContainer>& rhs);
		template <class fT, class fContainer>  
		friend bool operator!= (const stack<fT,fContainer>& lhs, const stack<fT,fContainer>& rhs);
		template <class fT, class fContainer>  
		friend bool operator<= (const stack<fT,fContainer>& lhs, const stack<fT,fContainer>& rhs);
		template <class fT, class fContainer>  
		friend bool operator>= (const stack<fT,fContainer>& lhs, const stack<fT,fContainer>& rhs);
		template <class fT, class fContainer>  
		friend bool operator> (const stack<fT,fContainer>& lhs, const stack<fT,fContainer>& rhs);
		template <class fT, class fContainer>  
		friend bool operator< (const stack<fT,fContainer>& lhs, const stack<fT,fContainer>& rhs);


		protected:
		container_type c;

	};
	template <class T, class Container>  
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c == rhs.c);
	}
	template <class T, class Container>  
	bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c != rhs.c);
	}
	template <class T, class Container>  
	bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c < rhs.c);
	}
	template <class T, class Container>  
	bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c <= rhs.c);
	}
	template <class T, class Container>  
	bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c > rhs.c);
	}
	template <class T, class Container>  
	bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c >= rhs.c);
	}

}

#endif