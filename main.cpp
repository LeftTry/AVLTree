#include <iostream>
#include "Tree.h"

int main() {
    int n;
    cout << "Enter quantity of elements:" << endl;
    cin >> n;
    Node<int>* tree = nullptr;
    cout << "Enter elements:" << endl;
    for(int i = 0;i < n;i++){
        int a;
        cin >> a;
        tree = Insert(tree, a);
    }
    Print(tree);
    cout << "Enter element you want to insert:" << endl;
    int a;
    cin >> a;
    tree = Insert(tree, a);
    Print(tree);
    Node<int>* s;
    cout << "Enter element you want to search:" << endl;
    cin >> a;
    s = Search(tree, a);
    cout << s << endl;
    cout << "Min element:" << endl;
    s = SearchMin(tree);
    cout << s << endl;
    cout << "Enter element you want to remove:" << endl;
    cin >> a;
    while(a == tree->data){
        cout << "You can't delete first node. Please enter correct value:" << endl;
        cin >> a;
    }
    s = Remove(tree, a);
    cout << "Removed element: " << s << endl;
    Print(tree);
    cout << "Removing min element..." << endl;
    s = SearchMin(tree);
    if(s == tree) cout << "We can't remove min element" << endl;
    else {
        s = Remove_Min(tree);
        cout << "Removed element: " << s << endl;
        Print(tree);
    }
    return 0;
}
