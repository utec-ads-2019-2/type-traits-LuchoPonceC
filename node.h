#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    int query;
    Node(T data) : data(data), query(0) {
        next = nullptr;
    }
      
    void killSelf();
};

template <typename T>
void Node<T>::killSelf() {
    if (next) {
        next->killSelf();
    }
    
    delete this;
}

#endif