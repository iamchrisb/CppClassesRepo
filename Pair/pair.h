#ifndef PAIR_H
#define PAIR_H

template<typename T1, typename T2>
class Pair {

private:
    T1 first;
    T2 second;

public:
    Pair();
    Pair(T1 t1, T2 t2);

    T1& first();
    //const T1& first() const { return first; }
    //T1& first() { return first; }

    //const T2& second() const { return second; }
    //T2& second() { return second; }
};

#include "pair.cpp"

#endif // PAIR_H
