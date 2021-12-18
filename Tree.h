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
    Node<T>* insert(T k);
    Node<T>* search(T k);
    Node<T>* searchMin();
    Node<T>* removeMin();
    Node<T>* remove(T k);
};

template<typename T>
Tree<T>::Tree(Node<T> * node) {
    root = node;
}

template<typename T>
Tree<T>::Tree() {
    root = nullptr;
}

template<typename T>
Node<T>* Tree<T>::insert(T k) {
    Node<T>* p = root;
    return insert(p, k);
}

template<typename T>
Node<T>* Tree<T>::search(T k) {
    Node<T>* p = root;
    return search(p, k);
}

template<typename T>
Node<T>* Tree<T>::searchMin() {
    Node<T>* p = root;
    return searchMin(p);
}

template<typename T>
Node<T> *Tree<T>::removeMin() {
    Node<T>* p = root;
    return removeMin(p);
}

template<typename T>
Node<T> *Tree<T>::remove(T k) {
    Node<T>* p = root;
    return remove(p, k);
}

template <typename T>
unsigned char height(Node<T>* p)
{
    return p?p->height:0;
}

template <typename T>
void fixHeight(Node<T>* p)
{
    unsigned char hl = height(p->left);
    unsigned char hr = height(p->right);
    p->height = (hl>hr?hl:hr)+1;
}

template <typename T>
int balanceFactor(Node<T>* p){
    return height(p->right) - height(p->left);
}

template <typename T>
Node<T>* rotateLeft(Node<T>* p){
    Node<T>* q = p->right;
    p->right = q->left;
    q->left = p;
    fixHeight(p);
    fixHeight(q);
    return q;
}

template <typename T>
Node<T>* rotateRight(Node<T>* p){
    Node<T>* q = p->left;
    p->left = q->right;
    q->right = p;
    fixHeight(p);
    fixHeight(q);
    return q;
}

template <typename T>
Node<T>* balance(Node<T>* p){
    fixHeight(p);
    if(balanceFactor(p) == 2){
        if(balanceFactor(p->right) < 0){
            p->right = rotateRight(p->right);
            return rotateLeft(p);
        }
    }
    if(balanceFactor(p->left) == -2){
        if(balanceFactor(p->left) > 0){
            p->left = rotateLeft(p->left);
            return rotateRight(p);
        }
    }
    return p;
}

template<typename T>
Node<T>* insert(Node<T>* p, T k) {
    if(p == nullptr)
        return new Node<T>(k);
    if(k < p->data){
        p->left = insert(p->left, k);
    }
    else{
        p->right = insert(p->right, k);
    }
    return balance(p);
}

template<typename T>
Node<T>* search(Node<T>* p, T k) {
    if(p == nullptr) return nullptr;
    if(p->data < k) search(p->left, k);
    else if(p->data > k) search(p->right, k);
    else if(p->data == k) return p;
}

template<typename T>
Node<T>* searchMin(Node<T>* p) {
    while(p->left != nullptr){
        p = p->left;
    }
    return p;
}

template<typename T>
Node<T> *removeMin(Node<T>* p) {
    if(p->left == nullptr) return p->right;
    p->left = removeMin(p->left);
    return balance(p);
}

template<typename T>
Node<T> remove(Node<T> *p, T k) {
    if(!p) return nullptr;
    else if(p->data > k) p->left = remove(p->left(), k);
    else if(p->data < k) p->right = remove(p->right, k);
    else{
        Node<T>* l = p->left;
        Node<T>* r = p->right;
        delete p;
        if(!r) return l;
        Node<T>* min = searchMin(r);
        min->right = removeMin(r);
        min->left = l;
        return balance(min);
    }
    return balance(p);
}

#endif //AVLTREE_TREE_H
