#pragma once
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>


using namespace std;

void TransformString(wstring& string)
{
	transform(++string.begin(), string.end(), ++string.begin(), tolower);
	string[0] = toupper(string[0]);
}

class Person 
{
private :
	wstring name;
	wstring surname;
	wstring fatherName;
public :
	Person() {};
	Person(wstring n, wstring s, wstring f)
	{
		name = n;
		surname = s;
		fatherName = f;
	};
	void SetData() {
		wcin >> surname;
		TransformString(surname);
		wcin >> name;
		TransformString(name);
		wcin >> fatherName;
		TransformString(fatherName);
	};
	void ShowData() {
		wcout << surname << " " << name << " " << fatherName;
	};

    const wstring& GetName() const{ return name; };
	const wstring& GetSurname() const{ return surname; };
	const wstring& GetFatherName() const{ return fatherName; };




    bool operator==(const Person &rhs) const
    {
        return name == rhs.name &&
               surname == rhs.surname &&
               fatherName == rhs.fatherName;
    }

    bool operator!=(const Person &rhs) const
    {
        return !(rhs == *this);
    }

    bool operator<(const Person &rhs) const
    {
       return surname < rhs.surname ;
    }


};

template<>
struct hash<Person>
{
    size_t
    operator()(const Person & obj) const
    {
        return hash<wstring>()(obj.GetSurname()) + hash<wstring>()(obj.GetName()) + hash<wstring>()(obj.GetFatherName());
    }
};
