/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 09:23:05 by djedasch          #+#    #+#             */
/*   Updated: 2022/12/13 13:24:41 by djedasch         ###   ########.fr       */
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
		typedef nodePtr									node_pointer;
		

		public:
		mapIterator() : _ptr(NULL), _root(NULL) {}
		mapIterator(node_pointer ptr, node_pointer root) : _ptr(ptr), _root(root){}
		~mapIterator(void){}
		mapIterator(const mapIterator& rhs): _ptr(rhs._ptr), _root(rhs._root){}
		template<typename node, typename val>
		mapIterator(mapIterator<node, val> copy) : _ptr(copy.base()) , _root(copy.getRoot()) {}
		mapIterator& operator=(const mapIterator& rhs)
		{
			this->_ptr = rhs._ptr;
			this->_root = rhs._root;
			return (*this);
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
			if (this->_ptr->_right != NULL) // geh nach rechts und dann ganz nach links unten
			{
				this->_ptr = this->_ptr->_right;
				while (this->_ptr->_left != NULL)
					this->_ptr = this->_ptr->_left;
			}
			else
			{
				node_pointer tmp = this->_ptr->_parent;
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
			if (!this->_ptr)
			{
				this->_ptr = this->_root;
				while (this->_ptr && this->_ptr->_right != NULL)
					this->_ptr =  this->_ptr->_right;
				return (*this);
			}
			if (this->_ptr->_left) // geh nach links und dann ganz nach rechts unten
			{
				this->_ptr = this->_ptr->_left;
				while (this->_ptr->_right)
					this->_ptr = this->_ptr->_right;
			}
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
		node_pointer	getNode()
		{
			return (this->_ptr);
		}
		node_pointer getRoot() const
		{
			return (this->_root);
		}
		node_pointer base() const
		{
			return (this->_ptr);
		}
		private:
		mutable node_pointer		_ptr;
		mutable node_pointer		_root;
	};
	
	template<typename n_ptr, typename v_type>
	bool operator==(const mapIterator<n_ptr, v_type> &lhs, const mapIterator<n_ptr, v_type> &rhs) {
		return (lhs.base() == rhs.base());	
	}

	template<typename n_ptr, typename v_type>
	bool operator!=(const mapIterator<n_ptr, v_type> &lhs, const mapIterator<n_ptr, v_type> &rhs) {
		return (lhs.base() != rhs.base());
	}

	template<typename n_ptr1, typename n_ptr2, typename v_type>
	bool operator==(const mapIterator<n_ptr1, v_type> &lhs, const mapIterator<n_ptr2, v_type> &rhs) {
		return (lhs.base() == rhs.base());	
	}

	template<typename n_ptr1, typename n_ptr2, typename v_type>
	bool operator!=(const mapIterator<n_ptr1, v_type> &lhs, const mapIterator<n_ptr2, v_type> &rhs) {
		return (lhs.base() != rhs.base());
	}

	template<typename n_ptr1, typename n_ptr2, typename v_type1, typename v_type2>
	bool operator==(const mapIterator<n_ptr1, v_type1> &lhs, const mapIterator<n_ptr2, v_type2> &rhs) {
		return (lhs.base() == rhs.base());	
	}

	template<typename n_ptr1, typename n_ptr2, typename v_type1, typename v_type2>
	bool operator!=(const mapIterator<n_ptr1, v_type1> &lhs, const mapIterator<n_ptr2, v_type2> &rhs) {
		return (lhs.base() != rhs.base());
	}


}

#endif