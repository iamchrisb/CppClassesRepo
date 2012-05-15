#ifndef RATIONALNUMBERARRAY_H
#define RATIONALNUMBERARRAY_H
#include "rationalnumber.h"


//Enum fuer die Fehler
enum errorTypes{
    OUT_OF_MEMORY, NOT_A_RNA, OUT_OF_BOUNDS, NO_RN, NO_ERROR, NULL_POINTER
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

    bool operator==(const RationalNumberArray& rna) const ;
public:
    // Default Constructor
    RationalNumberArray(int capacity);
    //Copy Constructor
    RationalNumberArray(const RationalNumberArray& r );
    //Deconstructor
    ~RationalNumberArray();

    void resize(const unsigned int i);
    int const getCapacity() const;
    int const getSize() const;
    void append(const RationalNumber& rn);
    void set(RationalNumber& rn,unsigned int position);
    RationalNumber get(unsigned int position) ;
    void remove(unsigned int fromPosition, unsigned int tillPosition);
    errorTypes& error();
    void rnaErrorCallback(void (*rnaCallbackFunction)(RationalNumberArray*));

    RationalNumberArray& operator=(const RationalNumberArray& rna);
    const RationalNumber& operator[](int i) const ;

    void printRNA();
/*

void rnaErrorCallback(RationalNumberArray* rna, void (*rnaCallbackFunction)(RationalNumberArray*));
*/
};
}
#endif // RATIONALNUMBERARRAY_H
