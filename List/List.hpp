#ifndef CONTAINER_LIST_HPP
#define CONTAINER_LIST_HPP

#include <iostream>

namespace ft {
    template<typename T>
    struct Node{
        T *data;
        Node *next;
        Node *prev;
    };
    template<typename T>
    class node {
    protected:
        Node<T> * data;
    public:
        node(){
            data->data = NULL;
            data->next = NULL;
            data->prev = NULL;
        }
        void push_back(T data){
            Node<T> * tmp;
            if (this->data->data){
                tmp  = this->data;
                while (tmp->next)
                    tmp = tmp->next;
                Node<T> * back;
                back->data = &data;
                back->prev = tmp;
                back->next = NULL;
                tmp->next = back;
            }
            else
                this->data->data = &data;
        }
    };

    template<class T, class Alloc = std::allocator<T> >
    class list : public node<T> {
    public:
        list() : node<T>(){};
    };
}
#endif
