#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

void doOpcode(std::vector<int> &vector, int &start, int end);

void solveAll(std::vector<int> &vector);

std::vector<int> getIntCode(int opcode);

int getIndex(std::vector<int> &vector, int opcode, int index);

int main() {
    const std::vector<int> integers = {3,225,1,225,6,6,1100,1,238,225,104,0,1101,65,73,225,1101,37,7,225,1101,42,58,225,1102,62,44,224,101,-2728,224,224,4,224,102,8,223,223,101,6,224,224,1,223,224,223,1,69,126,224,101,-92,224,224,4,224,1002,223,8,223,101,7,224,224,1,223,224,223,1102,41,84,225,1001,22,92,224,101,-150,224,224,4,224,102,8,223,223,101,3,224,224,1,224,223,223,1101,80,65,225,1101,32,13,224,101,-45,224,224,4,224,102,8,223,223,101,1,224,224,1,224,223,223,1101,21,18,225,1102,5,51,225,2,17,14,224,1001,224,-2701,224,4,224,1002,223,8,223,101,4,224,224,1,223,224,223,101,68,95,224,101,-148,224,224,4,224,1002,223,8,223,101,1,224,224,1,223,224,223,1102,12,22,225,102,58,173,224,1001,224,-696,224,4,224,1002,223,8,223,1001,224,6,224,1,223,224,223,1002,121,62,224,1001,224,-1302,224,4,224,1002,223,8,223,101,4,224,224,1,223,224,223,4,223,99,0,0,0,677,0,0,0,0,0,0,0,0,0,0,0,1105,0,99999,1105,227,247,1105,1,99999,1005,227,99999,1005,0,256,1105,1,99999,1106,227,99999,1106,0,265,1105,1,99999,1006,0,99999,1006,227,274,1105,1,99999,1105,1,280,1105,1,99999,1,225,225,225,1101,294,0,0,105,1,0,1105,1,99999,1106,0,300,1105,1,99999,1,225,225,225,1101,314,0,0,106,0,0,1105,1,99999,1008,226,677,224,102,2,223,223,1005,224,329,1001,223,1,223,7,677,226,224,102,2,223,223,1006,224,344,1001,223,1,223,1007,226,677,224,1002,223,2,223,1006,224,359,1001,223,1,223,1007,677,677,224,102,2,223,223,1005,224,374,1001,223,1,223,108,677,677,224,102,2,223,223,1006,224,389,101,1,223,223,8,226,677,224,102,2,223,223,1005,224,404,101,1,223,223,7,226,677,224,1002,223,2,223,1005,224,419,101,1,223,223,8,677,226,224,1002,223,2,223,1005,224,434,101,1,223,223,107,677,677,224,1002,223,2,223,1006,224,449,101,1,223,223,7,677,677,224,1002,223,2,223,1006,224,464,101,1,223,223,1107,226,226,224,102,2,223,223,1006,224,479,1001,223,1,223,1007,226,226,224,102,2,223,223,1006,224,494,101,1,223,223,108,226,677,224,1002,223,2,223,1006,224,509,101,1,223,223,1108,226,677,224,102,2,223,223,1006,224,524,1001,223,1,223,1008,226,226,224,1002,223,2,223,1005,224,539,101,1,223,223,107,226,226,224,102,2,223,223,1006,224,554,101,1,223,223,8,677,677,224,102,2,223,223,1005,224,569,101,1,223,223,107,226,677,224,102,2,223,223,1005,224,584,101,1,223,223,1108,226,226,224,1002,223,2,223,1005,224,599,1001,223,1,223,1008,677,677,224,1002,223,2,223,1005,224,614,101,1,223,223,1107,226,677,224,102,2,223,223,1005,224,629,101,1,223,223,1108,677,226,224,1002,223,2,223,1005,224,644,1001,223,1,223,1107,677,226,224,1002,223,2,223,1006,224,659,1001,223,1,223,108,226,226,224,102,2,223,223,1006,224,674,101,1,223,223,4,223,99,226};
    std::vector<int> intCode = integers;
    solveAll(intCode);
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

    return opArr;
}


int getIndex(std::vector<int> &vector, int opcode, int index) {
    if(opcode == 1) {
        return index;
    } else if (opcode == 0){
        return vector[index];
    }
}


void doOpcode(std::vector<int> &vector, int &start, int end) {
    int add = 1;
    int mult = 2;
    int get_in = 3;
    int show_out = 4;
    int jmp_true = 5;
    int jmp_false = 6;
    int less = 7;
    int eqls = 8;
    int halt = 99;

    if (end - start == 1) {

        if (vector[start] == halt) {
            std::cout << "gotta halt" << std::endl;
            start = vector.size() + 100;
        }


        if (vector[start] == get_in) {
            int id;
            std::cout << "give id: " << std::endl;
            std::cin >> id;
            vector[vector[start + 1]] = id;
        } else if (vector[start] == show_out) {
            std::cout << "[output] out=" << vector[vector[start + 1]] << std::endl;
        }
    } else {
        std::vector<int> opCode = getIntCode(vector[start]);
        int opcode = opCode[3];
        int index1 = getIndex(vector, opCode[2], start + 1);
        int index2 = getIndex(vector, opCode[1], start + 2);
        int index3 = getIndex(vector, opCode[0], start + 3);

        if (opcode == halt) {
            std::cout << "gotta halt" << std::endl;
            start = vector.size() + 100;
        }

        if(opcode == add) {
            vector[index3] = vector[index1] + vector[index2];
        } else if (opcode == mult) {

            vector[index3] = vector[index1] * vector[index2];

        } else if (opcode == jmp_true) {

            if (vector[index1] != 0) {
                start = vector[index2] - 4;
            } else {
                start -= 1; // we're advancing by 4, but jmp_true takes 2 arguments and 1 opcode so advance by 3
            }


        } else if (opcode == jmp_false) {
            if (vector[index1] == 0) {
                start = vector[index2] - 4;
            } else {
                start -= 1;
            }
        } else if (opcode == less) {
            if (vector[index1] < vector[index2]) {
                vector[index3] = 1;
            } else {
                vector[index3] = 0;
            }

        } else if (opcode == eqls) {
            if (vector[index1] == vector[index2]) {
                vector[index3] = 1;
            } else {
                vector[index3] = 0;
            }

        }

    }

}


void solveAll(std::vector<int> &vector) {
    int i = 0;
    while(i < vector.size()) {
        if (vector[i] == 3 || vector[i] == 4) {
            doOpcode(vector, i, i + 1);
            i += 2;
        } else {
            doOpcode(vector, i, i + 3);
            i += 4;

        }
    }
}
