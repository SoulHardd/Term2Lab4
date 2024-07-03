#ifndef TESTS_BINARY_TREE
#define TESTS_BINARY_TREE

#include "Tree.h"
#include <cassert>
#include "Complex.h"
#include "Enums.h"

void tests2Tree()
{
    BinaryTree<int> TreeInt(KeyFunctionInt);
    BinaryTree<double> TreeDouble(KeyFunctionDouble);
    BinaryTree<Complex> TreeComplex(KeyFunctionComplex);

    Complex num1(7, 8), num2(19, 3), num3(0, 1);

    TreeInt.Insert(2);
    TreeInt.Insert(10);
    TreeInt.Insert(4);
    TreeInt.Insert(1);

    TreeDouble.Insert(1.4);
    TreeDouble.Insert(4.5);
    TreeDouble.Insert(1.1);
    TreeDouble.Insert(3);
    TreeDouble.Insert(75.6);

    TreeComplex.Insert(num1);
    TreeComplex.Insert(num2);
    TreeComplex.Insert(num3);

    // traversal test; (L - left, r - root, R - right)
    int TreeIntTraversal_LrR[4] = {1, 2, 4, 10};
    int TreeIntTraversal_LRr[4] = {1, 4, 10, 2};
    int TreeIntTraversal_rLR[4] = {2, 1, 10, 4};
    int TreeIntTraversal_rRL[4] = {2, 10, 4, 1};
    int TreeIntTraversal_RrL[4] = {10, 4, 2, 1};
    int TreeIntTraversal_RLr[4] = {4, 10, 1, 2};

    for (int i = 0; i < 4; i++)
    {
        assert((TreeInt.TreeTraversal(LEFT_ROOT_RIGHT))[i] == TreeIntTraversal_LrR[i]);
        assert((TreeInt.TreeTraversal(LEFT_RIGHT_ROOT))[i] == TreeIntTraversal_LRr[i]);
        assert((TreeInt.TreeTraversal(ROOT_LEFT_RIGHT))[i] == TreeIntTraversal_rLR[i]);
        assert((TreeInt.TreeTraversal(ROOT_RIGHT_LEFT))[i] == TreeIntTraversal_rRL[i]);
        assert((TreeInt.TreeTraversal(RIGHT_ROOT_LEFT))[i] == TreeIntTraversal_RrL[i]);
        assert((TreeInt.TreeTraversal(RIGHT_LEFT_ROOT))[i] == TreeIntTraversal_RLr[i]);
    }

    double TreeDoubleTraversal_LrR[5] = {1.1, 1.4, 3, 4.5, 75.6};
    double TreeDoubleTraversal_LRr[5] = {1.1, 3, 75.6, 4.5, 1.4};
    double TreeDoubleTraversal_rLR[5] = {1.4, 1.1, 4.5, 3, 75.6};
    double TreeDoubleTraversal_rRL[5] = {1.4, 4.5, 75.6, 3, 1.1};
    double TreeDoubleTraversal_RrL[5] = {75.6, 4.5, 3, 1.4, 1.1};
    double TreeDoubleTraversal_RLr[5] = {75.6, 3, 4.5, 1.1, 1.4};

    for (int i = 0; i < 5; i++)
    {
        assert((TreeDouble.TreeTraversal(LEFT_ROOT_RIGHT))[i] == TreeDoubleTraversal_LrR[i]);
        assert((TreeDouble.TreeTraversal(LEFT_RIGHT_ROOT))[i] == TreeDoubleTraversal_LRr[i]);
        assert((TreeDouble.TreeTraversal(ROOT_LEFT_RIGHT))[i] == TreeDoubleTraversal_rLR[i]);
        assert((TreeDouble.TreeTraversal(ROOT_RIGHT_LEFT))[i] == TreeDoubleTraversal_rRL[i]);
        assert((TreeDouble.TreeTraversal(RIGHT_ROOT_LEFT))[i] == TreeDoubleTraversal_RrL[i]);
        assert((TreeDouble.TreeTraversal(RIGHT_LEFT_ROOT))[i] == TreeDoubleTraversal_RLr[i]);
    }

    Complex TreeComplexTraversal_LrR[3] = {num3, num1, num2};
    Complex TreeComplexTraversal_LRr[3] = {num3, num2, num1};
    Complex TreeComplexTraversal_rLR[3] = {num1, num3, num2};
    Complex TreeComplexTraversal_rRL[3] = {num1, num2, num3};
    Complex TreeComplexTraversal_RrL[3] = {num2, num1, num3};
    Complex TreeComplexTraversal_RLr[3] = {num2, num3, num1};

    for (int i = 0; i < 3; i++)
    {
        assert((TreeComplex.TreeTraversal(LEFT_ROOT_RIGHT))[i] == TreeComplexTraversal_LrR[i]);
        assert((TreeComplex.TreeTraversal(LEFT_RIGHT_ROOT))[i] == TreeComplexTraversal_LRr[i]);
        assert((TreeComplex.TreeTraversal(ROOT_LEFT_RIGHT))[i] == TreeComplexTraversal_rLR[i]);
        assert((TreeComplex.TreeTraversal(ROOT_RIGHT_LEFT))[i] == TreeComplexTraversal_rRL[i]);
        assert((TreeComplex.TreeTraversal(RIGHT_ROOT_LEFT))[i] == TreeComplexTraversal_RrL[i]);
        assert((TreeComplex.TreeTraversal(RIGHT_LEFT_ROOT))[i] == TreeComplexTraversal_RLr[i]);
    }

    // Search element test
    assert(TreeInt.SearchElement(2));
    assert(!(TreeInt.SearchElement(500)));

    assert(TreeDouble.SearchElement(75.6));
    assert(!(TreeDouble.SearchElement(55.55)));

    Complex IncorrectNum(34, 5);
    assert(TreeComplex.SearchElement(num1));
    assert(!(TreeComplex.SearchElement(IncorrectNum)));

    // Map test
    auto MappedTree1 = TreeInt.Map<int>([](int x)
                                        { return x * 2; });
    int CorrectMappedTree1[4] = {2, 4, 8, 20};

    auto MappedTree2 = TreeInt.Map<int>([](int x)
                                        { return x * 3; });
    int CorrectMappedTree2[4] = {3, 6, 12, 30};
    for (int i = 0; i < 4; i++)
    {
        assert((MappedTree1.TreeTraversal(LEFT_ROOT_RIGHT))[i] == CorrectMappedTree1[i]);
        assert((MappedTree2.TreeTraversal(LEFT_ROOT_RIGHT))[i] == CorrectMappedTree2[i]);
    }

    // Where test
    TreeInt.Insert(20);
    TreeInt.Insert(3);
    auto filteredTree1 = TreeInt.Where([](int x)
                                       { return x % 2 == 0; });
    auto filteredTree2 = TreeInt.Where([](int x)
                                       { return x % 10 == 0; });
    int CorrectFilteredTree1[4] = {2, 4, 10, 20};
    int CorrectFilteredTree2[2] = {10, 20};
    for (int i = 0; i < 4; i++)
    {
        assert((filteredTree1.TreeTraversal(LEFT_ROOT_RIGHT))[i] == CorrectFilteredTree1[i]);
    }
    for (int i = 0; i < 2; i++)
    {
        assert((filteredTree2.TreeTraversal(LEFT_ROOT_RIGHT))[i] == CorrectFilteredTree2[i]);
    }
    // Merge test
    BinaryTree<int> tree1(KeyFunctionInt);
    tree1.Insert(5);
    tree1.Insert(3);
    tree1.Insert(7);

    BinaryTree<int> tree2(KeyFunctionInt);
    tree2.Insert(1);
    tree2.Insert(4);
    tree2.Insert(6);
    tree1.Merge(tree2);
    int CorrectMergeTree[6] = {1, 3, 4, 5, 6, 7};
    for (int i = 0; i < 6; i++)
    {
        assert((tree1.TreeTraversal(LEFT_ROOT_RIGHT))[i] == CorrectMergeTree[i]);
    }

    // Remove test

    BinaryTree<int> removeTree1(KeyFunctionInt);
    removeTree1.Insert(1);
    removeTree1.Insert(2);
    removeTree1.Insert(3);
    removeTree1.Remove(2);

    int correctRemoveTree1[2] = {1, 3};
    assert((removeTree1.TreeTraversal(LEFT_ROOT_RIGHT))[0] == correctRemoveTree1[0]);
    assert((removeTree1.TreeTraversal(LEFT_ROOT_RIGHT))[1] == correctRemoveTree1[1]);

    std::cout << "Binary tree test were passed successfully\n";
}

#endif