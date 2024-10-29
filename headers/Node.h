#ifndef NODE_H
#define NODE_H

template <typename T>

class Node {
    public: 
        T data;
        int Heuristic;
        Node<T> *next;
        //test for commit

        Node (T value) : data(value), next(nullptr) ()
        bool operator()(Node * Obj1, Node * Obj2);
};

#endif