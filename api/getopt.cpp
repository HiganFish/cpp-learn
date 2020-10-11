#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	int opt = -1;
	while ((opt = getopt(argc, argv, "ab:c::")) != -1 )
	{
		switch (opt)
		{
			case 'a':
			{
				printf("%s\n", "a~~");
				// 形如 -a 的参数
				break;
			}

			case 'b':
			{
				printf("%s: %s\n", "b~~", optarg == nullptr ? "" : optarg);
				// 形如-b123或-b 123的参数 123会被打印出来 仅输入-b会报错
				break;
			}

			case 'c':
			{
				printf("%s: %s\n", "c~~", optarg == nullptr ? "" : optarg);
				// 形如-c123或-c 123的参数 123会被打印出来 仅输入-c不会报错
				break;
			}
			default :
			{
				printf("error\n");
			}
		}
	}
	return 0;
}
