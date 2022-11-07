#include "utils/Printer.h"
#include "Utils/utils.h"
#include <fstream>

// can be:
// std::ofstream os("output1.txt");
// utils::Printer printer(os);
utils::Printer printer;

int main() {
    printer << "Hello, World!";
    utils::delay(10);
    return 0;
}
