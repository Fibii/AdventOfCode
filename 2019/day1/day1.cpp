#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>

std::vector<int> readFile(std::string title);

int fuelNeeded(int);

void solution();

int main() {
    solution();
}

std::vector<int> readFile(std::string title) {
    std::ifstream is(title);
    std::vector<int> masses;

    if (!is.is_open()) {
        std::cout << "file error" << std::endl;
    }

    int mass;
    while (is >> mass) {
        masses.push_back(mass);
    }
    return masses;
}

int fuelNeeded(int mass) {
    return mass / 3 - 2;
}

void solution() {
    int sum = 0;
    std::vector<int> masses = readFile("day1.txt");
    std::vector<int> fuels;

    for (const auto mass : masses) {
        sum += fuelNeeded(mass);
        fuels.push_back(mass);
    }

    std::cout << "sum1=" << sum << std::endl;
    std::cout << fuels.size() << std::endl;

    std::vector<int> fuelOfFuel;
    for (const auto fuel : fuels) {
        int f = fuelNeeded(fuel);
        while (f > 0) {
            fuelOfFuel.push_back(f);
            f = fuelNeeded(f);
        }
    }

    int sum2 = 0;
    for (const auto fuel : fuelOfFuel) {
        sum2 += fuel;
    }
    std::cout << fuelOfFuel.size() << std::endl;

    std::cout << "sum2=" << sum2 << std::endl;
}
