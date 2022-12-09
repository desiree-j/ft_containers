/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:59:50 by djedasch          #+#    #+#             */
/*   Updated: 2022/11/23 16:41:36 by djedasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include <deque>
#include "incl.hpp"
#if 0  //CREATE A REAL STL EXAMPLE
	#include <stack>
	namespace ft = std; 
#else
	#include "stack.hpp"
#endif

#include <stdlib.h>
#include <vector>

int	main(void)
{
	ft::stack<int, ft::vector<int> > st;
	std::cout << "st is empty: " << std::boolalpha << st.empty() << std::endl;
	st.push(5);
	std::cout << "st is empty: " << std::boolalpha << st.empty() << std::endl;
	st.pop();
	std::cout << "st is empty: " << std::boolalpha << st.empty() << std::endl;
	for (int i = 0; i < 5; i++)
	{
		st.push(i);
		std::cout << "top element: " << st.top() << ", size: " << st.size() << std::endl;
	}
	ft::stack<int, ft::vector<int> > st2;
	st2.push(1);
	bool comp = st < st2;
	std::cout << "st < st2: " << std::boolalpha << comp << std::endl;
	comp = st > st2;
	std::cout << "st > st2: " << std::boolalpha << comp << std::endl;
	comp = st >= st2;
	std::cout << "st >= st2: " << std::boolalpha << comp << std::endl;
	comp = st <= st2;
	std::cout << "st <= st2: " << std::boolalpha << comp << std::endl;
	comp = st == st2;
	std::cout << "st == st2: " << std::boolalpha << comp << std::endl;
	comp = st != st2;
	std::cout << "st != st2: " << std::boolalpha << comp << std::endl;

}