/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:55:11 by djedasch          #+#    #+#             */
/*   Updated: 2022/11/24 15:57:44 by djedasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP
# define BST_HPP
#include "utils.hpp"

namespace ft
{
	template <class T1, class T2> 
	struct Node
	{
		pair<T1, T2>	*_data;
		Node 			*_parent;
		Node 			*_left;
		Node 			*_right;

		Node(pair data, Node *parent): _data(data), _parent(parent), _left(NULL), _right(NULL){};
		Node() : _data(new pair()), _parent(NULL), _left(NULL), _right(NULL);
	};

}

#endif