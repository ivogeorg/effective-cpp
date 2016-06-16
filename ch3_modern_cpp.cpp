//
// Created by Ivo Georgiev on 6/16/16.
//

#include <iostream>
#include <vector>
#include <boost/type_index.hpp>

#include "Chap.h"

using std::cout;
using std::endl;
using boost::typeindex::type_id_with_cvr; // don't strip const, volatile, reference

class Widget {
    int x { 7 };
//    int y ( 1 ); // can't use ()
    int y = 1;
public:
    int getX() { return x; }
    int getY() { return y; }
};

class Gadget {
public:
    Gadget(int a, double b) {}
    Gadget(int i, bool t) {}
    Gadget(std::initializer_list<bool> il) {}

    operator float() const {}
};

int Ch3::operator()() {
    std::cout << "--- Ch3 ---" << std::endl << std::endl;

    int ret{0};

    std::cout << "Item 07: Distinguish between () and {} for object initializtion" << std::endl << std::endl;

    // braced (aka universal) initialization can be used to initialize STL containers
    std::vector<int> v{ 1, 2, 3, 5, 7, 11 };

    ret += !(v.size() == 6);

    // braced initialization can be used for non-static class memeber initialization
    Widget w;
    ret += !(w.getX() == 7);
    ret += !(w.getY() == 1);

    // braced initialization can be used to initialize uncopiable, atomic, objects
    std::atomic<int> ai1{ 5 };
    std::atomic<int> ai2( 6 );
//    std::atomic<int> ai3 = 7; // deleted ctor

    ret += !(ai1 = 5);
    ret += !(ai2 = 6);

    // braced init checks for narrowing conversions
    double d, e, f;
//    int i { d + e + f };
    int i { static_cast<int>(d + e + f)}; // using cast

    // br init can be used to initilize an object with its default ctor
    Widget w2{};

    // NOTE: tangled relationship among br init, std::initializer_list, and ctor overload resolution
    auto item{ 6 }; // the type of item is std::initializer_list<int>
    auto item2 = {6}; // preferred
    cout << "item = " << type_id_with_cvr<decltype(item)>().pretty_name() << endl;
    cout << "item2 = " << type_id_with_cvr<decltype(item2)>().pretty_name() << endl;

    // STRONG preference ctor overaloads that use std::initalializer_list<> parameters
//    Gadget g{6, 6.5}; // ERROR due to preference of init_list ctor and disallowed narrowing conversion

    std::cout << "Item 08: Prefer nullptr to 0 and NULL" << std::endl << std::endl;

    std::cout << "Item 09: Prefer alias declarations to typedef" << std::endl << std::endl;

    std::cout << "Item 10: Prefer scoped enums to unscoped enums" << std::endl << std::endl;

    std::cout << "Item 11: Prefer deleted functions to private undefined ones" << std::endl << std::endl;

    std::cout << "Item 12: Declare overriding functions override" << std::endl << std::endl;

    std::cout << "Item 13: Prefer const_iterators to iterators" << std::endl << std::endl;

    return ret;
}
