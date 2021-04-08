#ifndef CONTAINER_LIST_HPP
#define CONTAINER_LIST_HPP

#include <iostream>
#include "iterator.hpp"

namespace ft {
    template <typename T_Node>
    struct Doubly_Linked_Node {
    public :
        Doubly_Linked_Node  *prev;
        Doubly_Linked_Node  *next;
        T_Node              data;

        Doubly_Linked_Node()
                :
                prev(u_nullptr),
                next(u_nullptr)
        {}
    };

    template<class T, class Alloc = std::allocator<T> >
    class list {
    public:
        typedef T                                         value_type;
        typedef Alloc                                     allocator_type;
        typedef typename Alloc::pointer                   pointer;
        typedef typename Alloc::const_pointer             const_pointer;
        typedef typename Alloc::reference                 reference;
        typedef typename Alloc::const_reference           const_reference;
//        typedef _List_iterator<T>                         iterator;
//        typedef _List_const_iterator<T>                   const_iterator;
//        typedef std::reverse_iterator<const_iterator>     const_reverse_iterator;
//        typedef std::reverse_iterator<iterator>           reverse_iterator;
        typedef size_t                                    size_type;
//        typedef ptrdiff_t                                 difference_type;
        typedef Doubly_Linked_Node<value_type>              node;


        explicit list (const allocator_type& alloc = allocator_type())
                :
                _alloc(alloc)
        {
            _last_node = _node_alloc.allocate(1);
            _node_alloc.construct(_last_node, Doubly_Linked_Node<value_type>());
            _last_node->prev = _last_node;
            _last_node->next = _last_node;
        }

        void push_front (const value_type& val){
            node_pointer tmp = _node_alloc.allocate(1);
            _node_alloc.construct(tmp, Doubly_Linked_Node<value_type>());
            tmp->data = val;
            if (_last_node->prev == _last_node){
                _last_node->next = tmp;
                _last_node->prev = tmp;
                tmp->next = _last_node;
                tmp->prev = _last_node;
            }
            else{
                tmp->prev = _last_node;
                tmp->next = _last_node->next;
                _last_node->next->prev = tmp;
                _last_node->next = tmp;
            }
        }

        void pop_front(){
            node_pointer node = _last_node->next;
            if (node->prev == _last_node)
                _last_node->next = node->next;
            else
                node->prev->next = node->next;
            if (node->next == _last_node)
                _last_node->prev = node->prev;
            else
                node->next->prev = node->prev;
            _node_alloc.destroy(node);
            _node_alloc.deallocate(node, 1);

        }

        void push_back(const value_type& val){
            node_pointer tmp = _node_alloc.allocate(1);
            _node_alloc.construct(tmp, Doubly_Linked_Node<value_type>());
            tmp->data = val;
            if (_last_node->next == _last_node){
                _last_node->next = tmp;
                _last_node->prev = tmp;
                tmp->next = _last_node;
                tmp->prev = _last_node;
            }
            else{
                tmp->prev = _last_node->prev;
                tmp->next = _last_node;
                _last_node->prev->next = tmp;
                _last_node->prev = tmp;
            }
        }

        void pop_back(){
            node_pointer node = _last_node->prev;
            if (node->prev == _last_node)
                _last_node->next = node->next;
            else
                node->prev->next = node->next;
            if (node->next == _last_node)
                _last_node->prev = node->prev;
            else
                node->next->prev = node->prev;
            _node_alloc.destroy(node);
            _node_alloc.deallocate(node, 1);
        }

        reference front() { return (_last_node->next->data); }
        const_reference front() const { return (_last_node->next->data); }
        reference back() { return (_last_node->prev->data); }
        const_reference back() const { return (_last_node->prev->data); }

        void swap (list& x)
        {
            if (&x == this)
                return;

            allocator_type 			save_alloc = x._alloc;
            node_allocator			save_node_alloc = x._node_alloc;
            node_pointer            save_last_node = x._last_node;

            x._alloc = this->_alloc;
            x._node_alloc = this->_node_alloc;
            x._last_node = this->_last_node;

            this->_alloc = save_alloc;
            this->_node_alloc = save_node_alloc;
            this->_last_node = save_last_node;
        }

        bool empty() const { return _last_node->next == _last_node; }

        size_type size() const{
            size_type cnt = 0;
            node_pointer node = _last_node;
            while ((node = node->next) != _last_node)
                cnt++;
            return cnt;
        }

        size_type max_size() const { return _node_alloc().max_size(); }

        void sort() {
            node_pointer a = _last_node->next;
            node_pointer b = a->next;
            node_pointer bef;
            node_pointer aft;
            while (b != _last_node)
            { 	// bef -> a -> b -> aft
                if (b->data < a->data)
                {
                    bef = a->prev;
                    aft = b->next;
                    // link bef -> b
                    bef->next = b;
                    b->prev = bef;
                    // link b -> a
                    b->next = a;
                    a->prev = b;
                    // link a-> aft
                    a->next = aft;
                    aft->prev = a;
                    // retun to begin
                    a = _last_node->next;
                    b = a->next;
                }
                else
                {
                    a = a->next;
                    b = b->next;
                }
            }
        }

        template <class Compare>
        void sort (Compare comp) {
            node_pointer a = _last_node->next;
            node_pointer b = a->next;
            node_pointer bef;
            node_pointer aft;
            while (b != _last_node)
            { 	// bef -> a -> b -> aft
                if (comp(b->data, a->data))
                {
                    bef = a->prev;
                    aft = b->next;
                    // link bef -> b
                    bef->next = b;
                    b->prev = bef;
                    // link b -> a
                    b->next = a;
                    a->prev = b;
                    // link a-> aft
                    a->next = aft;
                    aft->prev = a;
                    // retun to begin
                    a = _last_node->next;
                    b = a->next;
                }
                else
                {
                    a = a->next;
                    b = b->next;
                }
            }
        }

        void clear()
        {
            while (_last_node->next != _last_node)
                pop_back();
        }

        void resize (size_type n, value_type val = value_type()){
//            if (this->max_size() - this->size() < n)
//                throw (std::length_error("list::resize"));
            if (n > this->size())
            {
                n -= this->size();
                while (n--)
                    this->push_back(val);
            }
            else
            {
                while (this->size() > n)
                    this->pop_back();
            }
        }

    private:
        typedef std::allocator<Doubly_Linked_Node<T> > node_allocator;
        typedef typename node_allocator::pointer	node_pointer;

        allocator_type 			_alloc;
        node_allocator			_node_alloc;
        node_pointer        	_last_node;

    };
}
#endif
