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

        Node(T data) : data(data), left(nullptr), right(nullptr) {}
    };

    Node *root;
    int size;

public:
    BinaryTree()
    {
        root = nullptr;
        size = 0;
    }

    int GetSize()
    {
        return this->size;
    }

    void insert(T data)
    {
        root = insertRecursive(root, data);
        size++;
    }

    void remove(T data)
    {
        root = removeRecursive(root, data);
    }

    T *LeftRootRight()
    {
        int index = 0;
        T *arr = new T[size];
        LeftRootRightRecursive(root, arr, index);
        return arr;
    }

    T *RootLeftRight()
    {
        int index = 0;
        T *arr = new T[size];
        RootLeftRightRecursive(root, arr, index);
        return arr;
    }

    T *LeftRightRoot()
    {
        int index = 0;
        T *arr = new T[size];
        LeftRightRootRecursive(root, arr, index);
        return arr;
    }

    T *RightRootLeft()
    {
        int index = 0;
        T *arr = new T[size];
        RightRootLeftRecursive(root, arr, index);
        return arr;
    }

    T *RootRightLeft()
    {
        int index = 0;
        T *arr = new T[size];
        RootRightLeftRecursive(root, arr, index);
        return arr;
    }

    T *RightLeftRoot()
    {
        int index = 0;
        T *arr = new T[size];
        RightLeftRootRecursive(root, arr, index);
        return arr;
    }

    template <typename U>
    BinaryTree<U> map(std::function<U(T)> func)
    {
        BinaryTree<U> newTree;
        mapRecursive(root, newTree, func);
        return newTree;
    }

    BinaryTree<T> where(std::function<bool(T)> condition)
    {
        BinaryTree<T> newTree;
        whereRecursive(root, newTree, condition);
        return newTree;
    }

    void merge(BinaryTree<T> &otherTree)
    {
        mergeRecursive(root, otherTree.root);
    }

    BinaryTree<T> extractSubtree(T element)
    {
        Node *extractedNode = findAndExtract(root, element);
        BinaryTree<T> extractedTree;
        extractedTree.root = extractedNode;
        return extractedTree;
    }

    bool searchElement(T value)
    {
        return searchElementRecursive(root, value);
    }

private:
    Node *insertRecursive(Node *root, T data)
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

    Node *insertRecursive(Node *root, T data)
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

int main()
{
    // BinaryTree<int> tree;

    // tree.insert(5);
    // tree.insert(3);
    // tree.insert(7);
    // tree.insert(1);
    // tree.insert(4);
    // tree.insert(6);
    // tree.insert(8);

    // tree.LeftRootRight();
    // tree.RootLeftRight();
    // tree.LeftRightRoot();
    // tree.RightRootLeft();
    // tree.RootRightLeft();
    // tree.RightLeftRoot();

    // auto mappedTree = tree.map<double>([](int x)
    //                                    { return x * 2.5; });
    // std::cout << "Mapped tree in order traversal:";
    // mappedTree.LeftRootRight();

    // auto filteredTree = tree.where([](int x)
    //                                { return x % 2 == 0; });
    // std::cout << "Filtered tree in order traversal:";
    // filteredTree.LeftRootRight();

    // BinaryTree<int> tree1;
    // tree1.insert(5);
    // tree1.insert(3);
    // tree1.insert(7);

    // BinaryTree<int> tree2;
    // tree2.insert(1);
    // tree2.insert(4);
    // tree2.insert(6);

    // tree1.merge(tree2);
    // tree1.LeftRootRight();

    // BinaryTree<int> extractedTree = tree1.extractSubtree(3);
    // extractedTree.LeftRootRight();
}