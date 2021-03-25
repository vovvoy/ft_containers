#ifndef CONTAINER_LIST_HPP
#define CONTAINER_LIST_HPP


#include <memory>
#include <list>

template < class T >
class Node {
    T       content;
    Node *  previous;
    Node *  next;
    std::list<int> d;
};

template < class T, class Alloc = std::allocator<T> >
class list {
private:
    unsigned int    _size;
    T               _val;
    Node<T>         _elem;
public:
    list(): _size(0){
        _elem.content = NULL;
        _elem.next = NULL;
        _elem.previous = NULL;
    };

    void push_back(T val){
        Node<T> tmp;
        tmp = _elem;
        while (tmp.next)
            tmp = tmp.next;

        tmp.content = val;
    }
    void pop_back(){
        Node<T> tmp;
        tmp = _elem;
        while (tmp.next)
            tmp = tmp.next;

    }

};


#endif
