//
// Created by rjd67 on 2020/9/5.
//
#include <list>
#include <vector>
#include <iostream>

using namespace std;

template<class T>
void PrintContainer(const char* name, const T& t)
{
	std::cout << name << ": ";
	for (const auto& a1 : t)
	{
		std::cout << " " << a1;
	}
	std::cout << endl;
}

int main()
{
	list<int> list_int = {1, 2, 3, 4, 5};
	PrintContainer("list_int", list_int);

	vector<double> vector_double1(list_int.begin(), list_int.end());
	PrintContainer("vector_double1", vector_double1);

	vector<int> vector_int = {6, 7, 8, 9, 10};
	PrintContainer("vector_int", vector_int);

	vector<double> vector_double2(vector_int.begin(), vector_int.end());
	PrintContainer("vector_double2", vector_double2);

	return 0;
}