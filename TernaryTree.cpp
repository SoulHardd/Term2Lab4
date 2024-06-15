#include <iostream>
#include <functional>
using namespace std;

template <class T>
class TernaryTree
{
private:
    struct Node
    {
        T data;
        Node *children[3];
    };
    Node *root;
    int size;

public:
    TernaryTree()
    {
        root = nullptr;
    }

    void insert(int data)
    {
        root = insertRecursive(root, data);
    }

    template <typename U>
    TernaryTree<U> map(std::function<U(T)> func)
    {
        TernaryTree<U> newTree;
        mapRecursive(root, newTree, func);
        return newTree;
    }

    TernaryTree<T> where(std::function<bool(T)> condition)
    {
        TernaryTree<T> newTree;
        whereRecursive(root, newTree, condition);
        return newTree;
    }

private:
    Node *createNode(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        for (int i = 0; i < 3; i++)
        {
            newNode->children[i] = nullptr;
        }
        return newNode;
    }

    Node *insertRecursive(Node *root, int data)
    {
        if (root == nullptr)
        {
            return createNode(data);
        }

        if (data < root->data)
        {
            root->children[0] = insertRecursive(root->children[0], data);
        }
        else if (data > root->data)
        {
            root->children[2] = insertRecursive(root->children[2], data);
        }
        else
        {
            root->children[1] = insertRecursive(root->children[1], data);
        }

        return root;
    }

    template <typename U>
    void mapRecursive(Node *root, TernaryTree<U> &newTree, std::function<U(T)> func)
    {
        if (root != nullptr)
        {
            newTree.insert(func(root->data));
            for (int i = 0; i < 3; i++)
            {
                mapRecursive(root->children[i], newTree, func);
            }
        }
    }

    void whereRecursive(Node *root, TernaryTree<T> &newTree, std::function<bool(T)> condition)
    {
        if (root != nullptr)
        {
            if (condition(root->data))
            {
                newTree.insert(root->data);
            }
            for (int i = 0; i < 3; i++)
            {
                whereRecursive(root->children[i], newTree, condition);
            }
        }
    }
};

int main()
{
    TernaryTree<int> tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(8);
    return 0;
}