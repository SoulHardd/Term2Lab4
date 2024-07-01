#include <iostream>
#include "Tests2Tree.h"
#include "Tests3Tree.h"
#include "TestsStudents.h"

int mainMenu();
int DataTypeChoice();
template <class T>
void ReadNInsertElementsBinary(BinaryTree<T> &Tree);
template <class T>
void ReadNInsertElementsTernary(TernaryTree<T> &Tree);
int actionMenu();
template <class T>
void ActionsOfActionMenuBinary(BinaryTree<T> &Tree, int action);
template <class T>
void ActionsOfActionMenuTernary(TernaryTree<T> &Tree, int action);
void ActionsOfActionMenuTernaryComplex(TernaryTree<Complex> &Tree, int action);
void ActionsOfActionMenuBinaryComplex(BinaryTree<Complex> &Tree, int action);
void ReadNInsertElementsBinaryComplex(BinaryTree<Complex> &Tree);
void ReadNInsertElementsTernaryComplex(TernaryTree<Complex> &Tree);

void ActionsOfActionMenuTernaryStudent(TernaryTree<Student> &Tree, int action);
void ActionsOfActionMenuBinaryStudent(BinaryTree<Student> &Tree, int action);
void ReadNInsertElementsBinaryStudent(BinaryTree<Student> &Tree);
void ReadNInsertElementsTernaryStudent(TernaryTree<Student> &Tree);
Key ChooseStudentKey();

void UI()
{
    int mainMenuChoice = mainMenu();
    int DataType, ActMenuChoice;
    Key StudentKey;
    switch (mainMenuChoice)
    {
    case 1:
        DataType = DataTypeChoice();
        if (DataType == 1)
        {
            BinaryTree<int> Tree(NUMBERS);
            ReadNInsertElementsBinary(Tree);
            do
            {
                ActMenuChoice = actionMenu();
                ActionsOfActionMenuBinary(Tree, ActMenuChoice);
            } while (ActMenuChoice != 5);
        }
        else if (DataType == 2)
        {
            BinaryTree<double> Tree(NUMBERS);
            ReadNInsertElementsBinary(Tree);
            do
            {
                ActMenuChoice = actionMenu();
                ActionsOfActionMenuBinary(Tree, ActMenuChoice);
            } while (ActMenuChoice != 5);
        }
        else if (DataType == 3)
        {
            BinaryTree<Complex> Tree(NUMBERS);
            ReadNInsertElementsBinaryComplex(Tree);
            do
            {
                ActMenuChoice = actionMenu();
                ActionsOfActionMenuBinaryComplex(Tree, ActMenuChoice);
            } while (ActMenuChoice != 5);
        }
        else
        {
            StudentKey = ChooseStudentKey();
            BinaryTree<Student> Tree(StudentKey);
            ReadNInsertElementsBinaryStudent(Tree);
            do
            {
                ActMenuChoice = actionMenu();
                ActionsOfActionMenuBinaryStudent(Tree, ActMenuChoice);
            } while (ActMenuChoice != 5);
        }

        break;

    case 2:
        DataType = DataTypeChoice();
        if (DataType == 1)
        {
            TernaryTree<int> Tree(NUMBERS);
            ReadNInsertElementsTernary(Tree);
            do
            {
                ActMenuChoice = actionMenu();
                ActionsOfActionMenuTernary(Tree, ActMenuChoice);
            } while (ActMenuChoice != 5);
        }
        else if (DataType == 2)
        {
            TernaryTree<double> Tree(NUMBERS);
            ReadNInsertElementsTernary(Tree);
            do
            {
                ActMenuChoice = actionMenu();
                ActionsOfActionMenuTernary(Tree, ActMenuChoice);
            } while (ActMenuChoice != 5);
        }
        else if (DataType == 3)
        {
            TernaryTree<Complex> Tree(NUMBERS);
            ReadNInsertElementsTernaryComplex(Tree);
            do
            {
                ActMenuChoice = actionMenu();
                ActionsOfActionMenuTernaryComplex(Tree, ActMenuChoice);
            } while (ActMenuChoice != 5);
        }
        else
        {
            StudentKey = ChooseStudentKey();
            TernaryTree<Student> Tree(StudentKey);
            ReadNInsertElementsTernaryStudent(Tree);
            do
            {
                ActMenuChoice = actionMenu();
                ActionsOfActionMenuTernaryStudent(Tree, ActMenuChoice);
            } while (ActMenuChoice != 5);
        }
        break;
    case 3:
        tests2Tree();
        tests3Tree();
        testsStudents();
        break;

    case 4:
        return;

    default:
        std::cout << "Incorrect choice\n\n";
        UI();
        break;
    }
    UI();
}

