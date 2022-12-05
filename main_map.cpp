/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:56:15 by djedasch          #+#    #+#             */
/*   Updated: 2022/12/05 15:26:06 by djedasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>
#include "incl.hpp"
#if  0 //CREATE A REAL STL EXAMPLE
	#include <map>
	namespace ft = std; 
#else
	#include "map.hpp"
#endif

#include <stdlib.h>

template <class T1, class T2>
void	print_map(ft::map<T1, T2> m)
{
	if (m.empty())
		std::cout << "the map is empty";
	else
	{
		for (typename ft::map<T1, T2>::iterator it = m.begin(); it != m.end(); it++)
		{
			std::cout << C_GREEN<<"["<<  it->first << "]=" << it->second << "  ";
		}
	}
	std::cout << C_DEF<< std::endl;
	std::cout << "size: "<<m.size() << std::endl;
}

int main (void)
{
	{ //& constructor, deconstructor
		std::cout << C_BLUE << "default constructor" << C_DEF << std::endl;
		ft::map<int, std::string> m; 
		ft::pair< int, std::string> p(5, "test");
		ft::pair< int, std::string> p2(6, "map");
		ft::pair< int, std::string> p3(3, "insert");
		ft::pair< int, std::string> p4(2, "test");
		ft::pair< int, std::string> p5(16, "map");
		ft::pair< int, std::string> p6(30, "insert");
		std::cout <<"is empty: " << std::boolalpha << m.empty() << std::endl;
		std::cout << "maxsize: " <<m.max_size() << std::endl;
		std::cout << "size: " <<m.size() << std::endl;
		std::cout <<"count(5) = " << m.count(5) << std::endl;
		std::cout << C_BLUE << "insert elements" << C_DEF << std::endl;
		m.insert(p);
		print_map(m);
		m.insert(p2);
		m.insert(p3);
		print_map(m);
		std::cout <<"count(5) = " << m.count(5) << std::endl;
		std::cout <<"count(6) = " << m.count(6) << std::endl;
		std::cout <<"count(4) = " << m.count(4) << std::endl;
		ft::map<int, std::string>::iterator it = m.begin();
		std::cout << C_BLUE << "key of first element" << C_DEF << std::endl;
		std::cout << it->first << std::endl;
		--it;
		std::cout << it->first << std::endl;
		std::cout << C_BLUE << "insert element that is already in map " << C_DEF << std::endl;
		m.insert(p3);
		print_map(m);
		std::cout << C_BLUE << "copy assignment overload" << C_DEF << std::endl;
		ft::map<int, std::string> m2;
		m2. insert(p);
		std::cout << "before: " << std::endl;
		print_map(m2);
		m2 = m; 
		std::cout << "after: " << std::endl;
		print_map(m2);
		std::cout << C_BLUE << "erase element that is not in map " << C_DEF << std::endl;
		m.erase(7);
		print_map(m);
		std::cout << C_BLUE << "erase element that is in map " << C_DEF << std::endl;
		m.erase(3);
		print_map(m);
		m.erase(5);
		print_map(m);
		//m.erase(6);
		print_map(m);
		m2.insert(p4);
		m2.insert(p5);
		m2.insert(p6);
		std::cout << C_BLUE << "insert range " << C_DEF << std::endl;
		m.insert(m2.begin(), m2.end());
		print_map(m2);
		std::cout << C_BLUE << "erase range " << C_DEF << std::endl;
		it = m.begin();
		++it;
		m.erase(m.begin(), it);
		print_map(m);

	}


}