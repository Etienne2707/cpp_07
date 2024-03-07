#ifndef WHATEVER_HPP
#define WHATEVER_HPP


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


template< typename T>
void    swap(T & first , T  & second)
{
    T tmp;

    tmp = first;
    first = second;
    second = tmp;
}

template< typename T>
T min(T first, T second)
{
    return (second <= first ? second : first);
}

template< typename T>
T max(T first, T second)
{
    return (second >= first ? second : first);
}


#endif