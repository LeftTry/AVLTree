#ifndef AVLTREE_TREE_H
#define AVLTREE_TREE_H

#include <iostream>

using namespace std;

template <typename T>
class Node{
    T data;
    int height;
    Node<T>* left;
    Node<T>* right;
public:
    Node();
    explicit Node(T);
    T get_data();
    Node<T>* get_left();
    Node<T>* get_right();
    int get_height();
    void set_height(int);
    void set_data(T);
    void set_left(Node<T>*);
    void set_right(Node<T>*);
};

template<typename T>
Node<T>::Node() {
    left = nullptr;
    right = nullptr;
    height = 0;
}

template<typename T>
Node<T>::Node(T data_) {
    data = data_;
    left = nullptr;
    right = nullptr;
    height = 0;
}

template<typename T>
T Node<T>::get_data() {
    return data;
}

template<typename T>
Node<T> *Node<T>::get_left() {
    return left;
}

template<typename T>
Node<T> *Node<T>::get_right() {
    return right;
}

template<typename T>
void Node<T>::set_data(T data_) {
    data = data_;
}

template<typename T>
void Node<T>::set_left(Node<T> * node) {
    left = node;
}

template<typename T>
void Node<T>::set_right(Node<T> * node) {
    right = node;
}

template<typename T>
void Node<T>::set_height(int h) {
    height = h;
}

template<typename T>
int Node<T>::get_height() {
    return height;
}

template<typename T>
class Tree{
    Node<T>* root;
public:
    Tree();
    explicit Tree(Node<T>*);
};

template<typename T>
Tree<T>::Tree(Node<T> * node) {
    root = node;
}

template<typename T>
Tree<T>::Tree() {
    root = nullptr;
}

#endif //AVLTREE_TREE_H
