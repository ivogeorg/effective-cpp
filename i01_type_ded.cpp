//
// Created by Ivo Georgiev on 6/15/16.
//

#include <cstddef>
#include <array>
#include <iostream>
#include <iomanip>
#include "Item.h"

// The deduced type includes the array size!!!
// Notice the reference type T (&)[N], which prevents
// the array from decaying into a pointer.
template<typename T, std::size_t N>                 // see info
constexpr std::size_t arraySize(T (&)[N]) noexcept  // below on
{                                                   // constexpr
    return N;                                         // and
}

int I01::operator()() {
    std::cout << "--- IO1 ---" << std::endl << std::endl;

    std::cout << "Type deduction for arrays" << std::endl << std::endl;

    int keyVals[] = { 1, 3, 7, 9, 11, 22, 35 };

    std::array<int, arraySize(keyVals)> mappedVals; // type deduction here

    int i = 0;
    for (auto e: mappedVals)
        std::cout << i++ << ' ' << std::setw(20) << std::right << e << std::endl;
    std::cout << std::endl << std::endl;

    return mappedVals.size() == arraySize(keyVals);
}