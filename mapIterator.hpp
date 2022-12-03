/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:03:50 by djedasch          #+#    #+#             */
/*   Updated: 2022/12/03 13:34:37 by djedasch         ###   ########.fr       */
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
		typedef const value_type&						const_reference;
		typedef std::ptrdiff_t 							difference_type;
		typedef std::bidirectional_iterator_tag			iterator_category;
		typedef typename map::size_type					size_type;
		typedef typename map::key_type					key_type;
		typedef typename map::key_compare				key_compare;
		typedef typename map::Node						Node;
		

		public:
		mapIterator() : _ptr(NULL) {}
		mapIterator(Node *ptr, Node *root) : _ptr(ptr), _root(root){}
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
        pointer operator->() const
		{
			return (this->_ptr->_data);
		}
		reference operator*(void) const
		{
			return (*(this->_ptr->_data));
		}
		//& increment, decrement
		mapIterator operator++()
		{
			key_type k = this->_ptr->_data->first;
			if (this->_ptr->right() != NULL)
			{
				this->_ptr = this->_ptr->right();
				while (this->_ptr->left() != NULL)
					this->_ptr = this->_ptr->left();
				// geh nach rechts und dann ganz nach links unten
			}
			else  if (this->_ptr->parent() != NULL && this->_comp(k,this->_ptr->parent()->_data->first))
			{
				this->_ptr = this->_ptr->parent();
			}
			else
			{
				//geh so lange zum parent bis parent > this oder parent == NULL
				while (this->_ptr->parent() != NULL && !this->_comp(k ,this->_ptr->parent()->_data->first))
					this->_ptr = this->_ptr->parent();
				this->_ptr = this->_ptr->parent();
			}
			return (*this);
		}
		mapIterator operator++(int)
		{
			mapIterator tmp = *this;
			++(*this);
			return (tmp);
		}
		mapIterator operator--()
		{
			if (!this->_ptr)
			{
				this->_ptr = this->_root;
				while (this->_ptr->right() != NULL)
					this->_ptr =  this->_ptr->right();
				return (*this);
			}
			key_type k = this->_ptr->_data->first;
			if (this->_ptr->left() != NULL)
			{
				this->_ptr = this->_ptr->left();
				while (this->_ptr->right() != NULL)
					this->_ptr = this->_ptr->right();
				// geh nach links und dann ganz nach rechts unten
			}
			else  if (this->_ptr->parent() != NULL && this->_comp(this->_ptr->parent()->_data->first, k))
			{
				this->_ptr = this->_ptr->parent();
			}
			else
			{
				//geh so lange zum parent bis parent < this oder parent == NULL
				Node *tmp = this->_ptr;
				while (this->_ptr->parent() != NULL && !this->_comp(this->_ptr->parent()->_data->first, k))
					this->_ptr = this->_ptr->parent();
				if (!this->_ptr->parent())
					this->_ptr = tmp;
				else
					this->_ptr = this->_ptr->parent();
			}
			return (*this);
		}
		mapIterator operator--(int)
		{
			mapIterator tmp = *this;
			--(*this);
			return (tmp);
		}
		Node *right()
		{
			return (this->_ptr->right());
		}
		Node *left()
		{
			return (this->_ptr->left());
		}
		Node	*getNode()
		{
			return (this->_ptr);
		}
		private:
		Node		*_ptr;
		Node		*_root;
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
		typedef typename map::key_compare			key_compare;
		typedef typename map::Node					Node;
		

		public:
		const_mapIterator() : _ptr(NULL) {}
		const_mapIterator(Node *ptr, Node *root) : _ptr(ptr), _root(root){}
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
			return (this->_ptr->_data);
		}
		reference operator*(void) const
		{
			const value_type *tmp = (this->_ptr->_data);
			return (*tmp);
		}
		//& increment, decrement
		const_mapIterator operator++()
		{
			if (!this->_ptr)
				return (*this);
			key_type k = this->_ptr->_data->first;
			if (this->_ptr->right() != NULL)
			{
				this->_ptr = this->_ptr->right();
				while (this->_ptr->left() != NULL)
					this->_ptr = this->_ptr->left();
				// geh nach rechts und dann ganz nach links unten
			}
			else  if (this->_ptr->parent() != NULL && this->_comp(k,this->_ptr->parent()->_data->first))
			{
				this->_ptr = this->_ptr->parent();
			}
			else
			{
				//geh so lange zum parent bis parent > this oder parent == NULL
				while (this->_ptr->parent() != NULL && !this->_comp(k ,this->_ptr->parent()->_data->first))
					this->_ptr = this->_ptr->parent();
				if (!this->_ptr->parent())
					this->_ptr = NULL;
				else
					this->_ptr = this->_ptr->parent();
			}
			return (*this);
		}
		const_mapIterator operator++(int)
		{
			const_mapIterator tmp = *this;
			++(*this);
			return (tmp);
		}
		const_mapIterator operator--()
		{
			if (!this->_ptr)
			{
				this->_ptr = this->_root;
				while (this->_ptr->right() != NULL)
					this->_ptr =  this->_ptr->right();
				return (*this);
			}
			key_type k = this->_ptr->_data->first;
			if (this->_ptr->left() != NULL)
			{
				this->_ptr = this->_ptr->left();
				while (this->_ptr->right() != NULL)
					this->_ptr = this->_ptr->right();
				// geh nach links und dann ganz nach rechts unten
			}
			else  if (this->_ptr->parent() != NULL && this->_comp(this->_ptr->parent()->_data->first, k))
			{
				this->_ptr = this->_ptr->parent();
			}
			else
			{
				//geh so lange zum parent bis parent < this oder parent == NULL
				Node *tmp = this->_ptr;
				while (this->_ptr->parent() != NULL && !this->_comp(k ,this->_ptr->parent()->_data->first))
					this->_ptr = this->_ptr->parent();
				if (!this->_ptr->parent())
					this->_ptr = tmp;
				else
					this->_ptr = this->_ptr->parent();
			}
			return (*this);
		}
		const_mapIterator operator--(int)
		{
			const_mapIterator tmp = *this;
			--(*this);
			return (tmp);
		}
		Node 	*right()
		{
			return (this->_ptr->right());
		}
		Node 	*left()
		{
			return (this->_ptr->left());
		}
		Node	*getNode()
		{
			return (this->_ptr);
		}
		private:
		Node		*_ptr;
		Node		*_root;
		key_compare	_comp;

	};

#endif