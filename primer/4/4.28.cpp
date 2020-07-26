#include <string>
#include <vector>
#include <cstdio>

int main()
{
    printf("char %ld\n", sizeof(char));
    printf("short %ld\n", sizeof(short));
    printf("int %ld\n", sizeof(int));
    printf("long %ld\n", sizeof(long));
    printf("long long %ld\n", sizeof(long long));
    printf("float %ld\n", sizeof(float));
    printf("double %ld\n", sizeof(double));

    printf("string %ld\n", sizeof(std::string));


    std::string str1 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
                "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
    printf("str1 %ld", sizeof(str1));

    printf("vector<int> %ld\n", sizeof(std::vector<int>));

    return 0;
}
