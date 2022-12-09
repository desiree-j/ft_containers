/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:56:15 by djedasch          #+#    #+#             */
/*   Updated: 2022/12/09 14:00:34 by djedasch         ###   ########.fr       */
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
#include <string>
#include <stdlib.h>

template <class T1, class T2>
void	print_map(ft::map<T1, T2> m, std::string name)
{
	if (m.empty())
		std::cout << "the map "<< name <<" is empty";
	else
	{
		std::cout<< C_BLUE << name << " : ";
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
	{ 
		std::cout << C_BLUE << "default constructor" << C_DEF << std::endl;
		ft::map<int, std::string> m; 
		ft::pair< int, std::string> p(5, "a");
		ft::pair< int, std::string> p2(6, "test");
		ft::pair< int, std::string> p3(3, "is");
		ft::pair< int, std::string> p4(2, "this");
		ft::pair< int, std::string> p5(16, "for");
		ft::pair< int, std::string> p6(30, "map");
		ft::pair< int, std::string> pp(5, "an");
		std::cout <<"is empty: " << std::boolalpha << m.empty() << std::endl;
		std::cout << "maxsize: " <<m.max_size() << std::endl;
		std::cout << "size: " <<m.size() << std::endl;
		std::cout <<"count(5) = " << m.count(5) << std::endl;
		std::cout << C_BLUE << "insert elements" << C_DEF << std::endl;
		m.insert(p);
		m.insert(pp);
		print_map(m, "m");
		m.insert(m.begin(), p2);
		m.insert(p3);
		print_map(m, "m");
		std::cout <<"count(5) = " << m.count(5) << std::endl;
		std::cout <<"count(6) = " << m.count(6) << std::endl;
		std::cout <<"count(4) = " << m.count(4) << std::endl;
		std::cout <<"m[3] = " << m[3] << std::endl;
		std::cout <<"m.find(3) = " << m.find(3)->first<< " " << m.find(3)->second << std::endl;
		ft::map<int, std::string>::iterator it = m.begin();
		std::cout << C_BLUE << "key of first element" << C_DEF << std::endl;
		std::cout << it->first << std::endl;
		//--it;
		//std::cout << it->first << std::endl;
		std::cout << "---------------------------------------------------" << std::endl;
		std::cout << C_BLUE << "insert element that is already in map " << C_DEF << std::endl;
		m.insert(p3);
		print_map(m, "m");
		std::cout << C_BLUE << "copy assignment overload" << C_DEF << std::endl;
		ft::map<int, std::string> m2;
		m2. insert(p);
		std::cout << "before: " << std::endl;
		print_map(m2, "m2");
		m2 = m; 
		std::cout << "after: " << std::endl;
		print_map(m2, "m2");
		std::cout << C_BLUE << "erase element that is not in map " << C_DEF << std::endl;
		m.erase(7);
		print_map(m, "m");
		std::cout << C_BLUE << "erase element that is in map " << C_DEF << std::endl;
		m.erase(3);
		print_map(m, "m");
		m.erase(5);
		print_map(m, "m");
		std::cout << C_BLUE << "erase with iterator" << C_DEF << std::endl;
		m.erase(m.begin());
		print_map(m, "m");
		m2.insert(p4);
		m2.insert(p5);
		m2.insert(p6);
		print_map(m2, "m2");
		std::cout << C_BLUE << "insert range " << C_DEF << std::endl;
		it = m2.end();
		std::cout << (--(--it))->first << std::endl;
		//--it;
		//--it;
		m.insert(m2.begin(), it);
		print_map(m, "m");
		std::cout << C_BLUE << "erase range " << C_DEF << std::endl;
		it = m.begin();
		++it;
		it++;
		m.erase(m.begin(), it);
		print_map(m, "m");
		std::cout << C_BLUE << "range constructor " << C_DEF << std::endl;
		ft::map<int, std::string> m3(m2.begin(), m2.end());
		print_map(m3, "m3");
		std::cout << C_BLUE << "clear " << C_DEF << std::endl;
		m3.clear();
		print_map(m3, "m3");
		std::cout << "---------------------------------------------------" << std::endl;
		std::cout << C_BLUE << "swap " << C_DEF << std::endl;
		std::cout << "before: " << std::endl;
		print_map(m, "m");
		print_map(m2, "m2");
		m2.swap(m);
		std::cout << "after: " << std::endl;
		print_map(m, "m");
		print_map(m2, "m2");
		std::cout << C_BLUE << "non member function swap " << C_DEF << std::endl;	
		std::cout << "before: " << std::endl;
		print_map(m, "m");
		print_map(m2, "m2");
		swap(m, m2);
		std::cout << "after: " << std::endl;
		print_map(m, "m");
		print_map(m2, "m2");

		std::cout << "---------------------------------------------------" << std::endl;
		std::cout << C_BLUE << "comparision" << C_DEF << std::endl;	
		bool comp = (m < m2);
		std::cout << "m < m2: " << std::boolalpha << comp << std::endl;
		comp = m > m2;
		std::cout << "m > m2: " << std::boolalpha << comp << std::endl;
		comp = m >= m2;
		std::cout << "m >= m2: " << std::boolalpha << comp << std::endl;
		comp = m <= m2;
		std::cout << "m <= m2: " << std::boolalpha << comp << std::endl;
		comp = m == m2;
		std::cout << "m == m2: " << std::boolalpha << comp << std::endl;
		comp = m != m2;
		std::cout << "m != m2: " << std::boolalpha << comp << std::endl;
		std::cout << "---------------------------------------------------" << std::endl;

		std::cout << C_BLUE << "value_compare" << C_DEF << std::endl;
		ft::map<int, std::string>::iterator it2 = m.begin();
		ft::map<int, std::string>::iterator it3 = m.begin();
		it3++;
		std::cout << " *it2 < *it3: "<<std::boolalpha << m.value_comp()(*it2, *it3) << std::endl;
		std::cout << " p < p2: "<<std::boolalpha << m.value_comp()(p, p2) << std::endl;
		std::cout << C_BLUE << "key_compare" << C_DEF << std::endl;
		std::cout << " p < p2: "<<std::boolalpha << m.key_comp()(p.first, p2.first) << std::endl;

		std::cout << "---------------------------------------------------" << std::endl;
		std::cout << C_BLUE << "lower bound" << C_DEF << std::endl;
		std::cout << "m2.lower_bound(3): " << m2.lower_bound(3)->first << std::endl;
		std::cout << C_BLUE << "upper bound" << C_DEF << std::endl;
		std::cout << "m2.upper_bound(3): " << m2.upper_bound(3)->first << std::endl;
		std::cout << C_BLUE << "equal range" << C_DEF << std::endl;
		std::cout << "m2.equal_range(3): " << m2.equal_range(3).first->first << " " << m2.equal_range(3).second->first<< std::endl;
		std::cout << "---------------------------------------------------" << std::endl;
		const ft::map<int, std::string> m4(m2.begin(), m2.end());
		std::cout << C_BLUE << "const lower bound" << C_DEF << std::endl;
		std::cout << "m4.lower_bound(3): " << m4.lower_bound(3)->first << std::endl;
		std::cout << C_BLUE << "const upper bound" << C_DEF << std::endl;
		std::cout << "m4.upper_bound(3): " << m4.upper_bound(3)->first << std::endl;
		std::cout << C_BLUE << "const equal range" << C_DEF << std::endl;
		std::cout << "m4.equal_range(3): " << m4.equal_range(3).first->first << " " << m4.equal_range(3).second->first<< std::endl;
		std::cout <<"m4.find(3) = " << m4.find(3)->first<< " " << m4.find(3)->second << std::endl;
		std::cout << C_BLUE << "const value_compare" << C_DEF << std::endl;
		ft::map<int, std::string>::const_iterator it4 = m4.begin();
		ft::map<int, std::string>::const_iterator it5 = m4.begin();
		it4++;
		std::cout << " *it2 < *it3: "<<std::boolalpha << m4.value_comp()(*it4, *it5) << std::endl;
		std::cout << " p < p2: "<<std::boolalpha << m.key_comp()(it4->first, it5->first) << std::endl;
		m[9] = "checking";
		print_map(m, "m");
		std::cout <<(*it).second << std::endl;
		std::cout <<(*it4).second << std::endl;
	}

}