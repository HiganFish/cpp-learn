#include <string>

int main()
{
    std::string s = "word";

    std::string p1 = s + (s[s.size() - 1] == 'S' ? "" : "s");

    return 0;
}
