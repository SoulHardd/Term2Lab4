#ifndef LAB3_STUDENT_H
#define LAB3_STUDENT_H

#include <string>
#include <iostream>

#define String std::string

class Student
{
private:
    long id;
    String name;
    String surname;
    String university;
    String birthDate;

public:
    String address;
    String phone;
    int course;

    Student()
    {
        this->id = -1;
        name = "";
        surname = "";
        birthDate = "";
        university = "";

        course = -1;
        address = "";
        phone = "";
    }

    Student(
        long id,
        String name,
        String surname,
        String university,
        String birthDate)
    {
        this->id = id;
        this->name = std::move(name);
        this->surname = std::move(surname);
        this->birthDate = std::move(birthDate);
        this->university = std::move(university);

        course = -1;
        address = "";
        phone = "";
    }

    Student(
        long id,
        String name,
        String surname,
        String university,
        String birthDate,
        String address,
        String phone,
        int course) : Student(id, std::move(name), std::move(surname), std::move(university), std::move(birthDate))
    {
        this->course = course;
        this->address = std::move(address);
        this->phone = std::move(phone);
    }

    String getName() const
    {
        return name;
    }

    String getSurname() const
    {
        return surname;
    }

    String getUniversity() const
    {
        return university;
    }

    String getBirthDate() const
    {
        return birthDate;
    }

    long getId() const
    {
        return id;
    }

    bool operator>(const Student &c) const
    {
        return id > c.id;
    }

    bool operator<(const Student &c) const
    {
        return id < c.id;
    }

    bool operator>=(const Student &c) const
    {
        return id >= c.id;
    }

    bool operator<=(const Student &c) const
    {
        return id < c.id;
    }

    bool operator==(const Student &c) const
    {
        return id == c.id;
    }

    friend std::ostream &operator<<(std::ostream &os, const Student &s)
    {
        return os << "Student(" << s.getId() << ")";
    }
};

#endif
