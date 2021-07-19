// Challange.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
//#include <numeric>
std::vector<std::uint32_t> extractOddDigits(int n)
{
    std::vector<std::uint32_t> vector;
    const std::size_t vector_size = std::to_string(n).length();
    int divide_by = 1;
    vector.reserve(vector_size);

    for (auto i = 0; i < vector_size - 1; i++)  
    {
        divide_by *= 10;
    }

    for (auto i = 0; i < vector_size; i++)
    {
        if (i == 0)
        {
            int number = n / divide_by % 10;

            if (number % 2 == 0)
                continue;

            vector.push_back(number);
            continue;
        }
  
        divide_by /= 10;
        int number = n / divide_by % 10;

        if (number % 2 == 0)
            continue;
        vector.push_back(number);
    }

    return vector;
}

std::uint32_t restoreDigits(std::vector<std::uint32_t> digits)
{
    std::uint32_t ret = 0;
    for (auto i : digits)
        ret = ret * 10 + i;  

    return ret;
}

int main()
{
    const int test_case = 6543113;
    std::vector<std::uint32_t> vector = extractOddDigits(test_case);
    std::uint32_t restored = restoreDigits(vector);
    return 0;
}

