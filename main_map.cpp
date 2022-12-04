/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:56:15 by djedasch          #+#    #+#             */
/*   Updated: 2022/12/04 10:01:13 by djedasch         ###   ########.fr       */
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
		std::cout << "insert 2" << std::endl;
		m.insert(p2);
		m.insert(p3);
		std::cout << m.count(5) << std::endl;
		std::cout << m.count(6) << std::endl;
		std::cout << m.count(4) << std::endl;
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
		m.erase(5);
		std::cout << m.size() << std::endl;
	}


}