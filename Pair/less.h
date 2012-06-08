#ifndef LESS_H
#define LESS_H

#include <stdio.h>

template<class T>
class Less
{
public:

    bool operator()(const T &t1, const T &t2){
        return t1 < t2 ;
    }

};

#endif // LESS_H
