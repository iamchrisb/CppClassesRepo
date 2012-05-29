#ifndef PAIR_H
#define PAIR_H

#include <iostream>

template<typename T1, typename T2>
class Pair {

private:
    T1 m_first;
    T2 m_second;

public:

    Pair(T1 t1=T1(), T2 t2=T2())
        //:
            //m_first(t1),
            //m_second(t2)
    { m_first = t1 ; m_second = t2 ;}

    T1& first() { return m_first; }
    T2& second(){ return m_second; }

    const T1& first() const { return m_first; }
    const T2& second() const { return m_second; }
};

template<typename T1, typename T2>
std::ostream& operator<< (std::ostream& out, const Pair<T1,T2> &pair){
    out << "Pair<" << pair.first() << "," << pair.second() << ">";
    return out;
}

#endif // PAIR_H
