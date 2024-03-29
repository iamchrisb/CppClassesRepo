#ifndef PAIR_H
#define PAIR_H

#include <iostream>
#include "stdio.h"

namespace mystl{
template<typename T1, typename T2>
class Pair {

private:
    T1 m_first;
    T2 m_second;

public:

    Pair(T1 t1=T1(), T2 t2=T2())
        :
            m_first(t1),
            m_second(t2)
    {}

    //Copy Constructor
    Pair(const Pair<T1,T2>& p){
        m_first = p.first();
        m_second = p.second();
    }

    T1& first() { return m_first; }
    T2& second(){ return m_second; }

    const T1& first() const { return m_first; }
    const T2& second() const { return m_second; }

    Pair<T1,T2>& operator =(Pair<T1,T2>& p){
//        return Pair(p);
        m_first = p.first();
        m_second = p.second();
        return *this;
    }
    Pair<T1,T2>& operator =(T2& t){
    //        return Pair(p);
        printf(" pair=t2 ");
        m_second = t;
        return *this;
    }


};

template<typename T1, typename T2>
std::ostream& operator<< (std::ostream& out, const Pair<T1,T2> &pair){
    out << "Pair<" << pair.first() << "," << pair.second() << ">";
    return out;
}
//template<typename T1, typename T2>
//Pair<T1,T2>& operator =(T2& t){
////        return Pair(p);
//    m_second = t;
//    return *this;
//}
}

#endif // PAIR_H
