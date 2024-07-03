#ifndef TESTS_STUDENTS
#define TESTS_STUDENTS

#include "Tree.h"
#include <cassert>
#include "Complex.h"
#include "TernaryTree.h"
#include "Enums.h"

void testsStudents()
{

    TernaryTree<Student> StudentsID(KeyFunctionsStudents[ID]);
    TernaryTree<Student> StudentsGrade(KeyFunctionsStudents[AVG_GRADE]);
    TernaryTree<Student> StudentsName(KeyFunctionsStudents[NAME]);
    TernaryTree<Student> StudentsSurname(KeyFunctionsStudents[SURNAME]);
    TernaryTree<Student> StudentsUniversity(KeyFunctionsStudents[UNIVERSITY]);

    Student student1(123, "Vladislav", "Bogatyrenko", 4.5, "MEPHI");
    Student student2(52, "Kirill", "Antonov", 4.5, "MSU");
    Student student3(154, "Artur", "Usupov", 3.3, "KFU");
    Student student4(555, "Vladimir", "Bogatyrenko", 4.2, "MEPHI");
    Student student5(78, "Artem", "Kuznetsov", 2.7, "MIPT");
    Student student6(1, "Elena", "Markosyan", 5, "NSU");

    StudentsID.Insert(student1);
    StudentsID.Insert(student2);
    StudentsID.Insert(student3);
    StudentsID.Insert(student4);
    StudentsID.Insert(student5);
    StudentsID.Insert(student6);

    long int IdCorrectOrder[6] = {1, 52, 78, 123, 154, 555};

    StudentsGrade.Insert(student1);
    StudentsGrade.Insert(student2);
    StudentsGrade.Insert(student3);
    StudentsGrade.Insert(student4);
    StudentsGrade.Insert(student5);
    StudentsGrade.Insert(student6);

    double GradeCorrectOrder[6] = {2.7, 3.3, 4.2, 4.5, 4.5, 5};

    StudentsName.Insert(student1);
    StudentsName.Insert(student2);
    StudentsName.Insert(student3);
    StudentsName.Insert(student4);
    StudentsName.Insert(student5);
    StudentsName.Insert(student6);

    String NameCorrectOrder[6] = {"Artem", "Artur", "Elena", "Kirill", "Vladimir", "Vladislav"};

    StudentsSurname.Insert(student1);
    StudentsSurname.Insert(student2);
    StudentsSurname.Insert(student3);
    StudentsSurname.Insert(student4);
    StudentsSurname.Insert(student5);
    StudentsSurname.Insert(student6);

    String SurnameCorrectOrder[6] = {"Antonov", "Bogatyrenko", "Bogatyrenko", "Kuznetsov", "Markosyan", "Usupov"};

    StudentsUniversity.Insert(student1);
    StudentsUniversity.Insert(student2);
    StudentsUniversity.Insert(student3);
    StudentsUniversity.Insert(student4);
    StudentsUniversity.Insert(student5);
    StudentsUniversity.Insert(student6);

    String UniversityCorrectOrder[6] = {"KFU", "MEPHI", "MEPHI", "MIPT", "MSU", "NSU"};

    for (int i = 0; i < 6; i++)
    {
        assert(((StudentsID.TreeTraversal(LEFT_ROOT_RIGHT))[i]).getId() == IdCorrectOrder[i]);
        assert(((StudentsGrade.TreeTraversal(LEFT_ROOT_RIGHT))[i]).getAvgGrade() == GradeCorrectOrder[i]);
        assert(((StudentsName.TreeTraversal(LEFT_ROOT_RIGHT))[i]).getName() == NameCorrectOrder[i]);
        assert(((StudentsSurname.TreeTraversal(LEFT_ROOT_RIGHT))[i]).getSurname() == SurnameCorrectOrder[i]);
        assert(((StudentsUniversity.TreeTraversal(LEFT_ROOT_RIGHT))[i]).getUniversity() == UniversityCorrectOrder[i]);
    }

    std::cout << "Students tests were passed successfully\n\n";
}

#endif