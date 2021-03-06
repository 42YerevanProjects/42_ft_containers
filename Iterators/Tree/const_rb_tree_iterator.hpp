
#pragma once

#include "../iterator.hpp"
#include "rb_tree_iterator.hpp"
#include "../../Utility/rb_tree_node.hpp"

/*
=====================================
    Red-Black Tree Const Iterator
=====================================
*/

namespace ft
{
    template <typename T>
    class const_rb_tree_iterator : ft::iterator<ft::bidirectional_iterator_tag, const T>
    {
        public:
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type        value_type;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer           pointer;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference         reference;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type   difference_type;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category iterator_category;

            typedef rb_tree_iterator<T>         iterator;

            typedef const_rb_tree_iterator<T>   self;
            typedef const rb_tree_node_base*    base_ptr;
            typedef const rb_tree_node<T>*      link_type;

        private:
            base_ptr    inorder_increment(base_ptr node);
            base_ptr    inorder_decrement(base_ptr node);

        protected:
            base_ptr    _node;

        public:
            /* Constructors and Destructor */

            const_rb_tree_iterator();
            explicit const_rb_tree_iterator(link_type x);
            const_rb_tree_iterator(const iterator& _it);
            const_rb_tree_iterator(const self& other);
            virtual ~const_rb_tree_iterator();

            /* Operator Overloads */

            self&       operator=(const self& other);

            self&       operator++();
            self        operator++(int);

            self&       operator--();
            self        operator--(int);

            pointer     operator->() const;
            reference   operator*() const;

            /* Equality Checks */

            bool    operator==(const self& x) const;
            bool    operator!=(const self& x) const;
    };
}
#include "const_rb_tree_iterator.tpp"
