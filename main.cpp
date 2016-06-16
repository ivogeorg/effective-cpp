//
// Created by Ivo Georgiev on 6/15/16.
//

#include <iostream>
#include <vector>

#include "Chap.h"

int sandbox() {
    std::vector<Chap*> items;

    items.push_back(new Ch1());
    items.push_back(new Ch2());

    int ret = 0;
    for (auto i: items)
        ret += (*i)();

    return ret;
}
int main() {

    return sandbox();

}