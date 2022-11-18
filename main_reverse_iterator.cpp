/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_reverse_iterator.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:09:01 by djedasch          #+#    #+#             */
/*   Updated: 2022/11/18 12:33:29 by djedasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include "incl.hpp"
#if 0 //CREATE A REAL STL EXAMPLE
	namespace ft = std;
#else
	#include "utils.hpp"
	#include "reverse_iterator.hpp"
#endif

#include <stdlib.h>

int	main(void)
{
	std::vector<int> vec;
	for(int i = 0; i < 15; i++)
	{
		vec.push_back(i);
	}
	std::vector<int>::iterator it = vec.begin();
	it+=2;
	ft::reverse_iterator<std::vector<int>::iterator> rev(it);
	std::cout << *it <<" "<<*rev << std::endl;
	std::cout << *(rev++) << std::endl;
	std::cout << *rev << std::endl;
	std::cout << *(rev--) << std::endl;
	std::cout << *rev << std::endl;
	std::cout << *(rev - 2) << std::endl;
	std::cout << *rev << std::endl;
	std::cout << *rev.base() << std::endl;
	std::cout << *rev << std::endl;
	rev[0] = 42;
	std::cout << rev[0] << std::endl;

}