int mainMenu()
{
    std::cout << "Choose action by entering its number:\n";
    std::cout << "  1. Create Binary Tree\n"
              << "  2. Create Ternary Tree\n"
              << "  3. Run tests\n"
              << "  4. Exit program\n\n";

    int mainMenuChoice;
    std::cin >> mainMenuChoice;
    return mainMenuChoice;
}

int DataTypeChoice()
{
    std::cout << "Choose data type by entering its number:\n";
    std::cout << "  1. Int\n"
              << "  2. Double\n"
              << "  3. Complex\n"
              << "  4. Students\n\n";
    int DataType;
    do
    {
        std::cin >> DataType;
        if (DataType != 1 && DataType != 2 && DataType != 3 && DataType != 4)
        {
            std::cout << "Incorrect choice\n\n";
        }

    } while (DataType != 1 && DataType != 2 && DataType != 3 && DataType != 4);
    return DataType;
}

template <class T>
void ReadNInsertElementsBinary(BinaryTree<T> &Tree)
{
    std::cout << "Enter number of elements\n\n";
    int size;
    std::cin >> size;
    T element;
    std::cout << "Enter elements\n\n";
    for (int i = 0; i < size; i++)
    {
        std::cin >> element;
        Tree.Insert(element);
    }
    std::cout << "\n\n";
}

void ReadNInsertElementsBinaryComplex(BinaryTree<Complex> &Tree)
{
    std::cout << "Enter number of elements\n\n";
    int size;
    std::cin >> size;
    Complex element;
    std::cout << "Enter elements\n\n";
    for (int i = 0; i < size; i++)
    {
        std::cout << "Re: ";
        std::cin >> element.re;
        std::cout << "Im: ";
        std::cin >> element.im;
        Tree.Insert(element);
    }
    std::cout << "\n\n";
}

void ReadNInsertElementsTernaryComplex(TernaryTree<Complex> &Tree)
{
    std::cout << "Enter number of elements\n\n";
    int size;
    std::cin >> size;
    Complex element;
    std::cout << "Enter elements\n\n";
    for (int i = 0; i < size; i++)
    {
        std::cout << "Re: ";
        std::cin >> element.re;
        std::cout << "Im: ";
        std::cin >> element.im;
        Tree.Insert(element);
    }
    std::cout << "\n\n";
}

void ReadNInsertElementsBinaryStudent(BinaryTree<Student> &Tree)
{
    std::cout << "Enter number of elements\n\n";
    int size;
    std::cin >> size;
    long int Id;
    double avg_grade;
    String name, surname, university;
    Student student;
    std::cout << "Enter elements\n\n";
    for (int i = 0; i < size; i++)
    {
        std::cout << "Id: ";
        std::cin >> Id;
        std::cout << "Average grade: ";
        std::cin >> avg_grade;
        std::cout << "Name: ";
        std::cin >> name;
        std::cout << "Surname: ";
        std::cin >> surname;
        std::cout << "University: ";
        std::cin >> university;
        student.Fill(Id, name, surname, avg_grade, university);
        Tree.Insert(student);
    }
    std::cout << "\n\n";
}

void ReadNInsertElementsTernaryStudent(TernaryTree<Student> &Tree)
{
    std::cout << "Enter number of elements\n\n";
    int size;
    std::cin >> size;
    long int Id;
    double avg_grade;
    String name, surname, university;
    Student student;
    std::cout << "Enter elements\n\n";
    for (int i = 0; i < size; i++)
    {
        std::cout << "Id: ";
        std::cin >> Id;
        std::cout << "Average grade: ";
        std::cin >> avg_grade;
        std::cout << "Name: ";
        std::cin >> name;
        std::cout << "Surname: ";
        std::cin >> surname;
        std::cout << "University: ";
        std::cin >> university;
        student.Fill(Id, name, surname, avg_grade, university);
        Tree.Insert(student);
    }
    std::cout << "\n\n";
}

template <class T>
void ReadNInsertElementsTernary(TernaryTree<T> &Tree)
{
    std::cout << "Enter number of elements\n\n";
    int size;
    std::cin >> size;
    T element;
    std::cout << "Enter elements\n\n";
    for (int i = 0; i < size; i++)
    {
        std::cin >> element;
        Tree.Insert(element);
    }
    std::cout << "\n\n";
}

