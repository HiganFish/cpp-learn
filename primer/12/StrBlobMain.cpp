//
// Created by rjd67 on 2020/6/18.
//

#include "StrBlob.h"


int main()
{
	StrBlob b1;
	{
		StrBlob b2 = {"a", "an", "the"};

		b1 = b2;

		b2.PushBack("about");
	}

	printf("size-%ld\n", b1.Size());

	size_t temp = -1;
	if (temp > 0)
	{
		printf("big\n");
	}
	else
	{
		printf("small\n");
	}
}