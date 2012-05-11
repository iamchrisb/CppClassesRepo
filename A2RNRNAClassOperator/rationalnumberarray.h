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

    RationalNumberArray(){}
    ~RationalNumberArray();
    RationalNumberArray(int capacity);
    RationalNumberArray(const RationalNumberArray& r );
    void resize(unsigned int i);

/*
RationalNumberArray* rnaCreate(int capacity);
void rnaDelete(RationalNumberArray* rna);
void rnaResize(RationalNumberArray* rna, int capacity);
int rnaSize(RationalNumberArray* rna);
int rnaCapacity(RationalNumberArray* rna);
void rnaAdd(RationalNumberArray* rna, RationalNumber* rn);
void rnaSet(RationalNumberArray* rna, RationalNumber* rn, int position);
RationalNumber* rnaGet(RationalNumberArray* rna, int position);
void rnaRemove(RationalNumberArray* rna, int fromPosition, int tillPosition);

errorTypes* rnaError(RationalNumberArray *rna);
void rnaErrorCallback(RationalNumberArray* rna, void (*rnaCallbackFunction)(RationalNumberArray*));
*/
};
}
#endif // RATIONALNUMBERARRAY_H
