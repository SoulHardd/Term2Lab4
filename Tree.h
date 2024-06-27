#include <iostream>
#include <functional>

template <typename T>
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

public:
    BinaryTree();
    ~BinaryTree();
    BinaryTree(const BinaryTree &tree);
    BinaryTree(const T *values, const int &size);

    int GetSize();
    void insert(const T &data);
    void remove(const T &data);

    T *LeftRootRight();
    T *RootLeftRight();
    T *LeftRightRoot();
    T *RightRootLeft();
    T *RootRightLeft();
    T *RightLeftRoot();

    BinaryTree<T> where(std::function<bool(T)> condition);
    void merge(BinaryTree<T> &Tree);
    BinaryTree<T> extractSubtree(const T &element);
    bool searchElement(const T &value);

    template <typename U>
    BinaryTree<U> map(std::function<U(T)> func)
    {
        BinaryTree<U> newTree;
        mapRecursive(root, newTree, func);
        return newTree;
    }

private:
    Node *copyRecursive(Node *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        Node *newNode = new Node(node->data);
        newNode->left = copyRecursive(node->left);
        newNode->right = copyRecursive(node->right);

        return newNode;
    }

    void deleteTree(Node *root)
    {
        if (root != nullptr)
        {
            deleteTree(root->left);
            deleteTree(root->right);
            delete root;
        }
    }

    Node *insertRecursive(Node *root, const T &data)
    {
        if (root == nullptr)
        {
            return new Node(data);
        }

        if (data < root->data)
        {
            root->left = insertRecursive(root->left, data);
        }
        else
        {
            root->right = insertRecursive(root->right, data);
        }

        return root;
    }

    void removeRecursive(Node *&node, const T &data)
    {
        if (node == nullptr)
        {
            return;
        }

        if (data < node->data)
        {
            removeRecursive(node->left, data);
        }
        else if (data > node->data)
        {
            removeRecursive(node->right, data);
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
                removeRecursive(node->right, successor->data);
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

    void LeftRootRightRecursive(Node *root, T *arr, int &index)
    {
        if (root != nullptr)
        {
            LeftRootRightRecursive(root->left, arr, index);
            arr[index++] = root->data;
            LeftRootRightRecursive(root->right, arr, index);
        }
    }

    void RootLeftRightRecursive(Node *root, T *arr, int &index)
    {
        if (root != nullptr)
        {
            arr[index++] = root->data;
            RootLeftRightRecursive(root->left, arr, index);
            RootLeftRightRecursive(root->right, arr, index);
        }
    }

    void LeftRightRootRecursive(Node *root, T *arr, int &index)
    {
        if (root != nullptr)
        {
            LeftRightRootRecursive(root->left, arr, index);
            LeftRightRootRecursive(root->right, arr, index);
            arr[index++] = root->data;
        }
    }

    void RightRootLeftRecursive(Node *root, T *arr, int &index)
    {
        if (root != nullptr)
        {
            RightRootLeftRecursive(root->right, arr, index);
            arr[index++] = root->data;
            RightRootLeftRecursive(root->left, arr, index);
        }
    }

    void RootRightLeftRecursive(Node *root, T *arr, int &index)
    {
        if (root != nullptr)
        {
            arr[index++] = root->data;
            RootRightLeftRecursive(root->right, arr, index);
            RootRightLeftRecursive(root->left, arr, index);
        }
    }

    void RightLeftRootRecursive(Node *root, T *arr, int &index)
    {
        if (root != nullptr)
        {
            RightLeftRootRecursive(root->right, arr, index);
            RightLeftRootRecursive(root->left, arr, index);
            arr[index++] = root->data;
        }
    }

    template <typename U>
    void mapRecursive(Node *root, BinaryTree<U> &newTree, std::function<U(T)> func)
    {
        if (root != nullptr)
        {
            newTree.insert(func(root->data));
            mapRecursive(root->left, newTree, func);
            mapRecursive(root->right, newTree, func);
        }
    }

    void whereRecursive(Node *root, BinaryTree<T> &newTree, std::function<bool(T)> condition)
    {
        if (root != nullptr)
        {
            if (condition(root->data))
            {
                newTree.insert(root->data);
            }
            whereRecursive(root->left, newTree, condition);
            whereRecursive(root->right, newTree, condition);
        }
    }

    void mergeRecursive(Node *root1, Node *root2)
    {
        if (root2 != nullptr)
        {
            mergeRecursive(root1, root2->left);
            mergeRecursive(root1, root2->right);
            insert(root1, root2->data);
        }
    }

    void insert(Node *root, T data)
    {
        if (data < root->data)
        {
            if (root->left == nullptr)
            {
                root->left = new Node(data);
            }
            else
            {
                insert(root->left, data);
            }
        }
        else
        {
            if (root->right == nullptr)
            {
                root->right = new Node(data);
            }
            else
            {
                insert(root->right, data);
            }
        }
    }

    Node *findAndExtract(Node *root, T element)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (root->data == element)
        {
            Node *extractedNode = root;
            root = nullptr;
            return extractedNode;
        }
        else if (element < root->data)
        {
            return findAndExtract(root->left, element);
        }
        else
        {
            return findAndExtract(root->right, element);
        }
    }

    bool searchElementRecursive(Node *root, T value)
    {
        if (root == nullptr)
        {
            return false;
        }

        if (root->data == value)
        {
            return true;
        }

        return searchElementRecursive(root->left, value) || searchElementRecursive(root->right, value);
    }
};

