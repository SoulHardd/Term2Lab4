#include <iostream>
#include "Tree.h"
#include <cassert>
#include "Complex.h"

void tests()
{
    BinaryTree<int> TreeInt;
    BinaryTree<double> TreeDouble;
    BinaryTree<Complex> TreeComplex;
    Complex num1(7, 8), num2(19, 3), num3(0, 1);

    TreeInt.insert(2);
    TreeInt.insert(10);
    TreeInt.insert(4);
    TreeInt.insert(1);

    TreeDouble.insert(1.4);
    TreeDouble.insert(4.5);
    TreeDouble.insert(1.1);
    TreeDouble.insert(3);
    TreeDouble.insert(75.6);

    TreeComplex.insert(num1);
    TreeComplex.insert(num2);
    TreeComplex.insert(num3);

    // traversal test; (L - left, r - root, R - right)
    int TreeIntTraversal_LrR[4] = {1, 2, 4, 10};
    int TreeIntTraversal_LRr[4] = {1, 4, 10, 2};
    int TreeIntTraversal_rLR[4] = {2, 1, 10, 4};
    int TreeIntTraversal_rRL[4] = {2, 10, 4, 1};
    int TreeIntTraversal_RrL[4] = {10, 4, 2, 1};
    int TreeIntTraversal_RLr[4] = {4, 10, 1, 2};

    for (int i = 0; i < 4; i++)
    {
        assert((TreeInt.LeftRootRight())[i] == TreeIntTraversal_LrR[i]);
        assert((TreeInt.LeftRightRoot())[i] == TreeIntTraversal_LRr[i]);
        assert((TreeInt.RootLeftRight())[i] == TreeIntTraversal_rLR[i]);
        assert((TreeInt.RootRightLeft())[i] == TreeIntTraversal_rRL[i]);
        assert((TreeInt.RightRootLeft())[i] == TreeIntTraversal_RrL[i]);
        assert((TreeInt.RightLeftRoot())[i] == TreeIntTraversal_RLr[i]);
    }

    double TreeDoubleTraversal_LrR[5] = {1.1, 1.4, 3, 4.5, 75.6};
    double TreeDoubleTraversal_LRr[5] = {1.1, 3, 75.6, 4.5, 1.4};
    double TreeDoubleTraversal_rLR[5] = {1.4, 1.1, 4.5, 3, 75.6};
    double TreeDoubleTraversal_rRL[5] = {1.4, 4.5, 75.6, 3, 1.1};
    double TreeDoubleTraversal_RrL[5] = {75.6, 4.5, 3, 1.4, 1.1};
    double TreeDoubleTraversal_RLr[5] = {75.6, 3, 4.5, 1.1, 1.4};

    for (int i = 0; i < 5; i++)
    {
        assert((TreeDouble.LeftRootRight())[i] == TreeDoubleTraversal_LrR[i]);
        assert((TreeDouble.LeftRightRoot())[i] == TreeDoubleTraversal_LRr[i]);
        assert((TreeDouble.RootLeftRight())[i] == TreeDoubleTraversal_rLR[i]);
        assert((TreeDouble.RootRightLeft())[i] == TreeDoubleTraversal_rRL[i]);
        assert((TreeDouble.RightRootLeft())[i] == TreeDoubleTraversal_RrL[i]);
        assert((TreeDouble.RightLeftRoot())[i] == TreeDoubleTraversal_RLr[i]);
    }

    Complex TreeComplexTraversal_LrR[3] = {num3, num1, num2};
    Complex TreeComplexTraversal_LRr[3] = {num3, num2, num1};
    Complex TreeComplexTraversal_rLR[3] = {num1, num3, num2};
    Complex TreeComplexTraversal_rRL[3] = {num1, num2, num3};
    Complex TreeComplexTraversal_RrL[3] = {num2, num1, num3};
    Complex TreeComplexTraversal_RLr[3] = {num2, num3, num1};

    for (int i = 0; i < 3; i++)
    {
        assert((TreeComplex.LeftRootRight())[i] == TreeComplexTraversal_LrR[i]);
        assert((TreeComplex.LeftRightRoot())[i] == TreeComplexTraversal_LRr[i]);
        assert((TreeComplex.RootLeftRight())[i] == TreeComplexTraversal_rLR[i]);
        assert((TreeComplex.RootRightLeft())[i] == TreeComplexTraversal_rRL[i]);
        assert((TreeComplex.RightRootLeft())[i] == TreeComplexTraversal_RrL[i]);
        assert((TreeComplex.RightLeftRoot())[i] == TreeComplexTraversal_RLr[i]);
    }

    // Search element test
    assert(TreeInt.searchElement(2));
    assert(!(TreeInt.searchElement(500)));

    assert(TreeDouble.searchElement(75.6));
    assert(!(TreeDouble.searchElement(55.55)));

    Complex IncorrectNum(34, 5);
    assert(TreeComplex.searchElement(num1));
    assert(!(TreeComplex.searchElement(IncorrectNum)));

    // Map test
    auto mappedTree1 = TreeInt.map<int>([](int x)
                                        { return x * 2; });
    int CorrectMappedTree1[4] = {2, 4, 8, 20};

    auto mappedTree2 = TreeInt.map<int>([](int x)
                                        { return x * 3; });
    int CorrectMappedTree2[4] = {3, 6, 12, 30};
    for (int i = 0; i < 4; i++)
    {
        assert((mappedTree1.LeftRootRight())[i] == CorrectMappedTree1[i]);
        assert((mappedTree2.LeftRootRight())[i] == CorrectMappedTree2[i]);
    }

    // Where test
    TreeInt.insert(20);
    TreeInt.insert(3);
    auto filteredTree1 = TreeInt.where([](int x)
                                       { return x % 2 == 0; });
    auto filteredTree2 = TreeInt.where([](int x)
                                       { return x % 10 == 0; });
    int CorrectFilteredTree1[4] = {2, 4, 10, 20};
    int CorrectFilteredTree2[2] = {10, 20};
    for (int i = 0; i < 4; i++)
    {
        assert((filteredTree1.LeftRootRight())[i] == CorrectFilteredTree1[i]);
    }
    for (int i = 0; i < 2; i++)
    {
        assert((filteredTree2.LeftRootRight())[i] == CorrectFilteredTree2[i]);
    }
}