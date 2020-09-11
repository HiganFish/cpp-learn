//
// Created by rjd67 on 2020/9/7.
//

#include <vector>
#include <cstdio>

void Swap(int* left, int* right)
{
	int temp = *right;
	*right = *left;
	*left = temp;
}

void PrintArray(const int* begin, const int* end)
{
	const int* begin_copy = begin;
	while (begin_copy < end)
	{
		printf("%d ", *begin_copy);
		begin_copy++;
	}
	printf("\n");
}

void SelectionSort(int* begin, int* end)
{
	int* new_end = end - 1;

	while (begin < new_end)
	{
		int* max_int = begin;
		for (int* now_int = begin + 1; now_int <= new_end; ++now_int)
		{
			if (*now_int > *max_int)
			{
				max_int = now_int;
			}
		}

		Swap(max_int, new_end);
		new_end--;
	}
}

void Sort(int* begin, int* end)
{
	if (end - begin <= 1)
	{
		return;
	}
	SelectionSort(begin, end);
}

void SortAndPrintVector(std::vector<int>* vec)
{
	Sort(&*vec->begin(), &*vec->end());

	PrintArray(&*vec->begin(), &*vec->end());
	printf("\n");
}

int main()
{
	std::vector<int> vec1 = {1, 3, 5, 2, 4, 7, 6, 9, 8};
	std::vector<int> vec2 = {1, 3, 5, 2, 4, 7, 6, 9};
	std::vector<int> vec3 = {1};
	std::vector<int> vec4 = {};

	SortAndPrintVector(&vec1);
	SortAndPrintVector(&vec2);
	SortAndPrintVector(&vec3);
	SortAndPrintVector(&vec4);


	return 0;
}