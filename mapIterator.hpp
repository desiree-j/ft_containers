/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:03:50 by djedasch          #+#    #+#             */
/*   Updated: 2022/11/25 20:08:11 by djedasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATOR_HPP
# define MAPITERATOR_HPP

	template <typename map>
	class mapIterator
	{
		public:
		typedef typename map::pointer					pointer;
		typedef typename map::reference					reference;
		typedef typename map::value_type				value_type;
		typedef std::ptrdiff_t 							difference_type;
		typedef std::bidirectional_iterator_tag			iterator_category;
		typedef typename map::size_type					size_type;
		typedef typename map::key_type					key_type;
		typedef typename map::key_compare				key_compare;
		typedef typename map::Node						Node;
		

		public:
		mapIterator() : _ptr(NULL) {}
		mapIterator(Node *ptr) : _ptr(ptr){}
		~mapIterator(void){}
		mapIterator(const mapIterator& rhs)
		{
			this->_ptr = rhs._ptr;
		}
		mapIterator& operator=(const mapIterator& rhs)
		{
			this->_ptr = rhs._ptr;
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
        Node *operator->() const
		{
			return (this->_ptr);
		}
        reference operator[](int n) const
		{
			return (*(this->_ptr + n));
		}
		reference operator*(void) const
		{
			return (*(this->_ptr));
		}
		//& increment, decrement
		//! change increment and decrement operator
		mapIterator operator++()
		{
			key_type k = this->_ptr->_data->first;
			if (this->_ptr->_right != NULL)
			{
				this->_ptr = this->ptr->_right;
				while (this->_ptr->_left != NULL)
					this->_ptr = this->_ptr->_left;
				// geh nach rechts und dann ganz nach links unten
			}
			else  if (this->_ptr->_parent != NULL && this->_comp(k,this->_ptr->_parent->_data->first))
			{
				this->_ptr = this->_ptr->_parent;
			}
			else
			{
				//geh so lange zum parent bis parent > this oder parent == NULL
				while (this->_ptr->_parent != NULL && !this->_comp(k ,this->_ptr->_parent->_data->first))
					this->_ptr = this->_ptr->_parent;
				this->_ptr = this->_ptr->_parent;
			}
			return (*this);
		}
		mapIterator operator++(int)
		{
			mapIterator tmp = *this;
			this->_ptr++;
			return (tmp);
		}
		mapIterator operator--()
		{
			
			return (*this);
		}
		mapIterator operator--(int)
		{
			mapIterator tmp = *this;
			--(*this);
			return (tmp);
		}
		private:
		Node		 *_ptr;
		key_compare	_comp;
	};

	template <typename map>
	class const_mapIterator
	{
		public:
		typedef typename map::key_type				key_type;
		typedef typename map::pointer				pointer;
		typedef typename map::value_type			value_type;
		typedef const value_type&					reference;
		typedef std::ptrdiff_t 						difference_type;
		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef typename map::size_type				size_type;
		

		public:
		const_mapIterator() : _ptr(NULL) {}
		const_mapIterator(pointer ptr) : _ptr(ptr){}
		~const_mapIterator(void){}
		const_mapIterator(const const_mapIterator& rhs)
		{
			this->_ptr = rhs._ptr;
		}
		const_mapIterator& operator=(const const_mapIterator& rhs)
		{
			this->_ptr = rhs._ptr;
			return (*this);
		}
		//& comparison
		bool operator==(const const_mapIterator &rhs) const
		{
			if(this->_ptr == rhs._ptr)
				return (true);
			return (false);
		}
		bool operator!=(const const_mapIterator &rhs) const
		{
			return(!(*this == rhs));
		}
		//& (de)referencing
        const pointer operator->() const
		{
			return (this->_ptr);
		}
		reference operator*(void) const
		{
			const value_type *tmp = (this->_ptr);
			return (*tmp);
		}
		//& increment, decrement
		//! change increment and decrement operator
		const_mapIterator operator++()
		{
			this->_ptr++;
			return (*this);
		}
		const_mapIterator operator++(int)
		{
			const_mapIterator tmp = *this;
			this->_ptr++;
			return (tmp);
		}
		const_mapIterator operator--()
		{
			this->_ptr--;
			return (*this);
		}
		const_mapIterator operator--(int)
		{
			const_mapIterator tmp = *this;
			--(*this);
			return (tmp);
		}
		private:
		pointer _ptr;
	};

#endif