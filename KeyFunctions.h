#ifndef KEY_FUNCTIONS
#define KEY_FUNCTIONS

#include "Student.h"
#include <functional>

template <class T>
bool CompareNumbers(const T &num1, const T &num2)
{
    if (num1 < num2)
        return true;
    else
        return false;
}

bool CompareID(const Student &student1, const Student &student2)
{
    if (student1.getId() < student2.getId())
        return true;
    else
        return false;
}

bool CompareAvg(const Student &student1, const Student &student2)
{
    if (student1.getAvgGrade() < student2.getAvgGrade())
        return true;
    else
        return false;
}

bool CompareName(const Student &student1, const Student &student2)
{
    if (student1.getName() < student2.getName())
        return true;
    else
        return false;
}

bool CompareSurname(const Student &student1, const Student &student2)
{
    if (student1.getSurname() < student2.getSurname())
        return true;
    else
        return false;
}

bool CompareUniversity(const Student &student1, const Student &student2)
{
    if (student1.getUniversity() < student2.getUniversity())
        return true;
    else
        return false;
}

template <class T>
bool EqualCompareNumbers(const T &num1, const T &num2)
{
    if (num1 == num2)
        return true;
    else
        return false;
}

bool EqualCompareID(const Student &student1, const Student &student2)
{
    if (student1.getId() == student2.getId())
        return true;
    else
        return false;
}

bool EqualCompareAvg(const Student &student1, const Student &student2)
{
    if (student1.getAvgGrade() == student2.getAvgGrade())
        return true;
    else
        return false;
}

bool EqualCompareName(const Student &student1, const Student &student2)
{
    if (student1.getName() == student2.getName())
        return true;
    else
        return false;
}

bool EqualCompareSurname(const Student &student1, const Student &student2)
{
    if (student1.getSurname() == student2.getSurname())
        return true;
    else
        return false;
}

bool EqualCompareUniversity(const Student &student1, const Student &student2)
{
    if (student1.getUniversity() == student2.getUniversity())
        return true;
    else
        return false;
}

bool (*KeyFunctions[5])(const Student &student1, const Student &student2) = {CompareID, CompareAvg, CompareName, CompareSurname, CompareUniversity};
bool (*EqualKeyFunctions[5])(const Student &student1, const Student &student2) = {EqualCompareID, EqualCompareAvg, EqualCompareName, EqualCompareSurname, EqualCompareUniversity};

bool Compare(const Key &key, const Student &data1, const Student &data2)
{
    return (*KeyFunctions[key])(data1, data2);
}

template <class T>
bool Compare(const Key &key, const T &data1, const T &data2)
{
    return CompareNumbers(data1, data2);
}

bool EqualCompare(const Key &key, const Student &data1, const Student &data2)
{
    return (*EqualKeyFunctions[key])(data1, data2);
}

template <class T>
bool EqualCompare(const Key &key, const T &data1, const T &data2)
{
    return EqualCompareNumbers(data1, data2);
}

#endif