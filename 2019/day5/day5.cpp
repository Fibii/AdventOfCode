#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>

class Interpreter {


    std::vector<int> memory;
    int pointer = 0;


    int getIndex(int index, int mode) {
        if(mode == 1) {
            return index;
        } else {
            return memory[index];
        }
    }

    std::vector<int> getIntCode(int opcode) {

        std::vector<int> opArr(4);

        int op = opcode;
        int j = 3;
        opArr[j] = opcode % 100;
        j--;
        op /= 100;
        while (op > 0) {
            opArr[j--] = op % 10;
            op /= 10;
        }

        while(j > 0) {
            opArr[j--] = 0;
        }

        std::reverse(opArr.begin(), opArr.end());

        return opArr;
    }


public:

    Interpreter() {
        std::cout << "hallo" << std::endl;
    }

    void set(int position, int value) {
        memory[position] = value;
    }

    /**
     * adds param1 + param2 and stores them in memory[position]
     * */
    void add(int param1, int param2, int position, std::vector<int> mode){
        set(getIndex(position, mode[3]), memory[getIndex(param1, mode[1])] + memory[getIndex(param2, mode[2])]);
        pointer += 4;
    }

    /**
     * multiplied param1 and param2 and stores them in memory[position]
     * */
    void mult(int param1, int param2, int position, std::vector<int> mode){
        set(getIndex(position, mode[3]), memory[getIndex(param1, mode[1])] * memory[getIndex(param2, mode[2])]);
        pointer += 4;
    }

    /**
     * reads input from the user and stores it in memory[memory[input]]
     * */
    void in(int position){
        int id;
        std::cout << "enter id: " << std::endl;
        std::cin >> id;
        set(memory[position], id);
        pointer += 2;
    }

    /**
     * prints memory[position]
     * */
    void out(int position){
        std::cout << "output=" << memory[memory[position]] << std::endl;
        pointer += 2;
    }

    /**
     * if the first parameter is non-zero, it sets the instruction pointer to the value
     * from the second parameter.
     * Otherwise, it does nothing
     * */
    void jmp_true(int param1, int param2, std::vector<int> mode){
        if (memory[getIndex(param1, mode[1])] != 0) {
            pointer = memory[getIndex(param2, mode[2])];
        } else {
            pointer += 3;
        }
    }

    /**
     * if the first parameter is zero, it sets the instruction pointer
     * to the value from the second parameter.
     * Otherwise, it does nothing
     * */
    void jmp_false(int param1, int param2, std::vector<int> mode){
        if (memory[getIndex(param1, mode[1])] == 0) {
            pointer = memory[getIndex(param2, mode[2])];
        } else {
            pointer += 3;
        }
    }

    /**
     * if the first parameter is less than the second parameter,
     * it stores 1 in the position given by the third parameter.
     * Otherwise, it stores 0.
     * */
    void comp(int param1, int param2, int param3, std::vector<int> mode){
        pointer += 4;
        if (memory[getIndex(param1, mode[1])] < memory[getIndex(param2, mode[2])]) {
            set(getIndex(param3, mode[3]), 1);
        } else {
            set(getIndex(param3, mode[3]), 0);
        }
    }

    /**
     * if the first parameter is equal to the second parameter,
     * it stores 1 in the position given by the third parameter.
     * Otherwise, it stores 0
     * */
    void eqls(int param1, int param2, int param3, std::vector<int> mode){
        pointer += 4;
        if (memory[getIndex(param1, mode[1])] == memory[getIndex(param2, mode[2])]) {
            set(getIndex(param3, mode[3]), 1);
        } else {
            set(getIndex(param3, mode[3]), 0);
        }
    }

    /**
     * stops the loop
     * */
    void halt() {
        std::cout << "halting" << std::endl;
        pointer = memory.size();
    }


    void start(std::vector<int> intCodes) {
        memory = intCodes;
        while (pointer < memory.size()) {
            std::vector<int> intCode = getIntCode(memory[pointer]);
            int opCode = intCode.at(0);
            int param1 = pointer + 1;
            int param2 = pointer + 2;
            int param3 = pointer + 3;

            switch(opCode) {
                case 1:
                    add(param1, param2, param3, intCode);
                    break;
                case 2:
                    mult(param1, param2, param3, intCode);
                    break;
                case 3:
                    in(param1);
                    break;
                case 4:
                    out(param1);
                    break;
                case 5:
                    jmp_true(param1, param2, intCode);
                    break;
                case 6:
                    jmp_false(param1, param2, intCode);
                    break;
                case 7:
                    comp(param1, param2, param3, intCode);
                    break;
                case 8:
                    eqls(param1, param2, param3, intCode);
                    break;
                case 99:
                    halt();
                    break;
                default:
                    throw std::invalid_argument("invalid opcode");
            }
        }
    }

};

std::vector<int> getInput(std::string title){
    std::vector<int> integers;
    std::ifstream is(title);
    std::string line;
    while(is.good()) {
        getline(is, line, ',');
        integers.push_back(std::stoi(line));
    }
    return integers;
}

int main() {
    const std::vector<int> integers = getInput("day5.txt");
    Interpreter interpreter{};
    interpreter.start(integers);
}