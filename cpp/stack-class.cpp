#include <cstdio>

class Foo
{
public:
    char data[30000000];
};

int main()
{
  Foo foo;
  printf("%p", foo.data);
  return 0;
}
