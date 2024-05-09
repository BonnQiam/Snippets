#include <iostream>

// define binary tree structure and traverse helpers:
struct Node 
{
    int value;
    Node* left;
    Node* right;
    Node(int i=0) : value(i), left(nullptr), right(nullptr) {}
    //...
};
auto left = &Node::left;
auto right = &Node::right;

// traverse tree, using fold expression:
template <typename T, typename... TP>
Node* traverse(T np, TP... paths) 
{
    return (np ->* ... ->* paths);    // np ->* paths1 ->* paths2 ...
                                      // the final return value is a pointer to the node at the end of the path
}

int main()
{
    // init binary tree structure:
    Node* root = new Node{0};
    root->left = new Node{1};
    root->left->right = new Node{2};
    root->left->right->left = new Node{3};
    
    // traverse binary tree:
    Node* node = traverse(root, left, right,left);
    if (node != nullptr)
        std::cout << node->value << std::endl; // print 2
    else
        std::cout << "path is invalid" << std::endl; // print path is invalid

    Node* node2 = traverse(root, right);
    if (node2 != nullptr)
        std::cout << node2->value << std::endl; // print 1
    else
        std::cout << "path is invalid" << std::endl; // print path is invalid
        
    return 0;
}