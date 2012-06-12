#ifndef MAPTOFIRST_H
#define MAPTOFIRST_H
#include "less.h"

namespace mystl {
template<typename T1, typename T2 , template<typename T1> class Order = Less >
class MapToFirst
{

    Order<T1> m_order;

public:

    bool operator()(Pair<T1,T2> p, Pair<T1,T2> p1){
        return m_order(p.first(),p1.first());
    }

};
}
#endif // MAPTOFIRST_H
