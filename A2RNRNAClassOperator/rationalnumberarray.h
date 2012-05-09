#ifndef RATIONALNUMBERARRAY_H
#define RATIONALNUMBERARRAY_H
#include "rationalnumber.h"
//Enum fuer die Fehler
enum errorTypes{
    OutOfMemory, NotARNA, OutOfBounds, NoRN, NoError
};

struct RationalNumberArray;

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

#endif // RATIONALNUMBERARRAY_H
