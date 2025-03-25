#include <iostream>
#include <chrono>
#include "Challenge.h"

using std::chrono::high_resolution_clock;

void runChallengeWith(int cycles, long long expectedResult) {
    Challenge challenge = Challenge();

    auto start = high_resolution_clock::now();

    auto result = challenge.Run(cycles);

    auto finish = high_resolution_clock::now();

    auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish - start);

    std::cout << "Your solution was: " << result << "\n";
    std::cout << (result == expectedResult ? "Great Success!" : "Not quite there yet, keep going!") << "\n";
    std::cout << "Your solution ran in: " << microseconds.count() / 1000 << "ms\n";
    std::cout << "That is about: " << microseconds.count() / 1000000 << "s\n";
    std::cout << (microseconds.count() / 1000000 < 1 ? "Another satisfied customer!" : "The customer couldn't wait that long and walked away....") << "\n\n";
}

int main()
{
    std::cout << "MakeYourCodeFaster Challenge one!\n\n";

    runChallengeWith(25, 204022LL);
    runChallengeWith(75, 241651071960597LL);
}

