#ifndef RATIONALNUMBERARRAY_H
#define RATIONALNUMBERARRAY_H
#include "rationalnumber.h"


//Enum fuer die Fehler
enum errorTypes{
    OutOfMemory, NotARNA, OutOfBounds, NoRN, NoError
};
namespace rnum {
class RationalNumberArray {
private:

    RationalNumber *m_data;
    int m_size;
    int m_capacity;

    //FehlerTypen siehe enum errorTypes im Header
    errorTypes m_error;

    //Pointer auf Callback Funktion
    void (*rnaCallbackFunction)(RationalNumberArray*);

public:
    // Default Constructor
    RationalNumberArray(int capacity);
    //Copy Constructor
    RationalNumberArray(const RationalNumberArray& r );
    //Deconstructor
    ~RationalNumberArray();

    void resize(unsigned int i);
    int const getCapacity();
    int const getSize();
    void append(RationalNumber& rn);
    void set(RationalNumber& rn, int position);


/*
RationalNumber* rnaGet(RationalNumberArray* rna, int position);
void rnaRemove(RationalNumberArray* rna, int fromPosition, int tillPosition);

errorTypes* rnaError(RationalNumberArray *rna);
void rnaErrorCallback(RationalNumberArray* rna, void (*rnaCallbackFunction)(RationalNumberArray*));
*/
};
}
#endif // RATIONALNUMBERARRAY_H
