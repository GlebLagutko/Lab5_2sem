#include <iostream>
#include "Person.h"
#include <string>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <fstream>
#include <io.h>
#include <fcntl.h>
#include <codecvt>
#include <queue>
#include <ctime>


using namespace std;

const int Count = 3;

void ShowUnorderedSet(unordered_set < Person , hash<Person>> People )
{
	wcout << L"UnorderedSet : ";
	for (auto a : People)
	{
		a.ShowData();
		wcout << endl;
	}

}

unordered_set<Person> FillUnorderedSet(queue<Person> p)
{
	unordered_set < Person, hash<Person>> People;
	for (int i = 0; i < Count; i++)
	{
		People.insert(p.front());
		p.pop();
	}

	return People;
}

set<Person> FillSet(queue<Person> p)
{

	set < Person> PeopleSet;
	for (int i = 0; i < Count; i++)
	{
		auto person = p.front();
		PeopleSet.insert(person);
		p.pop();
	}

	return PeopleSet;
}

void ShowSet(set < Person > People)
{
	wcout << L"Set : ";
	for (auto a : People)
	{
		a.ShowData();
		wcout << endl;
	}

}

queue<Person> FillQueue()
{
	queue<Person> People;
	Person  p;
	for (int i = 0; i < Count; i++)
	{
		p.SetData();
		People.push(p);
	}

	return People;
}

int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stderr), _O_U16TEXT);
	queue<Person> queuePeople = FillQueue();
	int i = clock();
	auto set1 = FillUnorderedSet(queuePeople);	
	ShowUnorderedSet(set1);
	wcout << L"Time : " << clock() - i << endl;	
	i = clock();
	auto set2 = FillSet(queuePeople);
	ShowSet(set2);
	wcout << L"Time : " << clock() - i << endl;

	system("pause");

}