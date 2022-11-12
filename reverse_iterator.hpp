/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:53:38 by djedasch          #+#    #+#             */
/*   Updated: 2022/11/12 08:50:23 by djedasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft
{

	template< class Iter >
	class reverse_iterator
	//class reverse_iterator : std::iterator<std::iterator_traits<Iter>::iterator_category
	//, std::iterator_traits<Iter>::value_type
	//, std::iterator_traits<Iter>::difference_type
	//, std::iterator_traits<Iter>::pointer
	//, std::iterator_traits<Iter>::reference>
	{
		public:
			typedef	Iter											iterator_type;
			typedef std::iterator_traits<Iter>::pointer				pointer;
			typedef std::iterator_traits<Iter>::reference			reference;
			typedef std::iterator_traits<Iter>::value_type			value_type;
			typedef std::iterator_traits<Iter>::difference_type		difference_type;
			typedef std::iterator_traits<Iter>::iterator_category	iterator_category;

		public:
			reverse_iterator() : _it(Iter()){}
			reverse_iterator(Iter it) : _it(it){}
			~reverse_iterator(void) : ~Iter(){}
			reverse_iterator(const reverse_iterator& rhs) 
			reverse_iterator& operator=(const reverse_iterator& rhs)
		private:
			Iter _it;

	};
}

#endif