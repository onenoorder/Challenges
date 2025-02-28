#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <numeric>

struct MapKey {
    std::string PartOne;
    int PartTwo;
};

class Challenge {
private:
    std::string _input = "0 37551 469 63 1 791606 2065 9983586";

    long long Cycle(std::string stone, int times, std::map<MapKey, long long>& cache);
    bool StoneHasEvenDigits(const std::string& stone);
    std::pair<std::string, std::string> SplitStone(const std::string& stone);
    std::string MultiplyStoneBy2024(const std::string& stone);

public:
    long long Run(int cycles);

};
