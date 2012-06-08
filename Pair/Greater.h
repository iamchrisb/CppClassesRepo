#ifndef GREATER_H
#define GREATER_H

template<class T>
class Greater
{
public:

    bool operator()(const T &t1 ,const T &t2){
        return t2 < t1;
    }

};

#endif // GREATER_H
