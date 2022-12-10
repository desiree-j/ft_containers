/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 09:23:05 by djedasch          #+#    #+#             */
/*   Updated: 2022/12/10 09:49:36 by djedasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATOR_HPP
# define MAPITERATOR_HPP
# include "utils.hpp"

namespace ft
{
	template <typename nodePtr, typename valType>
	class mapIterator
	{
		public:
		typedef valType*								pointer;
		typedef valType&								reference;
		typedef valType									value_type;
		typedef const value_type&						const_reference;
		typedef std::ptrdiff_t 							difference_type;
		typedef std::bidirectional_iterator_tag			iterator_category;
		//typedef typename map::size_type				size_type;
		//typedef typename value_type::first_type			key_type;
		//typedef typename map::key_compare				key_compare;
		typedef nodePtr									node_pointer;
		

		public:
		mapIterator() : _ptr(NULL), _root(NULL) {}
		mapIterator(node_pointer ptr, node_pointer root) : _ptr(ptr), _root(root){}
		~mapIterator(void){}
		mapIterator(const mapIterator& rhs): _ptr(rhs._ptr), _root(rhs._root){}
		template<typename node, typename val>
		mapIterator(mapIterator<node, val> &copy) : _ptr(copy.base()) , _root(copy.getRoot()) {}
		mapIterator& operator=(const mapIterator& rhs)
		{
			this->_ptr = rhs._ptr;
			this->_root = rhs._root;
			return (*this);
		}
		//& comparison
		bool operator==(const mapIterator &rhs) const
		{
			if(this->_ptr == rhs._ptr)
				return (true);
			return (false);
		}
		bool operator!=(const mapIterator &rhs) const
		{
			return(!(*this == rhs));
		}
		//& (de)referencing
        pointer operator->() const
		{
			return (this->_ptr->_data);
		}
		reference operator*(void) const
		{
			return (*(this->_ptr->_data));
		}
		//& increment, decrement
		mapIterator &operator++()
		{
			if (this->_ptr == NULL)
			{
				return (*this);
			}
			//key_type k = this->_ptr->_data->first;
			if (this->_ptr->_right != NULL) // geh nach rechts und dann ganz nach links unten
			{
				this->_ptr = this->_ptr->_right;
				while (this->_ptr->_left != NULL)
					this->_ptr = this->_ptr->_left;
			}
			//else  if (this->_ptr->parent() != NULL && this->_comp(k,this->_ptr->parent()->_data->first))
			//{
			//	this->_ptr = this->_ptr->parent();
			//}
			else
			{
				node_pointer tmp = this->_ptr->_parent;
				//geh so lange zum parent bis parent > this oder parent == NULL
				while (tmp && this->_ptr == tmp->_right)
				{
					this->_ptr = tmp;
					tmp = tmp->_parent;
				}
				this->_ptr = tmp;
			}
			return (*this);
		}
		mapIterator operator++(int)
		{
			mapIterator tmp = *this;
			++(*this);
			return (tmp);
		}
		
		mapIterator &operator--()
		{
			if (!this->_ptr && this->_root)
			{
				this->_ptr = this->_root;
				while (this->_ptr && this->_ptr->_right != NULL)
					this->_ptr =  this->_ptr->_right;
				return (*this);
			}
			//key_type k = this->_ptr->_data->first;
			if (this->_ptr->_left != NULL) // geh nach links und dann ganz nach rechts unten
			{
				this->_ptr = this->_ptr->_left;
				while (this->_ptr->_right != NULL)
					this->_ptr = this->_ptr->_right;
			}
			//else  if (this->_ptr->parent() != NULL && this->_comp(this->_ptr->parent()->_data->first, k))
			//{
			//	this->_ptr = this->_ptr->parent();
			//}
			else
			{
				//geh so lange zum parent bis parent < this oder parent == NULL
				node_pointer tmp = this->_ptr->_parent;
				while (tmp && this->_ptr == tmp->_left)
				{
					this->_ptr = tmp;
					tmp = tmp->_parent;
				}
				this->_ptr = tmp;
			}
			return (*this);
		}
		mapIterator operator--(int)
		{
			mapIterator tmp = *this;
			--(*this);
			return (tmp);
		}
		node_pointer 	right()
		{
			return (this->_ptr->right());
		}
		node_pointer 	left()
		{
			return (this->_ptr->_left);
		}
		node_pointer	getNode()
		{
			return (this->_ptr);
		}
		node_pointer	parent()
		{
			return (this->_ptr->_parent);
		}
		node_pointer getRoot()
		{
			return (this->_root);
		}
		node_pointer base()
		{
			return (this->_ptr);
		}
		private:
		mutable node_pointer		_ptr;
		mutable node_pointer		_root;
		//key_compare	_comp;
	};


}

#endif