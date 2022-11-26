/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:56:15 by djedasch          #+#    #+#             */
/*   Updated: 2022/11/26 10:08:06 by djedasch         ###   ########.fr       */
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
		ft::pair<int, std::string> p(5, "test");
		std::cout << m.empty() << std::endl;
		std::cout << m.max_size() << std::endl;
		std::cout << m.size() << std::endl;
		std::cout << m.count(5) << std::endl;
		m.insert(p);
		
	}


}