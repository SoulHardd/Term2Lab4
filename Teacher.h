#ifndef LAB3_TEACHER_H
#define LAB3_TEACHER_H

#include <iostream>
#include <string>

#define String std::string

class Teacher
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
    int salary;

    Teacher()
    {
        this->id = -1;
        name = "";
        surname = "";
        birthDate = "";
        university = "";

        salary = -1;
        address = "";
        phone = "";
    }

    Teacher(
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

        salary = -1;
        address = "";
        phone = "";
    }

    Teacher(
        long id,
        String name,
        String surname,
        String university,
        String birthDate,
        String address,
        String phone,
        int salary) : Teacher(id, std::move(name), std::move(surname), std::move(university), std::move(birthDate))
    {
        this->salary = salary;
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

    bool operator>(const Teacher &c) const
    {
        return id > c.id;
    }

    bool operator<(const Teacher &c) const
    {
        return id < c.id;
    }

    bool operator>=(const Teacher &c) const
    {
        return id >= c.id;
    }

    bool operator<=(const Teacher &c) const
    {
        return id < c.id;
    }

    bool operator==(const Teacher &c) const
    {
        return id == c.id;
    }

    friend std::ostream &operator<<(std::ostream &os, const Teacher &s)
    {
        return os << "Teacher(" << s.getId() << ")";
    }
};

#endif
