/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:56:26 by djedasch          #+#    #+#             */
/*   Updated: 2022/12/11 09:04:47 by djedasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP
#include <cstddef>
#include <iterator>

namespace ft
{

	//& ft::iterator_traits
    template <class Iterator> 
    class iterator_traits
    {
        public:
        typedef typename Iterator::value_type            value_type;
        typedef typename Iterator::difference_type       difference_type;
        typedef typename Iterator::iterator_category     iterator_category;
        typedef typename Iterator::pointer               pointer;
        typedef typename Iterator::reference             reference;
    };
    template <class T> 
    class iterator_traits<T*>
    {
        public:
        typedef ptrdiff_t                	    difference_type;
        typedef T                        	    value_type;
        typedef T*                     	    	pointer;
        typedef T&                          	reference;
        typedef std::random_access_iterator_tag iterator_category;
    };
    template <class T> 
    class iterator_traits<const T*>
    {
        public:
        typedef ptrdiff_t           	         difference_type;
        typedef T               	             value_type;
        typedef const T*    	                 pointer;
        typedef const T&	                     reference;
        typedef std::random_access_iterator_tag  iterator_category;
    };


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
	
	//& ft::equal 
    template <class InputIterator1, class InputIterator2>  
    bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
        while (first1!=last1) 
        {
            if (!(*first1 == *first2))
                return false;
            ++first1; 
			++first2;
        }
        return true;
    }
    template <class InputIterator1, class InputIterator2, class BinaryPredicate>  
    bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
    {
        while (first1!=last1) 
        {
            if (!pred(*first1,*first2))
                return false;
            ++first1; 
			++first2;
        }
        return true;
    }

	//& ft::lexicographical_compare
	template <class InputIterator1, class InputIterator2>  
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1) 
				return false;
			else if (*first1<*first2) 
				return true;
			++first1;
			++first2;
		}
		return (first2!=last2);
	}
	template <class InputIterator1, class InputIterator2, class Compare>  
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while (first1!=last1)
		{
			if (first2==last2 || comp(*first2,*first1)) 
				return false;
			else if (comp(*first1,*first2)) 
				return true;
			++first1;
			++first2;
		}
		return (first2!=last2);
	}

    
	//& ft::pair
    template <class T1, class T2> 
    struct pair
    {
        typedef T1 first_type;
        typedef T2 second_type;

        pair() : first(first_type()), second(second_type()) {}
        template<class U, class V> 
        pair (const pair<U,V>& pr) : first(first_type(pr.first)), second(second_type(pr.second)){ }
        pair (const first_type& a, const second_type& b) : first(a), second(b) {}
        pair& operator= (const pair& pr)
        {
            this->~pair();
            new(this) pair(pr.first, pr.second);
            //this->first = first_type(pr.first);
            //this->second = second_type(pr.second);
            return (*this);            
        }
        first_type  first;
        second_type second;
    };
    template <class T1, class T2>  
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}
    template <class T1, class T2>  
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (!(lhs == rhs));
	}
    template <class T1, class T2>  
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first < rhs.first && lhs.second < rhs.second);
	}
    template <class T1, class T2>  
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (!(lhs > rhs));
	}
    template <class T1, class T2>  
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (rhs < lhs);
	}
    template <class T1, class T2>  
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (!(lhs < rhs));
	}
    
	//& ft::make_pair
    template <class T1, class T2>  
    pair<T1,T2> make_pair (T1 x, T2 y)
    {
        return (pair<T1,T2>(x,y));
    }

    //& Node for tree (map)
    template <class T1, class T2> 
	struct Node
	{
		pair<const T1, T2>	*_data;
		Node 		        *_parent;
		Node 		        *_left;
		Node 		        *_right;

		Node() : _data(new ft::pair<const T1, T2>()), _parent(NULL), _left(NULL), _right(NULL){}
        Node *left() { return (this->_left);}
        Node *right() { return(this->_right);}
        Node *parent() { return(this->_parent);}
	};

}
#endif