/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:29:11 by djedasch          #+#    #+#             */
/*   Updated: 2022/11/23 18:13:30 by djedasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>
#include "incl.hpp"
#if 1  //CREATE A REAL STL EXAMPLE
	#include <vector>
	namespace ft = std; 
#else
	#include "vector.hpp"
#endif

#include <stdlib.h>

template <class T>
void	print_vector(ft::vector<T> vec)
{
	if (vec.empty())
		std::cout << "the vector is empty";
	else
	{
		std::cout << C_YELLOW <<"all elements" << C_DEF << std:: endl;
		for (size_t i = 0; i < vec.size(); i++)
		{
			std::cout << vec[i] << " ";
		}
	}
	std::cout << std::endl;
}

int main(void) 
{
	{	//&constructor, destructor
		std::cout << C_MAGENTA << "Test constructors" << C_DEF << std::endl;
		std::cout << "---------------------------------------------------" << std::endl;
		std::cout << C_BLUE << "default constructor" << C_DEF << std::endl;
		ft::vector<int> vec;
		print_vector(vec);
		std::cout << C_BLUE << "constructor 2 (fill)" << C_DEF << std::endl;
		ft::vector<int> vec2(5,5);
		print_vector(vec2);
		std::cout << C_BLUE << "constructor 3 (range)" << C_DEF << std::endl;
		ft::vector<int>vec5(vec2.begin(), vec2.end());
		print_vector(vec5);
		std::cout << C_BLUE << "copy constructor" << C_DEF << std::endl;
		ft::vector<int> vec3(vec2);
		print_vector(vec3);
		std::cout << C_BLUE << "copy assignment overload constructor" << C_DEF << std::endl;
		ft::vector<int> vec4(6,6);
		print_vector(vec4);
		vec4 = vec3;
		print_vector(vec3);
		//todo get_allocator
		std::cout << "---------------------------------------------------" << std::endl;
	}
	{	//&capacity
		std::cout<< std::endl<< C_MAGENTA << "Test capacity" << C_DEF << std::endl;
		std::cout << C_BLUE << "default constructor" << C_DEF << std::endl;
		ft::vector<int> vec;
		print_vector(vec);
		std::cout << "size "<<vec.size() << ", capacity " << vec.capacity() << std::endl;
		std::cout << C_BLUE << "constructor 2 with size 5" << C_DEF << std::endl;
		ft::vector<int> vec2(5,5);
		print_vector(vec2);
		std::cout << "size "<<vec2.size() << ", capacity " << vec2.capacity() << std::endl;
		ft::vector<int> vec3(vec2);
		vec3.push_back(12);
		ft::vector<int> vec4(6,6);
		std::cout << C_BLUE << "add to empty vector" << C_DEF << std::endl;
		for(int i = 0; i < 14; i++)
		{
			vec.push_back(i);
			print_vector(vec);
			std::cout << "size "<<vec.size() << ", capacity " << vec.capacity() << std::endl;
		}
		std::cout << C_BLUE << "resize to 20" << C_DEF << std::endl;
		vec.resize(20, 5);
		print_vector(vec);
		std::cout << C_BLUE << "reserve space" << C_DEF << std::endl;
		std::cout << C_BLUE << "before" << C_DEF << std::endl;
		print_vector(vec3);
		std::cout << "size "<<vec3.size() << ", capacity " << vec3.capacity() << std::endl;
		vec3.reserve(18);
		std::cout << C_BLUE << "after" << C_DEF << std::endl;
		print_vector(vec3);
		std::cout << "size "<<vec3.size() << ", capacity " << vec3.capacity() << std::endl;
		std::cout <<  C_BLUE <<"max_size: " << vec.max_size() << C_DEF << std::endl;
		std::cout << "---------------------------------------------------" << std::endl;
	}

	{ //&insert
		std::cout << C_MAGENTA << "Test insert" << C_DEF << std::endl;
		ft::vector<int> vec;
		ft::vector<int>::iterator it = vec.begin();
		it = vec.insert(it, 42);
		std::cout << "new element "<< *it << std::endl;
		for(int i = 0; i < 15; i++)
		{
			vec.push_back(i);
		}
		print_vector(vec);
		it = vec.begin();
		it = vec.insert(it, 33);
		std::cout << "new element "<< *it << std::endl;
		print_vector(vec);
		vec.insert(vec.end(), 33, 42);
		print_vector(vec);
		std::cout << "---------------------------------------------------" << std::endl;
	}
	{	//& modifiers
		std::cout << C_MAGENTA << "Test modifier functions" << C_DEF << std::endl;
		ft::vector<int> vec(1, 1);	
		std::cout << C_BLUE << "before erase" << C_DEF << std::endl;
		for(int i = 0; i < 15; i++)
		{
			vec.push_back(i);
		}
		print_vector(vec);
		ft::vector<int>::iterator it = vec.begin();
		it = vec.insert(it, 42);
		std::cout << "new element = " << *it << std::endl;
		std::cout << C_BLUE << "after erase" << C_DEF << std::endl;
		print_vector(vec);
		
		ft::vector<int> vec2(7, 1);	
		std::cout << C_BLUE << "swap vec and vec2" << C_DEF << std::endl;
		std::cout << C_BLUE << "before" << C_DEF << std::endl;
		print_vector(vec);
		std::cout << "size "<<vec.size() << ", capacity " << vec.capacity() << std::endl;
		print_vector(vec2);
		std::cout << "size "<<vec2.size() << ", capacity " << vec2.capacity() << std::endl;
		vec.swap(vec2);
		std::cout << C_BLUE << "after" << C_DEF << std::endl;
		print_vector(vec);
		std::cout << "size "<<vec.size() << ", capacity " << vec.capacity() << std::endl;
		print_vector(vec2);
		std::cout << "size "<<vec2.size() << ", capacity " << vec2.capacity() << std::endl;
		
		std::cout << C_BLUE << "assign size 25, value 5" << C_DEF << std::endl;
		print_vector(vec2);
		vec.assign(25, 5);
		print_vector(vec);
		std::cout << C_BLUE << "assign range" << C_DEF << std::endl;
		it = vec.begin();
		ft::vector<int>::iterator it2 = vec.end();
		vec2.assign(it, it2);
		print_vector(vec2);
		std::cout << "---------------------------------------------------" << std::endl;
	}

	{	//& element access
		std::cout << std::endl << C_MAGENTA << "Test element access functions" << C_DEF << std::endl;
		ft::vector<int> vec;	
		for(int i = 0; i < 15; i++)
		{
			vec.push_back(i);
		}
		const ft::vector<int> vec2(vec.begin(), vec.end() - 3);	
		print_vector(vec);
		std::cout << C_BLUE << "front of vec" << C_DEF << std::endl;
		std::cout << vec.front() << std::endl;
		std::cout << C_BLUE << "back of vec" << C_DEF << std::endl;
		std::cout << vec.back() << std::endl;
		std::cout << C_BLUE << "at position 6 of vec" << C_DEF << std::endl;
		std::cout << vec.at(6) << std::endl;
		std::cout << C_BLUE << " [7] of vec" << C_DEF << std::endl;
		std::cout << vec[7] << std::endl;
		std::cout << C_MAGENTA << "Test const element access functions" << C_DEF << std::endl;
		print_vector(vec2);
		std::cout << C_BLUE << "front of vec2" << C_DEF << std::endl;
		std::cout << vec2.front() << std::endl;
		std::cout << C_BLUE << "back of vec2" << C_DEF << std::endl;
		std::cout << vec2.back() << std::endl;
		std::cout << C_BLUE << "at position 6 of vec2" << C_DEF << std::endl;
		std::cout << vec2.at(6) << std::endl;
		std::cout << C_BLUE << " [7] of vec2" << C_DEF << std::endl;
		std::cout << vec2[7] << std::endl;
		std::cout << "---------------------------------------------------" << std::endl;
	}

	{	//& comparison
		ft::vector<int> vec(5,5);
		ft::vector<int> vec2(vec);
		vec2.push_back(1);
		print_vector(vec);
		print_vector(vec2);
		std::cout << std::endl << C_MAGENTA << "vector comparison" << C_DEF << std::endl;
		bool comp = vec < vec2;
		std::cout << "vec < vec2: " << std::boolalpha << comp << std::endl;
		comp = vec > vec2;
		std::cout << "vec > vec2: " << std::boolalpha << comp << std::endl;
		comp = vec >= vec2;
		std::cout << "vec >= vec2: " << std::boolalpha << comp << std::endl;
		comp = vec <= vec2;
		std::cout << "vec <= vec2: " << std::boolalpha << comp << std::endl;
		comp = vec == vec2;
		std::cout << "vec == vec2: " << std::boolalpha << comp << std::endl;
		comp = vec != vec2;
		std::cout << "vec != vec2: " << std::boolalpha << comp << std::endl;
		std::cout << "---------------------------------------------------" << std::endl;
	}

	{	//&i vector iterator
		std::cout << C_MAGENTA << "iterator test" << C_DEF << std::endl;
		ft::vector<int> vec;
		for (int i = 0; i< 5; i++)
		{
			vec.push_back(i);
		}
		std::cout << C_YELLOW <<"all elements" << C_DEF << std:: endl;
		for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		{
			std::cout << *it << ", ";
		}
		std::cout << std::endl;
		ft::vector<int>::iterator it2 = vec.begin();
		ft::vector<int>::iterator it3 = vec.begin();
		std::cout << "*it2: "<<*it2 << std::endl;
		std::cout << "*it2++: "<< *(it2++) << std::endl; 
		std::cout << "*it2: "<<*it2 << std::endl;
		std::cout << "*it2[0]: "<< it2[0] << std::endl; 
		it2[0] = 23;
		std::cout << "*it2[0] = 23: "<< it2[0] << std::endl; 
		std::cout << "*++it2: "<< *++it2 << std::endl; 
		*it2 = 42;
		std::cout << C_BLUE <<"all elements" << C_DEF << std:: endl;
		for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		{
			std::cout << *it << ", ";
		}
		std::cout << std::endl;
		it2 = it2 + 2;
		std::cout << "it2 = it2 + 2; "<<*it2 << std::endl;
		it2 = 1 + it2;
		std::cout << "it2 = 1 + it2; "<< *it2 << std::endl;
		it2 -= 2;
		std::cout << "it2 -= 2; "<<*it2 << std::endl;
		it2 = it3;
		std::cout <<"it2 + 2: "<< *(it2 + 2) << std::endl;
		std::cout << "it2:"<< *it2 << std::endl;
		std::cout << "*it2 = " << *it2 << ", *it3 = " << *it3 <<std::endl;
		std::cout << C_BLUE << "iterator comparison" << C_DEF << std::endl;
		bool comp = it2 < it3;
		std::cout << "it2 < it3: " << std::boolalpha << comp << std::endl;
		comp = it2 > it3;
		std::cout << "it2 > it3: " << std::boolalpha << comp << std::endl;
		comp = it2 <= it3;
		std::cout << "it2 <= it3: " << std::boolalpha << comp << std::endl;
		comp = it2 >= it3;
		std::cout << "it2 >= it3: " << std::boolalpha << comp << std::endl;
		comp = it2 == it3;
		std::cout << "it2 == it3: " << std::boolalpha << comp << std::endl;
		comp = it2 != it3;
		std::cout << "it2 != it3: " << std::boolalpha << comp << std::endl;

		std::cout << C_BLUE << "const iterator" << C_DEF << std::endl;
		const ft::vector<int> cvec(10, 5);
		for (ft::vector<int>::const_iterator cit = cvec.begin(); cit != cvec.end(); cit++)
		{
			std::cout << *cit << " ";
			//*cit+=2;
		}
		std::cout << std::endl;
		for (ft::vector<int>::const_iterator cit = cvec.begin(); cit != cvec.end(); cit++)
		{
			std::cout << *cit << " ";
		}
		std::cout << std::endl;
	}
}