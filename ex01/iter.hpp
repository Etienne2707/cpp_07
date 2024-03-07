#ifndef ITER_HPP
#define ITER_HPP


#pragma once
#include <string>
#include <iostream>
#include <stdlib.h>
const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");

template<typename A, typename L, typename F>
void iter(A *Aptr, L length, F func) {
    for (L i = 0; i < length; ++i) {
        func(Aptr[i]);
    }
}


#endif