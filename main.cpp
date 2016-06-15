//
// Created by Ivo Georgiev on 6/15/16.
//

#include <iostream>
#include <vector>
#include "Item.h"

int sandbox() {
    std::vector<Item*> items;

    items.push_back(new I01());

    int ret = 0;
    for (auto i: items)
        ret += (*i)();
}

int main() {

    return sandbox();

}