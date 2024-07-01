#ifndef TESTS_TERNARY_TREE
#define TESTS_TERNARY_TREE

#include "TernaryTree.h"
#include <cassert>
#include "Complex.h"
#include "Enums.h"

void tests3Tree()
{
    Complex Num1(1, 1), Num2(3, 5), Num3(7, 8);

    TernaryTree<int> TernaryTreeInt(NUMBERS);
    TernaryTree<double> TernaryTreeDouble(NUMBERS);
    TernaryTree<Complex> TernaryTreeComplex(NUMBERS);

    TernaryTreeInt.Insert(3);
    TernaryTreeInt.Insert(3);
    TernaryTreeInt.Insert(1);
    TernaryTreeInt.Insert(2);
    TernaryTreeInt.Insert(5);

    TernaryTreeDouble.Insert(7.8);
    TernaryTreeDouble.Insert(4);
    TernaryTreeDouble.Insert(11.2);
    TernaryTreeDouble.Insert(7.8);
    TernaryTreeDouble.Insert(28.3);

    TernaryTreeComplex.Insert(Num1);
    TernaryTreeComplex.Insert(Num2);
    TernaryTreeComplex.Insert(Num3);
    TernaryTreeComplex.Insert(Num2);
    TernaryTreeComplex.Insert(Num1);

    // traversal test; (L - left, r - root, R - right, M - Middle)
    int TernaryTreeIntTraversal_LrMR[5] = {1, 2, 3, 3, 5};
    double TernaryTreeDoubleTraversal_LrMR[5] = {4, 7.8, 7.8, 11.2, 28.3};
    Complex TernaryTreeComplexTraversal_LrMR[5] = {Num1, Num1, Num2, Num2, Num3};

    for (int i = 0; i < 5; i++)
    {
        assert((TernaryTreeInt.TreeTraversal(LEFT_ROOT_RIGHT))[i] == TernaryTreeIntTraversal_LrMR[i]);
        assert((TernaryTreeDouble.TreeTraversal(LEFT_ROOT_RIGHT))[i] == TernaryTreeDoubleTraversal_LrMR[i]);
        assert((TernaryTreeComplex.TreeTraversal(LEFT_ROOT_RIGHT))[i] == TernaryTreeComplexTraversal_LrMR[i]);
    }

    // Search element test
    assert(TernaryTreeInt.SearchElement(3));
    assert(TernaryTreeInt.SearchElement(1));
    assert(TernaryTreeInt.SearchElement(5));
    assert(!(TernaryTreeInt.SearchElement(100)));

    assert(TernaryTreeDouble.SearchElement(7.8));
    assert(TernaryTreeDouble.SearchElement(11.2));
    assert(!(TernaryTreeDouble.SearchElement(5.55)));
    assert(!(TernaryTreeDouble.SearchElement(8.87)));

    assert(TernaryTreeComplex.SearchElement(Num1));
    assert(TernaryTreeComplex.SearchElement(Num3));
    assert(TernaryTreeComplex.SearchElement(Num2));
    Complex Num4(9, 1);
    assert(!(TernaryTreeComplex.SearchElement(Num4)));

    // Where tests

    auto filteredTernaryTree1 = TernaryTreeInt.Where([](int x)
                                                     { return x % 3 == 0; });
    auto filteredTernaryTree2 = TernaryTreeDouble.Where([](double x)
                                                        { return x + 1 > 10; });
    int CorrectFilteredTernaryTree1[2] = {3, 3};
    double CorrectFilteredTernaryTree2[2] = {11.2, 28.3};
    assert((filteredTernaryTree1.TreeTraversal(LEFT_ROOT_RIGHT))[0] == CorrectFilteredTernaryTree1[0]);
    assert((filteredTernaryTree1.TreeTraversal(LEFT_ROOT_RIGHT))[1] == CorrectFilteredTernaryTree1[1]);
    for (int i = 0; i < 2; i++)
    {
        assert((filteredTernaryTree2.TreeTraversal(LEFT_ROOT_RIGHT))[i] == CorrectFilteredTernaryTree2[i]);
    }

    // Remove test

    TernaryTree<int> removeTree2(NUMBERS);
    removeTree2.Insert(1);
    removeTree2.Insert(2);
    removeTree2.Insert(3);
    removeTree2.Remove(2);

    int correctRemoveTree2[2] = {1, 3};
    assert((removeTree2.TreeTraversal(LEFT_ROOT_RIGHT))[0] == correctRemoveTree2[0]);
    assert((removeTree2.TreeTraversal(LEFT_ROOT_RIGHT))[1] == correctRemoveTree2[1]);

    // Map test
    auto MappedTernaryTree1 = TernaryTreeInt.Map<int>([](int x)
                                                      { return x * 10; });
    int CorrectMappedTernaryTree1[5] = {10, 20, 30, 30, 50};

    for (int i = 0; i < 5; i++)
    {
        assert((MappedTernaryTree1.TreeTraversal(LEFT_ROOT_RIGHT))[i] == CorrectMappedTernaryTree1[i]);
    }

    std::cout << "Ternary tree tests were passed successfully\n";
}

#endif