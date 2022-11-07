//
// Created by sanch on 04.11.2022.
//

#ifndef ALGOCPP_PRINTER_H
#define ALGOCPP_PRINTER_H

#include <thread>
#include "FIFO.h"
#include <iostream>
#include <utility>
#include <functional>

namespace utils {
    class Printer {
    public:
        explicit Printer(std::ostream &stream = std::cout);
        virtual ~Printer();
        bool operator << (const std::string &str);

    private:
        void run_loop();
        utils::FIFO<std::string> queue_;
        std::thread thread_;
        bool stop_;
        std::ostream &stream_;
    };

    Printer::Printer(std::ostream &stream) : queue_(true, 100), stream_(stream){
        stop_ = false;
        thread_ = std::thread([this] { run_loop(); });
    }

    void Printer::run_loop() {
        std::string text;
        while(!stop_){
            queue_.pop(text);
            stream_ << text << std::endl;
        }
    }

    bool Printer::operator << (const std::string &str) {
        return this->queue_.push(str);
}

    Printer::~Printer() {
        stop_ = true;
        *this << "";
        if (thread_.joinable()){
            thread_.join();
        }
    }

} // utils

#endif //ALGOCPP_PRINTER_H
