//
// Created by sanch on 05.11.2022.
//
#include "tests.h"
#include <fstream>
#include <iostream>

int main() {
    FIFO_test1();
    Printer_test1();
    return 0;
}

int FIFO_test1() {
    utils::FIFO<int> q(false, 10);
    q.push(9);
    int item;
    q.pop(item);
    if (item == 9) std::cout << "FIFO #1 Passed" << std::endl;
    else std::cout << "FIFO #1 Failed!" << std::endl;
    bool f = q.pop(item);
    if (item == 9 && !f) std::cout << "FIFO #2 Passed" << std::endl;
    else std::cout << "FIFO #2 Failed!" << std::endl;
    for (int i = 0; i < 11; i++) q.push(i);
    f = q.push(100);
    if (!f) std::cout << "FIFO #3 Passed" << std::endl;
    else std::cout << "FIFO #3 Failed!" << std::endl;
    for (int i = 0; i < 10; ++i) {
        f = q.pop(item);
    }
    if (item == 9 && f) std::cout << "FIFO #4 Passed" << std::endl;
    else std::cout << "FIFO #4 Failed! Expected: " << 9 << " got: " << item  << std::endl;
    return item;
}

int Printer_test1(){
    std::ofstream out("output.txt");
    utils::Printer printer(out);
    printer << "test1";
    printer << "test";
    utils::delay(10);
    std::ifstream inp("output.txt");
    std::string str, str1;
    inp >> str1;
    inp >> str;
    if ("test1test" == str1 + str) std::cout << "Printer #1 Passed!" << std::endl;
    else std::cout << "Printer #1 Failed! Expected: \"test1test\", got: " << str1 + str<< std::endl;

    return 0;
}
