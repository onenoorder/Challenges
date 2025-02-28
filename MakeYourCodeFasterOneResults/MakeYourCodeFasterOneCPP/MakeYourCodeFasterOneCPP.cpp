#include <iostream>
#include <chrono>
#include "Challenge.h"

using std::chrono::high_resolution_clock;

int main()
{
    std::cout << "MakeYourCodeFaster Challenge one!\n\n";

    Challenge challenge = Challenge();

    auto start = high_resolution_clock::now();

    auto result = challenge.Run(25);

    auto finish = high_resolution_clock::now();

    std::cout << (result == 204022L ? "Great Success!" : "Not quite there yet, keep going!") << "\n\n";

    auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish - start);
    std::cout << microseconds.count() << "µs\n";
    std::cout << microseconds.count() / 1000 << "ms\n";
    std::cout << microseconds.count() / 1000000 << "s\n";

    std::cout << "\n" << (microseconds.count() / 1000000 < 1 ? "Another satisfied customer!" : "The customer couldn't wait that long and walked away....") << "\n\n";


    start = high_resolution_clock::now();

    result = challenge.Run(75);

    finish = high_resolution_clock::now();

    std::cout << (result == 241651071960597L ? "Great Success!" : "Not quite there yet, keep going!") << "\n\n";

    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish - start);
    std::cout << microseconds.count() << "µs\n";
    std::cout << microseconds.count() / 1000 << "ms\n";
    std::cout << microseconds.count() / 1000000 << "s\n";

    std::cout << "\n" << (microseconds.count() / 1000000 < 1 ? "Another satisfied customer!" : "The customer couldn't wait that long and walked away....") << "\n\n";
}

