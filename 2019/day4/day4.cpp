#include <iostream>
#include <map>
#include <vector>
#include <unordered_set>

bool isValid(int number);
bool isDuplicate(std::vector<int> number);
bool isDuplicate2(std::vector<int> number);
std::vector<int> getIntArray(int number);

std::vector<int> solve1(int start, int end);
bool isIncreasing(std::vector<int> number);
int solve2(int start, int end);

int main() {

    int input1 = 172930;
    int input2 = 683082;
    std::cout << "ans1= " << solve1(input1, input2).size() << std::endl;
    std::cout << "ans2= " << solve2(input1, input2) << std::endl;
}

std::vector<int> getIntArray(int number) {
    std::vector<int> num(6);
    int n = number;
    int i = 5;
    while(n != 0) {
        num[i--] = n % 10;
        n /= 10;
    }
    return num;
}

bool isDuplicate(std::vector<int> number) {
    std::map<int, int> mp;
    for(int i = 0; i < 6; i++) {
        if (mp.find(number[i]) == mp.cend()) {
            mp.insert(std::make_pair(number[i], 1));
        } else {
            return true;
        }
    }
    return false;

}

bool isIncreasing(std::vector<int> number) {
    for (int i = 0; i < 5; i++) {
        if (number[i] > number[i + 1]) {
            return false;
        }
    }    return true;
}

bool isValid(int number) {
    std::vector<int> num = getIntArray(number);
    if(!isDuplicate(num)) {
        return false;
    }

    if(!isIncreasing(num)) {
        return false;
    }

    return true;
}

std::vector<int> solve1(int start, int end) {
    std::vector<int> passwords;

    for(int i = start; i <= end; i++) {
        if(isValid(i)) {
            passwords.push_back(i);
        }
    }

    return passwords;
}

bool isDuplicate2(std::vector<int> number) {

    std::map<int, int> mp;
    for(int i = 0; i < 6; i++) {
        if (mp.find(number[i]) == mp.cend()) {
            mp.insert(std::make_pair(number[i], 1));
        } else {
            mp[number[i]] = mp[number[i]] + 1;
        }
    }

    for(const auto k : mp) {
        if(k.second == 2) {
            return true;
        }
    }
    return false;

}

int solve2(int start, int end) {
    int count = 0;
    std::vector<int> passwords = solve1(start, end);
    for (int i : passwords) {
        if(isDuplicate2(getIntArray(i))){
            count++;
        }
    }
    return count;
}
