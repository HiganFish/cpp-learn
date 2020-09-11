//
// Created by rjd67 on 2020/9/9.
//
#include <cstdio>
#include "BinarySearchST.h"

int main()
{
	BinarySearchST<int, int> st;

	for (int i = 0; i < 10; ++i)
	{
		st.Put(i, i);
	}

	printf("size = %ld\r\n", st.Size());

	for (const auto& key : st.GetKeys())
	{
		printf("%d: %d\r\n", key, *st.Get(key));
	}

	for (const auto& key : st.GetKeys())
	{
		st.Delete(key);
	}

	printf("size = %ld\r\n", st.Size());

	for (const auto& key : st.GetKeys())
	{
		printf("%d: %d\r\n", key, *st.Get(key));
	}

	for (int i = 0; i < 10; ++i)
	{
		st.Put(i, i);
	}

	printf("size = %ld\r\n", st.Size());

	for (const auto& key : st.GetKeys())
	{
		printf("%d: %d\r\n", key, *st.Get(key));
	}

	return 0;
}