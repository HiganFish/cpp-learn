#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

std::vector<std::string> result;
std::vector<char> input_vector;

void Sequence(std::string* str, size_t length)
{
    if (length == 0)
    {
        result.push_back(*str);
        return;
    }

    size_t result_size = input_vector.size();

    char backup = 0;
    for (size_t i = 0; i < result_size; ++i)
    {
        if (input_vector[i] == 0)
        {
            continue;
        }
        backup = input_vector[i];
        *str += input_vector[i];
        input_vector[i] = 0;

        Sequence(str, length - 1);

        str->erase(str->end() - 1);
        input_vector[i] = backup;
    }
}

int main()
{
    char input;

    while (std::cin >> input)
    {
        if (input == ',')
        {
            break;
        }
        input_vector.push_back(input);
    }

    sort(input_vector.begin(), input_vector.end());

    std::string cache;
    Sequence(&cache, input_vector.size());

    if (result.empty())
    {
        return 0;
    }

    for (int i = 0; i < result.size() - 1; ++i)
    {
        std::cout << result[i] << " ";
    }
    std::cout << result[result.size() - 1] << std::endl;

    return 0;
}
