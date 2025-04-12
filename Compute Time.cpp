#include <bits/stdc++.h>
using namespace std;


const int ITERATIONS = 1000000;

// Timing function
clock_t measure_time(function<int()> func)
{
    clock_t start = clock();
    for (int i = 0; i < ITERATIONS; i++)
    {
        func();
    }
    return clock() - start;
}

int main()
{
    int a = 48, b = 18;

    // __gcd timing
    auto __gcd_time = measure_time([&]()
                                   { return __gcd(a, b); });

    // std::gcd timing
    auto std_gcd_time = measure_time([&]()
                                     { return std::gcd(a, b); });

    cout << "__gcd time: " << __gcd_time << " ms\n";
    cout << "std::gcd time: " << std_gcd_time << " ms\n";

    return 0;
}