#include "Challenge.h"

bool operator<(const MapKey& l, const MapKey& r) {
    return (l.PartTwo < r.PartTwo || (l.PartOne == r.PartOne && l.PartOne < r.PartOne));
}

long long Challenge::Run(int cycles) {
    std::map<MapKey, long long> cache;
    std::vector<std::string> stones;
    std::stringstream stringStream(_input);
    std::string stone;

    while (stringStream >> stone) {
        stones.push_back(stone);
    }

    long long sum = 0;
    for (const auto& stone : stones) {
        sum += Cycle(stone, cycles, cache);
    }

    return sum;
}

long long Challenge::Cycle(std::string stone, int times, std::map<MapKey, long long>& cache) {
    if (times == 0) {
        return 1;
    }

    MapKey key = { stone, times };
    times--;
    long long result;
    if (cache.find(key) != cache.end()) {
        result = cache[key];
    }
    else if (stone == "0") {
        cache[key] = Cycle("1", times, cache);
        result = cache[key];
    }
    else if (StoneHasEvenDigits(stone)) {
        auto splitPair = SplitStone(stone);
        cache[key] = Cycle(splitPair.first, times, cache) + Cycle(splitPair.second, times, cache);
        result = cache[key];
    }
    else {
        cache[key] = Cycle(MultiplyStoneBy2024(stone), times, cache);
        result = cache[key];
    }

    return result;
}

bool Challenge::StoneHasEvenDigits(const std::string& stone) {
    return stone.length() % 2 == 0;
}

std::pair<std::string, std::string> Challenge::SplitStone(const std::string& stone) {
    int middle = (int)(stone.length() / 2);
    std::string leftStone = stone.substr(0, middle);
    std::string rightStone = stone.substr(middle);
    size_t firstNonZero = rightStone.find_first_not_of('0');

    if (firstNonZero != std::string::npos) {
        rightStone = rightStone.substr(firstNonZero);
    }
    else {
        rightStone = "0";
    }

    return { leftStone, rightStone };
}

std::string Challenge::MultiplyStoneBy2024(const std::string& stone) {
    long long num = std::stoll(stone);
    return std::to_string(2024LL * num);
}
