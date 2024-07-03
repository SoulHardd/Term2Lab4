#ifndef TERNARY_TREE
#define TERNARY_TREE
#include <functional>
#include "Enums.h"

template <class T>
class TernaryTree
{
private:
    struct Node
    {
        T data;
        Node *left;
        Node *middle;
        Node *right;

        Node(const T &data) : data(data), left(nullptr), middle(nullptr), right(nullptr) {}
    };
    Node *root;
    int size;
    const int (*KeyFunction)(const T &, const T &);

public:
    TernaryTree(const int (*KeyFunction)(const T &, const T &));
    TernaryTree(const TernaryTree &tree, const int (*KeyFunction)(const T &, const T &));
    ~TernaryTree();

    void Insert(const T &data);
    bool SearchElement(const T &data);
    void Remove(const T &data);
    int GetSize();

    TernaryTree<T> Where(std::function<bool(T)> condition);
    void Merge(TernaryTree<T> &Tree);

    const T *TreeTraversal(const Traversal &traversal);

    template <class U>
    TernaryTree<U> Map(std::function<U(T)> func)
    {
        TernaryTree<U> newTree(KeyFunction);
        MapRecursive(root, newTree, func);
        return newTree;
    }

private:
    Node *CopyTree(Node *Root)
    {
        if (Root == nullptr)
        {
            return nullptr;
        }

        Node *newNode = new Node(Root->data);
        newNode->left = CopyTree(Root->left);
        newNode->middle = CopyTree(Root->middle);
        newNode->right = CopyTree(Root->right);

        return newNode;
    }

    void DeleteTree(Node *node)
    {
        if (node != nullptr)
        {
            DeleteTree(node->left);
            DeleteTree(node->middle);
            DeleteTree(node->right);
            delete node;
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
        else
        {
            root->middle = InsertRecursive(root->middle, data);
        }

        return root;
    }

    Node *FindSuccessor(Node *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
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
            if (node->left == nullptr && node->right == nullptr && node->middle == nullptr)
            {
                delete node;
                node = nullptr;
            }
            else if (node->middle != nullptr)
            {
                Node *temp = node->middle;
                temp->right = node->right;
                temp->left = node->left;
                delete node;
                node = temp;
            }
            else if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                node = temp;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                node = temp;
            }
            else
            {
                Node *successor = FindSuccessor(node->right);
                node->data = successor->data;
                RemoveRecursive(node->right, successor->data);
            }
        }
    }

    bool SearchElementRecursive(Node *root, T value)
    {
        if (root == nullptr)
        {
            return false;
        }

        if (KeyFunction(value, root->data) == 0)
        {
            return true;
        }

        return SearchElementRecursive(root->left, value) || SearchElementRecursive(root->right, value) || SearchElementRecursive(root->middle, value);
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
                TreeTraversalRecursive(root->middle, arr, index, traversal);
                TreeTraversalRecursive(root->right, arr, index, traversal);
                break;

            case RIGHT_ROOT_LEFT:
                TreeTraversalRecursive(root->right, arr, index, traversal);
                arr[index++] = root->data;
                TreeTraversalRecursive(root->middle, arr, index, traversal);
                TreeTraversalRecursive(root->left, arr, index, traversal);
                break;

            case ROOT_LEFT_RIGHT:
                arr[index++] = root->data;
                TreeTraversalRecursive(root->middle, arr, index, traversal);
                TreeTraversalRecursive(root->left, arr, index, traversal);
                TreeTraversalRecursive(root->right, arr, index, traversal);
                break;

            case ROOT_RIGHT_LEFT:
                arr[index++] = root->data;
                TreeTraversalRecursive(root->middle, arr, index, traversal);
                TreeTraversalRecursive(root->right, arr, index, traversal);
                TreeTraversalRecursive(root->left, arr, index, traversal);
                break;

            case LEFT_RIGHT_ROOT:
                TreeTraversalRecursive(root->left, arr, index, traversal);
                TreeTraversalRecursive(root->right, arr, index, traversal);
                arr[index++] = root->data;
                TreeTraversalRecursive(root->middle, arr, index, traversal);
                break;

            case RIGHT_LEFT_ROOT:
                TreeTraversalRecursive(root->right, arr, index, traversal);
                TreeTraversalRecursive(root->left, arr, index, traversal);
                arr[index++] = root->data;
                TreeTraversalRecursive(root->middle, arr, index, traversal);
                break;
            }
        }
    }

    void WhereRecursive(Node *root, TernaryTree<T> &newTree, std::function<bool(T)> condition)
    {
        if (root != nullptr)
        {
            if (condition(root->data))
            {
                newTree.Insert(root->data);
            }
            WhereRecursive(root->left, newTree, condition);
            WhereRecursive(root->middle, newTree, condition);
            WhereRecursive(root->right, newTree, condition);
        }
    }

    void MergeRecursive(Node *root1, Node *root2)
    {
        if (root2 != nullptr)
        {
            MergeRecursive(root1, root2->left);
            MergeRecursive(root1, root2->middle);
            MergeRecursive(root1, root2->right);
            root1 = InsertRecursive(root1, root2->data);
        }
    }

    template <typename U>
    void MapRecursive(Node *root, TernaryTree<U> &newTree, std::function<U(T)> func)
    {
        if (root != nullptr)
        {
            newTree.Insert(func(root->data));
            MapRecursive(root->left, newTree, func);
            MapRecursive(root->middle, newTree, func);
            MapRecursive(root->right, newTree, func);
        }
    }
};

template <class T>
TernaryTree<T>::TernaryTree(const int (*KeyFunction)(const T &, const T &))
{
    root = nullptr;
    size = 0;
    this->KeyFunction = KeyFunction;
}

template <class T>
TernaryTree<T>::TernaryTree(const TernaryTree &tree, const int (*KeyFunction)(const T &, const T &))
{
    root = CopyTree(tree.root);
    this->size = tree.size;
}

template <class T>
TernaryTree<T>::~TernaryTree()
{
    DeleteTree(root);
}

template <class T>
void TernaryTree<T>::Insert(const T &data)
{
    root = InsertRecursive(root, data);
    size++;
}

template <class T>
bool TernaryTree<T>::SearchElement(const T &data)
{
    return SearchElementRecursive(root, data);
}

template <class T>
void TernaryTree<T>::Remove(const T &data)
{
    RemoveRecursive(root, data);
    size--;
}

template <class T>
const T *TernaryTree<T>::TreeTraversal(const Traversal &traversal)
{
    int index = 0;
    T *arr = new T[size];
    TreeTraversalRecursive(root, arr, index, traversal);
    return arr;
}

template <class T>
TernaryTree<T> TernaryTree<T>::Where(std::function<bool(T)> condition)
{
    TernaryTree<T> newTree(KeyFunction);
    WhereRecursive(root, newTree, condition);
    return newTree;
}

template <class T>
void TernaryTree<T>::Merge(TernaryTree<T> &Tree)
{
    MergeRecursive(root, Tree.root);
}

template <class T>
int TernaryTree<T>::GetSize()
{
    return size;
}

#endif