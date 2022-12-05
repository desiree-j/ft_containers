/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:56:15 by djedasch          #+#    #+#             */
/*   Updated: 2022/12/05 13:25:03 by djedasch         ###   ########.fr       */
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
		std::cout << "the vector is empty";
	else
	{
		std::cout << C_YELLOW <<"all elements" << C_DEF << std:: endl;
		for (typename ft::map<T1, T2>::iterator it = m.begin(); it != m.end(); it++)
		{
			std::cout << C_GREEN<<"["<<  it->first << "]=" << it->second << "  ";
		}
	}
	std::cout << C_DEF<< std::endl;
}

int main (void)
{
	{ //& constructor, deconstructor
		ft::map<int, std::string> m; 
		ft::pair< int, std::string> p(5, "test");
		ft::pair< int, std::string> p2(6, "map");
		ft::pair< int, std::string> p3(3, "insert");
		std::cout << m.empty() << std::endl;
		std::cout << m.max_size() << std::endl;
		std::cout << m.size() << std::endl;
		std::cout << m.count(5) << std::endl;
		m.insert(p);
		print_map(m);
		m.insert(p2);
		m.insert(p3);
		print_map(m);
		std::cout <<"count(5) = " << m.count(5) << std::endl;
		std::cout <<"count(6) = " << m.count(6) << std::endl;
		std::cout <<"count(4) = " << m.count(4) << std::endl;
		ft::map<int, std::string>::iterator it = m.begin();
		std::cout << it->first << std::endl;
		--it;
		std::cout << it->first << std::endl;
		m.insert(p3);
		std::cout << m.size() << std::endl;
		m.erase(7);
		std::cout << m.size() << std::endl;
		m.erase(3);
		std::cout << m.size() << std::endl;
		m.erase(6);
		//m.erase(5);
		std::cout << m.size() << std::endl;
	}


}