#ifndef KEY_FUNCTIONS
#define KEY_FUNCTIONS

#include "Student.h"
#include <functional>
#include "Complex.h"

const int CompareID(const Student &student1, const Student &student2)
{
    if (student1.getId() < student2.getId())
        return -1;
    else if (student1.getId() > student2.getId())
        return 1;
    else
        return 0;
}

const int CompareAvg(const Student &student1, const Student &student2)
{
    if (student1.getAvgGrade() < student2.getAvgGrade())
        return -1;
    else if (student1.getAvgGrade() > student2.getAvgGrade())
        return 1;
    else
        return 0;
}

const int CompareName(const Student &student1, const Student &student2)
{
    if (student1.getName() < student2.getName())
        return -1;
    else if (student1.getName() > student2.getName())
        return 1;
    else
        return 0;
}

const int CompareSurname(const Student &student1, const Student &student2)
{
    if (student1.getSurname() < student2.getSurname())
        return -1;
    else if (student1.getSurname() > student2.getSurname())
        return 1;
    else
        return 0;
}

const int CompareUniversity(const Student &student1, const Student &student2)
{
    if (student1.getUniversity() < student2.getUniversity())
        return -1;
    else if (student1.getUniversity() < student2.getUniversity())
        return 1;
    else
        return 0;
}

const int CompareInt(const int &num1, const int &num2)
{
    if (num1 < num2)
        return -1;
    else if (num1 > num2)
        return 1;
    else
        return 0;
}

const int CompareDouble(const double &num1, const double &num2)
{
    if (num1 < num2)
        return -1;
    else if (num1 > num2)
        return 1;
    else
        return 0;
}

const int CompareComplex(const Complex &num1, const Complex &num2)
{
    if (num1 < num2)
        return -1;
    else if (num1 > num2)
        return 1;
    else
        return 0;
}

const int (*KeyFunctionsStudents[5])(const Student &, const Student &) = {CompareID, CompareAvg, CompareName, CompareSurname, CompareUniversity};
const int (*KeyFunctionInt)(const int &, const int &) = {CompareInt};
const int (*KeyFunctionDouble)(const double &, const double &) = CompareDouble;
const int (*KeyFunctionComplex)(const Complex &, const Complex &) = CompareComplex;

#endif