/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:56:26 by djedasch          #+#    #+#             */
/*   Updated: 2022/11/11 10:47:25 by djedasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft
{

	//todo ft::iterator_traits
	//& ft::enable_if
	template <bool, typename T = void>
	struct enable_if
	{};

	template <typename T>
	struct enable_if<true, T> {
	typedef T type;
	};

	//& ft::is_integral
	 template <class T, T v>
    struct integral_constant 
    {
        static const T value = v;
        typedef T value_type;
    };

    // template <class T, T v> 
    // const T integral_constant<T, v>::value;

    typedef integral_constant<bool, true>  true_type;
    typedef integral_constant<bool, false> false_type;

    template <class T> struct is_integral : public false_type { };

    template <> struct is_integral<bool> : public true_type { };
    template <> struct is_integral<char> : public true_type { };
    template <> struct is_integral<unsigned char> : public true_type { };
    template <> struct is_integral<short> : public true_type { };
    template <> struct is_integral<unsigned short> : public true_type { };
    template <> struct is_integral<int> : public true_type { };
    template <> struct is_integral<unsigned int> : public true_type { };
    template <> struct is_integral<long> : public true_type { };
    template <> struct is_integral<unsigned long> : public true_type { };
    template <> struct is_integral<long long> : public true_type { };
    template <> struct is_integral<unsigned long long> : public true_type { };
	
	//todo ft::equal and/or ft::lexicographical_compare
	//todo ft::pair
	//todo ft::make_pair

}
#endif