/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:29:11 by djedasch          #+#    #+#             */
/*   Updated: 2022/11/14 17:34:31 by djedasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>
#include "incl.hpp"
#if 0 //CREATE A REAL STL EXAMPLE
	#include <vector>
	namespace ft = std;
#else
	#include "vector.hpp"
#endif

#include <stdlib.h>

int main(void) 
{
	//{	//&constructor, destructor
	//	std::cout << C_RED << "Test constructors" << C_DEF << std::endl;
	//	std::cout << C_BLUE << "default constructor" << C_DEF << std::endl;
	//	ft::vector<int> vec;
	//	std::cout << "size "<<vec.size() << ", capa " << vec.capacity() << std::endl;
	//	std::cout << C_BLUE << "constructor 2 (fill)" << C_DEF << std::endl;
	//	ft::vector<int> vec2(5,5);
	//	std::cout << "size "<<vec2.size() << ", capa " << vec2.capacity() << std::endl;
	//	//todo range constructor
	//	std::cout << C_BLUE << "copy constructor" << C_DEF << std::endl;
	//	ft::vector<int> vec3(vec2);
	//	std::cout << "size "<<vec3.size() << ", capa " << vec3.capacity() << std::endl;
	//	std::cout << C_BLUE << "copy assignment overload constructor" << C_DEF << std::endl;
	//	ft::vector<int> vec4(6,6);
	//	vec4 = vec3;
	//	//todo get_allocator
	//	//todo check memory leaks
	//}
	//{	//&capacity
	//	//todo empty, resize
	//	std::cout << C_RED << "Test capacity" << C_DEF << std::endl;
	//	std::cout << C_BLUE << "default constructor" << C_DEF << std::endl;
	//	ft::vector<int> vec;
	//	std::cout << "vec is empty: " <<std::boolalpha <<  vec.empty() << std::endl;
	//	std::cout << "size "<<vec.size() << ", capa " << vec.capacity() << std::endl;
	//	std::cout << C_BLUE << "constructor 2 with size 5" << C_DEF << std::endl;
	//	ft::vector<int> vec2(5,5);
	//	std::cout << "vec2 is empty: "<<std::boolalpha << vec2.empty() << std::endl;
	//	std::cout << "size "<<vec2.size() << ", capa " << vec2.capacity() << std::endl;
	//	std::cout << C_BLUE << "copy constructor" << C_DEF << std::endl;
	//	ft::vector<int> vec3(vec2);
	//	std::cout << "size "<<vec3.size() << ", capa " << vec3.capacity() << std::endl;
	//	vec3.push_back(12);
	//	std::cout << "size "<<vec3.size() << ", capa " << vec3.capacity() << std::endl;
	//	ft::vector<int> vec4(6,6);
	//	std::cout << C_BLUE << "add to empty vector" << C_DEF << std::endl;
	//	for(int i = 0; i < 15; i++)
	//	{
	//		vec2.push_back(i);
	//		std::cout << "size "<<vec2.size() << ", capa " << vec2.capacity() << std::endl;
	//	}
	//	std::cout << C_BLUE << "reserve space" << C_DEF << std::endl;
	//	std::cout << "size "<<vec3.size() << ", capa " << vec3.capacity() << std::endl;
	//	vec3.reserve(18);
	//	std::cout << "size "<<vec3.size() << ", capa " << vec3.capacity() << std::endl;
	//	std::cout << C_BLUE << "pop back on empty vector" << C_DEF << std::endl;
	//	vec.pop_back();
	//	std::cout << "size "<<vec.size() << ", capa " << vec.capacity() << std::endl;
	//	std::cout << "max_size: " << vec.max_size() << std::endl;
	//}
	{	//& modifiers
		std::cout << C_RED << "Test modifier functions" << C_DEF << std::endl;
		ft::vector<int> vec;	
		std::cout << C_BLUE << "before erase" << C_DEF << std::endl;
		for(int i = 0; i < 15; i++)
		{
			vec.push_back(i);
			std::cout << "element "<< i << " = " << vec[i] << std::endl;
			//std::cout << "size "<<vec2.size() << ", capa " << vec2.capacity() << std::endl;
		}
		ft::vector<int>::iterator it = vec.begin();
		ft::vector<int>::iterator it2 = vec.end() - 5;
		it = vec.erase(it);
		vec.insert(it, 42);
		it++;
		//it2 = it + 5;
		it += 2;
		it = vec.erase(it, it2);
		std::cout << C_BLUE << "after erase" << C_DEF << std::endl;
		for(size_t i = 0; i < vec.size(); i++)
		{
			std::cout << "element "<< i << " = " << vec[i] << std::endl;
		}
		//vec.insert(it, 5, 24);
		//std::cout << C_BLUE << "after insert" << C_DEF << std::endl;
		//for(size_t i = 0; i < vec.size(); i++)
		//{
		//	std::cout << "element "<< i << " = " << vec[i] << std::endl;
		//}
		//std::cout << "size "<<vec.size() << ", capa " << vec.capacity() << std::endl;

	}

	//{	//& element access
	//	std::cout << C_RED << "Test element access functions" << C_DEF << std::endl;
	//	ft::vector<int> vec;	
	//	const ft::vector<int> vec2(10, 1);	
	//	for(int i = 0; i < 15; i++)
	//	{
	//		vec.push_back(i);
	//		std::cout << "size "<<vec.size() << ", capa " << vec.capacity() << std::endl;

	//	}
	//	std::cout << C_BLUE << "front of vec" << C_DEF << std::endl;
	//	std::cout << vec.front() << std::endl;
	//	std::cout << C_BLUE << "back of vec" << C_DEF << std::endl;
	//	std::cout << vec.back() << std::endl;
	//	std::cout << C_BLUE << "at position 6 of vec" << C_DEF << std::endl;
	//	std::cout << vec.at(6) << std::endl;
	//	std::cout << C_BLUE << " [6] of vec" << C_DEF << std::endl;
	//	std::cout << vec[6] << std::endl;

	//	std::cout << C_RED << "Test const element access functions" << C_DEF << std::endl;
	//	std::cout << C_BLUE << "front of vec2" << C_DEF << std::endl;
	//	std::cout << vec2.front() << std::endl;
	//	std::cout << C_BLUE << "back of vec2" << C_DEF << std::endl;
	//	std::cout << vec2.back() << std::endl;
	//	std::cout << C_BLUE << "at position 6 of vec2" << C_DEF << std::endl;
	//	std::cout << vec2.at(6) << std::endl;
	//	std::cout << C_BLUE << " [6] of vec2" << C_DEF << std::endl;
	//	std::cout << vec2[6] << std::endl;
	//}
	//{	//& comparison
	//	ft::vector<int> vec(5,5);
	//	ft::vector<int> vec2(vec);
	//	vec2.push_back(1);
	//	std::cout << std::endl << C_RED << "vector comparison" << C_DEF << std::endl;
	//	bool comp = vec < vec2;
	//	std::cout << "vec < vec2: " << std::boolalpha << comp << std::endl;
	//	comp = vec > vec2;
	//	std::cout << "vec > vec2: " << std::boolalpha << comp << std::endl;
	//	comp = vec >= vec2;
	//	std::cout << "vec >= vec2: " << std::boolalpha << comp << std::endl;
	//	comp = vec <= vec2;
	//	std::cout << "vec <= vec2: " << std::boolalpha << comp << std::endl;
	//}
	//{	//&i vector iterator
	//	std::cout << C_RED << "iterator test" << C_DEF << std::endl;
	//	ft::vector<int> vec;
	//	for (int i = 0; i< 5; i++)
	//	{
	//		vec.push_back(i);
	//	}
	//	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	//	{
	//		std::cout << *it << std::endl;
	//		//std::cout << "test" << std::endl;
	//	}
	//	ft::vector<int>::iterator it2 = vec.begin();
	//	ft::vector<int>::iterator it3 = vec.begin();
	//	*it2++;
	//	std::cout << *it2 << std::endl;
	//	*it2 = 42;
	//	it2 = it2 + 2;
	//	it2 = 1 + it2;
	//	it2 -= 2;
	//	//it2 = it3;
	//	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	//	{
	//		std::cout << *it << std::endl;
	//	}
	//	std::cout << "*it2 = " << *it2 << ", *it3 = " << *it3 <<std::endl;
	//	std::cout << C_BLUE << "iterator comparison" << C_DEF << std::endl;
	//	bool comp = it2 < it3;
	//	std::cout << "it2 < it3: " << std::boolalpha << comp << std::endl;
	//	comp = it2 > it3;
	//	std::cout << "it2 > it3: " << std::boolalpha << comp << std::endl;
	//	comp = it2 <= it3;
	//	std::cout << "it2 <= it3: " << std::boolalpha << comp << std::endl;
	//	comp = it2 >= it3;
	//	std::cout << "it2 >= it3: " << std::boolalpha << comp << std::endl;


	//}
}