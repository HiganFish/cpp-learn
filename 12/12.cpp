//
// Created by rjd67 on 2020/6/25.
//

#include <vector>
#include <iostream>
#include <memory>

typedef std::shared_ptr<std::vector<int>> IntVectorPtr;

std::vector<int>* GetVector()
{
	 return new std::vector<int>{1, 2, 3, 4, 5, 6, 7};
}

void PrintVector(const std::vector<int> vec)
{
	for (int temp : vec)
	{
		std::cout << temp << " ";
	}
}

void PrintVector(const IntVectorPtr& vec)
{
	for (int temp : *vec)
	{
		std::cout << temp << " ";
	}
}

IntVectorPtr GetIntVectorPtr()
{
	return std::make_shared<std::vector<int>>(
			std::initializer_list<int>{1, 2, 3, 4, 5}
			);
}

bool b()
{
	int* p = new int;

	return p;
}

int main()
{
	std::vector<int>* vec = GetVector();

	PrintVector(*vec);

	delete vec;

	PrintVector(GetIntVectorPtr());
}