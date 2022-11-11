/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:56:26 by djedasch          #+#    #+#             */
/*   Updated: 2022/11/11 09:46:22 by djedasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft
{

	//todo ft::iterator_traits
	//todo ft::enable_if
	template <bool, typename T = void>
	struct enable_if
	{};

	template <typename T>
	struct enable_if<true, T> {
	typedef T type;
	};

	//todo ft::is_integral
	//todo ft::equal and/or ft::lexicographical_compare
	//todo ft::pair
	//todo ft::make_pair

}
#endif