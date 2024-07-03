#ifndef TREE
#define TREE
#include <functional>
#include "Student.h"
#include "Enums.h"
#include "KeyFunctions.h"

template <class T>
class BinaryTree
{
private:
    struct Node
    {
        T data;
        Node *left;
        Node *right;

        Node(const T &data) : data(data), left(nullptr), right(nullptr) {}
    };

    Node *root;
    int size;
    const int (*KeyFunction)(const T &, const T &);

public:
    BinaryTree(const int (*KeyFunction)(const T &, const T &));
    ~BinaryTree();
    BinaryTree(const BinaryTree &tree, const int (*KeyFunction)(const T &, const T &));
    BinaryTree(T *values, const int &size, const int (*KeyFunction)(const T &, const T &));

    const int GetSize();
    BinaryTree<T> Insert(const T &data);
    BinaryTree<T> Remove(const T &data);

    const T *TreeTraversal(const Traversal &traversal);

    BinaryTree<T> Where(std::function<bool(T)> condition);
    BinaryTree<T> Merge(BinaryTree<T> &Tree);
    bool SearchElement(const T &value);

    template <class U>
    BinaryTree<U> Map(std::function<U(T)> func)
    {
        BinaryTree<U> newTree(KeyFunction);
        MapRecursive(root, newTree, func);
        return newTree;
    }

private:
    Node *CopyTree(Node *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        Node *newNode = new Node(node->data);
        newNode->left = CopyTree(node->left);
        newNode->right = CopyTree(node->right);

        return newNode;
    }

    void DeleteTree(Node *root)
    {
        if (root != nullptr)
        {
            DeleteTree(root->left);
            DeleteTree(root->right);
            delete root;
        }
    }

    Node *InsertRecursive(Node *root, const T &data)
    {
        if (root == nullptr)
        {
            return new Node(data);
        }

        if (KeyFunction(data, root->data) == -1)
        {
            root->left = InsertRecursive(root->left, data);
        }
        else if (KeyFunction(data, root->data) == 1)
        {
            root->right = InsertRecursive(root->right, data);
        }
        return root;
    }

    void RemoveRecursive(Node *&node, const T &data)
    {
        if (node == nullptr)
        {
            return;
        }
        if (KeyFunction(data, node->data) == -1)
        {
            RemoveRecursive(node->left, data);
        }
        else if (KeyFunction(data, node->data) == 1)
        {
            RemoveRecursive(node->right, data);
        }
        else
        {
            if (node->left == nullptr && node->right == nullptr)
            {
                delete node;
                node = nullptr;
                return;
            }
            if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                node = temp;
                return;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                node = temp;
                return;
            }
            else
            {
                Node *successor = FindSuccessor(node->right);
                node->data = successor->data;
                RemoveRecursive(node->right, successor->data);
            }
        }
    }

    Node *FindSuccessor(Node *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    void TreeTraversalRecursive(Node *root, T *arr, int &index, const Traversal &traversal)
    {
        if (root != nullptr)
        {
            switch (traversal)
            {
            case LEFT_ROOT_RIGHT:
                TreeTraversalRecursive(root->left, arr, index, traversal);
                arr[index++] = root->data;
                TreeTraversalRecursive(root->right, arr, index, traversal);
                break;

            case RIGHT_ROOT_LEFT:
                TreeTraversalRecursive(root->right, arr, index, traversal);
                arr[index++] = root->data;
                TreeTraversalRecursive(root->left, arr, index, traversal);
                break;

            case ROOT_LEFT_RIGHT:
                arr[index++] = root->data;
                TreeTraversalRecursive(root->left, arr, index, traversal);
                TreeTraversalRecursive(root->right, arr, index, traversal);
                break;

            case ROOT_RIGHT_LEFT:
                arr[index++] = root->data;
                TreeTraversalRecursive(root->right, arr, index, traversal);
                TreeTraversalRecursive(root->left, arr, index, traversal);
                break;

            case LEFT_RIGHT_ROOT:
                TreeTraversalRecursive(root->left, arr, index, traversal);
                TreeTraversalRecursive(root->right, arr, index, traversal);
                arr[index++] = root->data;
                break;

            case RIGHT_LEFT_ROOT:
                TreeTraversalRecursive(root->right, arr, index, traversal);
                TreeTraversalRecursive(root->left, arr, index, traversal);
                arr[index++] = root->data;
                break;
            }
        }
    }

    template <typename U>
    void MapRecursive(Node *root, BinaryTree<U> &newTree, std::function<U(T)> func)
    {
        if (root != nullptr)
        {
            newTree.Insert(func(root->data));
            MapRecursive(root->left, newTree, func);
            MapRecursive(root->right, newTree, func);
        }
    }

    void WhereRecursive(Node *root, BinaryTree<T> &newTree, std::function<bool(T)> condition)
    {
        if (root != nullptr)
        {
            if (condition(root->data))
            {
                newTree.Insert(root->data);
            }
            WhereRecursive(root->left, newTree, condition);
            WhereRecursive(root->right, newTree, condition);
        }
    }

    void MergeRecursive(Node *root1, Node *root2)
    {
        if (root2 != nullptr)
        {
            MergeRecursive(root1, root2->left);
            MergeRecursive(root1, root2->right);
            root1 = InsertRecursive(root1, root2->data);
        }
    }

    bool SearchElementRecursive(Node *root, T value)
    {
        if (root == nullptr)
        {
            return false;
        }

        if (KeyFunction(root->data, value) == 0)
        {
            return true;
        }

        return SearchElementRecursive(root->left, value) || SearchElementRecursive(root->right, value);
    }
};

template <class T>
BinaryTree<T>::BinaryTree(const int (*KeyFunction)(const T &, const T &))
{
    this->KeyFunction = KeyFunction;
    root = nullptr;
    size = 0;
}

template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree &tree, const int (*KeyFunction)(const T &, const T &))
{
    root = CopyTree(tree.root);
    this->size = tree.size;
    this->KeyFunction = KeyFunction;
}

template <class T>
BinaryTree<T>::BinaryTree(T *values, const int &size, const int (*KeyFunction)(const T &, const T &))
{
    root = nullptr;
    for (int i = 0; i < size; ++i)
    {
        Insert(values[i]);
    }
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
    DeleteTree(root);
}

template <class T>
const int BinaryTree<T>::GetSize()
{
    return this->size;
}

template <class T>
BinaryTree<T> BinaryTree<T>::Insert(const T &data)
{
    this->root = InsertRecursive(this->root, data);
    size++;
    return this;
}

template <class T>
BinaryTree<T> BinaryTree<T>::Remove(const T &data)
{
    RemoveRecursive(root, data);
    size--;
    return this;
}

template <class T>
const T *BinaryTree<T>::TreeTraversal(const Traversal &traversal)
{
    int index = 0;
    T *arr = new T[size];
    TreeTraversalRecursive(root, arr, index, traversal);
    return arr;
}

template <class T>
BinaryTree<T> BinaryTree<T>::Where(std::function<bool(T)> condition)
{
    BinaryTree<T> newTree(KeyFunction);
    WhereRecursive(root, newTree, condition);
    return newTree;
}

template <class T>
BinaryTree<T> BinaryTree<T>::Merge(BinaryTree<T> &Tree)
{
    MergeRecursive(root, Tree.root);
    return this;
}

template <class T>
bool BinaryTree<T>::SearchElement(const T &value)
{
    return SearchElementRecursive(root, value);
}

#endif