int actionMenu()
{
    int actionMenuChoice;
    do
    {
        std::cout << "Choose action by entering its number:\n";
        std::cout << "  1. Print in ascending order\n"
                  << "  2. Print in descending order\n"
                  << "  3. Insert element\n"
                  << "  4. Remove element\n"
                  << "  5. Go to main menu\n\n";
        std::cin >> actionMenuChoice;
        if (actionMenuChoice != 1 && actionMenuChoice != 2 && actionMenuChoice != 3 && actionMenuChoice != 4 && actionMenuChoice != 5)
        {
            std::cout << "Incorrect action";
        }

    } while (actionMenuChoice != 1 && actionMenuChoice != 2 && actionMenuChoice != 3 && actionMenuChoice != 4 && actionMenuChoice != 5);
    return actionMenuChoice;
}

template <class T>
void ActionsOfActionMenuBinary(BinaryTree<T> &Tree, int action)
{
    T element;
    switch (action)
    {
    case 1:
        for (int i = 0; i < Tree.GetSize(); i++)
        {
            std::cout << (Tree.TreeTraversal(LEFT_ROOT_RIGHT))[i] << " ";
        }
        std::cout << "\n\n";

        break;

    case 2:
        for (int i = 0; i < Tree.GetSize(); i++)
        {
            std::cout << (Tree.TreeTraversal(RIGHT_ROOT_LEFT))[i] << " ";
        }
        std::cout << "\n\n";

        break;

    case 3:
        std::cout << "Enter element\n";
        std::cin >> element;
        Tree.Insert(element);
        break;
    case 4:
        std::cout << "Enter element\n";
        std::cin >> element;
        Tree.Remove(element);
        break;
    }
}

template <class T>
void ActionsOfActionMenuTernary(TernaryTree<T> &Tree, int action)
{
    T element;
    switch (action)
    {
    case 1:
        for (int i = 0; i < Tree.GetSize(); i++)
        {
            std::cout << (Tree.TreeTraversal(LEFT_ROOT_RIGHT))[i] << " ";
        }
        std::cout << "\n\n";

        break;

    case 2:
        for (int i = 0; i < Tree.GetSize(); i++)
        {
            std::cout << (Tree.TreeTraversal(RIGHT_ROOT_LEFT))[i] << " ";
        }
        std::cout << "\n\n";

        break;

    case 3:
        std::cout << "Enter element\n";
        std::cin >> element;
        Tree.Insert(element);
        break;
    case 4:
        std::cout << "Enter element\n";
        std::cin >> element;
        Tree.Remove(element);
        break;
    }
}

void ActionsOfActionMenuBinaryComplex(BinaryTree<Complex> &Tree, int action)
{
    Complex element;
    switch (action)
    {
    case 1:
        for (int i = 0; i < Tree.GetSize(); i++)
        {
            std::cout << (Tree.TreeTraversal(LEFT_ROOT_RIGHT))[i] << " ";
        }
        std::cout << "\n\n";

        break;

    case 2:
        for (int i = 0; i < Tree.GetSize(); i++)
        {
            std::cout << (Tree.TreeTraversal(RIGHT_ROOT_LEFT))[i] << " ";
        }
        std::cout << "\n\n";

        break;

    case 3:
        std::cout << "Enter element\n";
        std::cout << "Re: ";
        std::cin >> element.re;
        std::cout << "Im: ";
        std::cin >> element.im;
        Tree.Insert(element);
        break;
    case 4:
        std::cout << "Enter element\n";
        std::cout << "Re: ";
        std::cin >> element.re;
        std::cout << "Im: ";
        std::cin >> element.im;
        Tree.Remove(element);
        break;
    }
}

void ActionsOfActionMenuTernaryComplex(TernaryTree<Complex> &Tree, int action)
{
    Complex element;
    switch (action)
    {
    case 1:
        for (int i = 0; i < Tree.GetSize(); i++)
        {
            std::cout << (Tree.TreeTraversal(LEFT_ROOT_RIGHT))[i] << " ";
        }
        std::cout << "\n\n";

        break;

    case 2:
        for (int i = 0; i < Tree.GetSize(); i++)
        {
            std::cout << (Tree.TreeTraversal(RIGHT_ROOT_LEFT))[i] << " ";
        }
        std::cout << "\n\n";

        break;

    case 3:
        std::cout << "Enter element\n";
        std::cout << "Re: ";
        std::cin >> element.re;
        std::cout << "Im: ";
        std::cin >> element.im;
        Tree.Insert(element);
        break;
    case 4:
        std::cout << "Enter element\n";
        std::cout << "Re: ";
        std::cin >> element.re;
        std::cout << "Im: ";
        std::cin >> element.im;
        Tree.Remove(element);
        break;
    }
}

