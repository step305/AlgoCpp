//
// Created by sanch on 07.11.2022.
//

#include "utils.h"

namespace utils {
    void delay(long long ms) {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }
}
