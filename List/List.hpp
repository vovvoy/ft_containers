#ifndef CONTAINER_LIST_HPP
#define CONTAINER_LIST_HPP

#include <iostream>

namespace ft {
    template <typename T_Node>
    struct Doubly_Linked_Node {
    public :
        Doubly_Linked_Node  *prev;
        Doubly_Linked_Node  *next;
        T_Node              data;

        Doubly_Linked_Node()
                :
                prev(NULL),
                next(NULL)
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


        explicit list (const allocator_type& alloc = allocator_type())
                :
                _alloc(alloc)
        {
            _last_node = _node_alloc.allocate(1);
            _node_alloc.construct(_last_node, Doubly_Linked_Node<value_type>());
            _last_node->prev = _last_node;
            _last_node->next = _last_node;
        }

        void push_back(const value_type& val){
            _node_pointer tmp = _node_alloc.allocate(1);
            _node_alloc.construct(tmp, Doubly_Linked_Node<value_type>(val));
            if (_last_node->next == _last_node){
                _last_node->next = tmp;
                _last_node->prev = tmp;
                tmp->prev = _last_node;
                tmp->next = _last_node;
            }
            else{
                tmp->prev = _last_node->prev;
                tmp->next = _last_node;
                _last_node->next->next = tmp;
                _last_node->prev = tmp;
            }
        }
    private:
        typedef typename allocator_type::template rebind<Doubly_Linked_Node<T> >::other node_allocator;
        typedef typename node_allocator::pointer	_node_pointer;

        allocator_type 			_alloc;
        node_allocator			_node_alloc;
        Doubly_Linked_Node<T>	*_last_node;

    };
}
#endif
