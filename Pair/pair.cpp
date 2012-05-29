#ifndef INCLUDE_PAIR_CPP
#define INCLUDE_PAIR_CPP
#include "pair.h"
#include <stdio.h>

template<typename T1, typename T2>
Pair<T1,T2>::Pair() {
    printf("ready");
}

template<typename T1, typename T2>
Pair<T1,T2>::Pair(T1 t1, T2 t2)
    :
        first(t1),
        second(t2)
{printf("ready c2");}

template<typename T1, typename T2>
std::ostream& operator<< (std::ostream& out, const Pair<T1,T2> &pair){
    out << "Pair<" << pair.first() << "," << pair.second() << ">";
    return out;
}

T1& Pair::first(){
    return this->first;
}

T2& Pair::second(){
    return this->second;
}

#endif //PAIR_CPP
