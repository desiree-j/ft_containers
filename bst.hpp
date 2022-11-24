/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:55:11 by djedasch          #+#    #+#             */
/*   Updated: 2022/11/24 12:57:44 by djedasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP
# define BST_HPP
#include "utils.hpp"

namespace ft
{
	struct Node
	{
		pair		_data;
		Node 		*_parent;
		Node 		*_left;
		Node 		*_right;

		Node(pair data, Node *parent): _data(data), _parent(parent), _left(NULL), _right(NULL){};
	};

	//class BST
	//{
	//	private:
	//	Node *_root;
	//}
}

#endif