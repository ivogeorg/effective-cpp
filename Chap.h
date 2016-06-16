//
// Created by Ivo Georgiev on 6/15/16.
//

#ifndef EFFECTIVE_CPP_ITEM_H
#define EFFECTIVE_CPP_ITEM_H

class Chap {
public:
    virtual int operator()() = 0;
};

class Ch1 : public Chap {
public:
    int operator()() override final;
};

class Ch2 : public Chap {
public:
    int operator()() override final;
};

class Ch3 : public Chap {
public:
    int operator()() override final;
};

#endif //EFFECTIVE_CPP_ITEM_H
