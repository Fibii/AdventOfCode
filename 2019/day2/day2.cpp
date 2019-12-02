#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
//#define CATCH_CONFIG_MAIN
#include "../catch.hpp"


void doOpcode(std::vector<int> &vector, int start, int end);

void solvePart1(std::vector<int> &vector);

void solvePart2(const std::vector<int> vector);

#ifndef CATCH_CONFIG_MAIN

int main() {
    const std::vector<int> integers = {1, 0, 0, 3, 1, 1, 2, 3, 1, 3, 4, 3, 1, 5, 0, 3, 2, 1, 6, 19, 1, 9, 19, 23, 2, 23,
                                       10, 27, 1, 27, 5, 31, 1, 31, 6, 35, 1, 6, 35, 39, 2, 39, 13, 43, 1, 9, 43, 47, 2,
                                       9, 47, 51, 1, 51, 6, 55, 2, 55, 10, 59, 1, 59, 5, 63, 2, 10, 63, 67, 2, 9, 67,
                                       71, 1, 71, 5, 75, 2, 10, 75, 79, 1, 79, 6, 83, 2, 10, 83, 87, 1, 5, 87, 91, 2, 9,
                                       91, 95, 1, 95, 5, 99, 1, 99, 2, 103, 1, 103, 13, 0, 99, 2, 14, 0, 0};
    std::vector<int> intCode = integers;
    solvePart1(intCode);
    std::cout << intCode[0] << std::endl;
    solvePart2(integers);
}

#endif

void doOpcode(std::vector<int> &vector, int start, int end) {
    int halt = 99;
    int add = 1;
    int mult = 2;
    if (vector[start] == halt) {
        return;
    } else if (vector[start] == add) {
        vector[vector[end]] = vector[vector[start + 1]] + vector[vector[end - 1]];
    } else if (vector[start] == mult) {
        vector[vector[end]] = vector[vector[start + 1]] * vector[vector[end - 1]];
    }
}


void solvePart1(std::vector<int> &vector) {
    vector[1] = 12;
    vector[2] = 2;
    for (int i = 0; i < vector.size() - 3; i += 4) {
        doOpcode(vector, i, i + 3);
    }
}

void solvePart2(const std::vector<int> vector) {
    int ans = 19690720;
    for (int noun = 0; noun <= 99; noun++) {
        for (int verb = 0; verb <= 99; verb++) {
            std::vector<int> tmp = vector;
            tmp[1] = noun;
            tmp[2] = verb;

            for (int i = 0; i < vector.size(); i += 4) {
                doOpcode(tmp, i, i + 3);
                if (tmp[0] == ans) {
                    std::cout << "noun=" << noun << " verb=" << verb << std::endl;
                    std::cout << "ans=" << 100 * noun + verb << std::endl;
                    break;
                }
            }
        }
    }
}

#ifdef CATCH_CONFIG_MAIN
TEST_CASE("provided examples are correct") {

    std::vector<int> v1 = {1,0,0,0,99};
    std::vector<int> v1s = {2,0,0,0,99};

    std::vector<int> v2 = {2,3,0,3,99};
    std::vector<int> v2s = {2,3,0,6,99};

    std::vector<int> v3 = {2,4,4,5,99,0};
    std::vector<int> v3s = {2,4,4,5,99,9801};

    std::vector<int> v4 = {1,1,1,4,99,5,6,0,99};
    std::vector<int> v4s = {30,1,1,4,2,5,6,0,99};

    solvePart1(v1);
    REQUIRE(v1 == v1s);

    solvePart1(v2);
    REQUIRE(v2 == v2s);

    solvePart1(v3);
    REQUIRE(v3 == v3s);

    solvePart1(v4);
    REQUIRE(v4 == v4s);

}

#endif