template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree &tree)
{
    root = copyRecursive(tree.root);
    this->size = tree.size;
}

template <class T>
BinaryTree<T>::BinaryTree()
{
    root = nullptr;
    size = 0;
}

template <class T>
BinaryTree<T>::BinaryTree(const T *values, const int &size)
{
    root = nullptr;

    for (int i = 0; i < size; ++i)
    {
        insert(values[i]);
    }
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
    deleteTree(root);
}

template <class T>
int BinaryTree<T>::GetSize()
{
    return this->size;
}

template <class T>
void BinaryTree<T>::insert(const T &data)
{
    root = insertRecursive(root, data);
    size++;
}

template <class T>
void BinaryTree<T>::remove(const T &data)
{
    removeRecursive(root, data);
    size--;
}

template <class T>
T *BinaryTree<T>::LeftRootRight()
{
    int index = 0;
    T *arr = new T[size];
    LeftRootRightRecursive(root, arr, index);
    return arr;
}

template <class T>
T *BinaryTree<T>::RootLeftRight()
{
    int index = 0;
    T *arr = new T[size];
    RootLeftRightRecursive(root, arr, index);
    return arr;
}

template <class T>
T *BinaryTree<T>::LeftRightRoot()
{
    int index = 0;
    T *arr = new T[size];
    LeftRightRootRecursive(root, arr, index);
    return arr;
}

template <class T>
T *BinaryTree<T>::RightRootLeft()
{
    int index = 0;
    T *arr = new T[size];
    RightRootLeftRecursive(root, arr, index);
    return arr;
}

template <class T>
T *BinaryTree<T>::RootRightLeft()
{
    int index = 0;
    T *arr = new T[size];
    RootRightLeftRecursive(root, arr, index);
    return arr;
}

template <class T>
T *BinaryTree<T>::RightLeftRoot()
{
    int index = 0;
    T *arr = new T[size];
    RightLeftRootRecursive(root, arr, index);
    return arr;
}

template <class T>
BinaryTree<T> BinaryTree<T>::where(std::function<bool(T)> condition)
{
    BinaryTree<T> newTree;
    whereRecursive(root, newTree, condition);
    return newTree;
}

template <class T>
void BinaryTree<T>::merge(BinaryTree<T> &Tree)
{
    mergeRecursive(root, Tree.root);
}

template <class T>
BinaryTree<T> BinaryTree<T>::extractSubtree(const T &element)
{
    Node *extractedNode = findAndExtract(root, element);
    BinaryTree<T> extractedTree;
    extractedTree.root = extractedNode;
    return extractedTree;
}

template <class T>
bool BinaryTree<T>::searchElement(const T &value)
{
    return searchElementRecursive(root, value);
}