void ActionsOfActionMenuBinaryStudent(BinaryTree<Student> &Tree, int action)
{
    Student student;
    long int Id;
    double avg_grade;
    String name, surname, university;
    switch (action)
    {
    case 1:
        for (int i = 0; i < Tree.GetSize(); i++)
        {
            std::cout << (Tree.TreeTraversal(LEFT_ROOT_RIGHT))[i] << " ";
        }
        std::cout << "\n\n";

        break;

    case 2:
        for (int i = 0; i < Tree.GetSize(); i++)
        {
            std::cout << (Tree.TreeTraversal(RIGHT_ROOT_LEFT))[i] << " ";
        }
        std::cout << "\n\n";

        break;

    case 3:
        std::cout << "Id: ";
        std::cin >> Id;
        std::cout << "Average grade: ";
        std::cin >> avg_grade;
        std::cout << "Name: ";
        std::cin >> name;
        std::cout << "Surname: ";
        std::cin >> surname;
        std::cout << "University: ";
        std::cin >> university;
        student.Fill(Id, name, surname, avg_grade, university);
        Tree.Insert(student);
        break;
    case 4:
        std::cout << "Id: ";
        std::cin >> Id;
        std::cout << "Average grade: ";
        std::cin >> avg_grade;
        std::cout << "Name: ";
        std::cin >> name;
        std::cout << "Surname: ";
        std::cin >> surname;
        std::cout << "University: ";
        std::cin >> university;
        student.Fill(Id, name, surname, avg_grade, university);
        Tree.Remove(student);
        break;
    }
}

void ActionsOfActionMenuTernaryStudent(TernaryTree<Student> &Tree, int action)
{
    Student student;
    long int Id;
    double avg_grade;
    String name, surname, university;
    switch (action)
    {
    case 1:
        for (int i = 0; i < Tree.GetSize(); i++)
        {
            std::cout << (Tree.TreeTraversal(LEFT_ROOT_RIGHT))[i] << " ";
        }
        std::cout << "\n\n";

        break;

    case 2:
        for (int i = 0; i < Tree.GetSize(); i++)
        {
            std::cout << (Tree.TreeTraversal(RIGHT_ROOT_LEFT))[i] << " ";
        }
        std::cout << "\n\n";

        break;

    case 3:
        std::cout << "Id: ";
        std::cin >> Id;
        std::cout << "Average grade: ";
        std::cin >> avg_grade;
        std::cout << "Name: ";
        std::cin >> name;
        std::cout << "Surname: ";
        std::cin >> surname;
        std::cout << "University: ";
        std::cin >> university;
        student.Fill(Id, name, surname, avg_grade, university);
        Tree.Insert(student);
        break;
    case 4:
        std::cout << "Id: ";
        std::cin >> Id;
        std::cout << "Average grade: ";
        std::cin >> avg_grade;
        std::cout << "Name: ";
        std::cin >> name;
        std::cout << "Surname: ";
        std::cin >> surname;
        std::cout << "University: ";
        std::cin >> university;
        student.Fill(Id, name, surname, avg_grade, university);
        Tree.Remove(student);
        break;
    }
}

Key ChooseStudentKey()
{
    int studentChoice;
    Key key;
    do
    {
        std::cout << "Choose data type for which the tree will be filled in:\n";
        std::cout << "  1. ID\n"
                  << "  2. Average grade\n"
                  << "  3. Name\n"
                  << "  4. Surname\n"
                  << "  5. University\n\n";

        std::cin >> studentChoice;

        if (studentChoice != 1 && studentChoice != 2 && studentChoice != 3 && studentChoice != 4 && studentChoice != 5)
        {
            std::cout << "Incorrect action";
        }

    } while (studentChoice != 1 && studentChoice != 2 && studentChoice != 3 && studentChoice != 4 && studentChoice != 5);

    switch (studentChoice)
    {
    case 1:
        key = ID;
        break;

    case 2:
        key = AVG_GRADE;
        break;

    case 3:
        key = NAME;
        break;

    case 4:
        key = SURNAME;
        break;

    case 5:
        key = UNIVERSITY;
        break;
    }
    return key;
}