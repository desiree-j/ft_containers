/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:56:26 by djedasch          #+#    #+#             */
/*   Updated: 2022/11/23 14:40:38 by djedasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft
{

	//& ft::iterator_traits
    template <class Iterator> 
    class iterator_traits
    {
        typedef typename Iterator::value_type            value_type;
        typedef typename Iterator::difference_type       difference_type;
        typedef typename Iterator::iterator_category     iterator_category;
        typedef typename Iterator::pointer               pointer;
        typedef typename Iterator::reference             reference;
    }
    template <class T> 
    class iterator_traits<T*>
    {
        typedef ptrdiff_t                    difference_type;
        typedef T                            value_type;
        typedef T*                           pointer;
        typedef T&                           reference;
        typedef random_access_iterator_tag   iterator_category;
    }
    template <class T> 
    class iterator_traits<const T*>
    {
        typedef ptrdiff_t                    difference_type;
        typedef T                            value_type;
        typedef const T*                     pointer;
        typedef const T&                     reference;
        typedef random_access_iterator_tag   iterator_category;
    }


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
    template <class T1, class T2> 
    struct pair
    {
        typedef T1 first_type;
        typedef T2 second_type;

        public:
        pair();
        template<class U, class V> pair (const pair<U,V>& pr);
        pair (const first_type& a, const second_type& b);

        private:
        first_type  first;
        second_type second;
    }
    
	//todo ft::make_pair

}
#endif