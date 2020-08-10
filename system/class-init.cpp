#include <vector>
#include <string>

class Foo
{
public:

    int bar_int_;
    size_t bar_size_t_;

    std::string bar_string_;

    std::vector<int> bar_vector_int_;

    std::vector<std::string> bar_vector_string_;
};

int main()
{
    Foo foo;
    Foo foo1{};


    return 0;
}
