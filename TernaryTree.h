#include <iostream>

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

public:
    TernaryTree();
    TernaryTree(const TernaryTree &tree);
    ~TernaryTree();

    void insert(const T &data);
    bool searchElement(const T &data);
    void remove(const T &data);
    int GetSize();

    T *LeftRootMiddleRight();

private:
    Node copyTree(Node Root)
    {
        if (Root == nullptr)
        {
            return nullptr;
        }

        Node newNode = new Node(Root->data);
        newNode->left = copyTree(Root->left);
        newNode->middle = copyTree(Root->middle);
        newNode->right = copyTree(Root->right);

        return newNode;
    }

    void deleteTree(Node *node)
    {
        if (node != nullptr)
        {
            deleteTree(node->left);
            deleteTree(node->middle);
            deleteTree(node->right);
            delete node;
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
        else if (data > root->data)
        {
            root->right = insertRecursive(root->right, data);
        }
        else
        {
            root->middle = insertRecursive(root->middle, data);
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
            if (node->left == nullptr && node->right == nullptr && node->middle == nullptr)
            {
                delete node;
                node = nullptr;
                return;
            }
            else if (node->middle != nullptr)
            {
                Node *temp = node->middle;
                delete node;
                node = temp;
                return;
            }
            else if (node->left == nullptr)
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

        return searchElementRecursive(root->left, value) || searchElementRecursive(root->right, value) || searchElementRecursive(root->middle, value);
    }

    void LeftRootMiddleRightRecursive(Node *root, T *arr, int &index)
    {
        if (root != nullptr)
        {
            LeftRootMiddleRightRecursive(root->left, arr, index);
            arr[index++] = root->data;
            LeftRootMiddleRightRecursive(root->middle, arr, index);
            LeftRootMiddleRightRecursive(root->right, arr, index);
        }
    }
};

template <class T>
TernaryTree<T>::TernaryTree()
{
    root = nullptr;
    size = 0;
}

template <class T>
TernaryTree<T>::TernaryTree(const TernaryTree &tree)
{
    root = copyTree(tree.root);
    this->size = tree.size;
}

template <class T>
TernaryTree<T>::~TernaryTree()
{
    deleteTree(root);
}

template <class T>
void TernaryTree<T>::insert(const T &data)
{
    root = insertRecursive(root, data);
    size++;
}

template <class T>
bool TernaryTree<T>::searchElement(const T &data)
{
    return searchElementRecursive(root, data);
}

template <class T>
void TernaryTree<T>::remove(const T &data)
{
    removeRecursive(root, data);
    size--;
}

template <class T>
T *TernaryTree<T>::LeftRootMiddleRight()
{
    int index = 0;
    T *arr = new T[size];
    LeftRootMiddleRightRecursive(root, arr, index);
    return arr;
}

template <class T>
int TernaryTree<T>::GetSize()
{
    return size;
}