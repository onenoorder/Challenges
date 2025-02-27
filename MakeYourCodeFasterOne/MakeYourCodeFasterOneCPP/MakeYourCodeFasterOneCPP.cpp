#include <iostream>
#include <chrono>
#include "Challenge.h"

using std::chrono::high_resolution_clock;

int main()
{
    std::cout << "MakeYourCodeFaster Challenge one!\n\n";

    Challenge challenge = Challenge();

    auto start = high_resolution_clock::now();

    long result = challenge.Run(25);

    auto finish = high_resolution_clock::now();

    std::cout << (result == 204022L ? "Yeah" : "Not yet") << "\n\n";

    auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish - start);
    std::cout << microseconds.count() << "µs\n";
    std::cout << microseconds.count() / 1000 << "ms\n";
    std::cout << microseconds.count() / 1000000 << "s\n";

    std::cout << "\n" << (microseconds.count() / 1000000 > 1 ? "Too slow!" : "Speed!") << "\n\n";
}

