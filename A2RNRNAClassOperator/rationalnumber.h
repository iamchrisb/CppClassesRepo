#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

namespace rnum {
class RationalNumber {
    private:

    int getDigits(double);
    int pow(int , int powindex);

    int m_zaehler;
    int m_nenner;

    RationalNumber checkNeg();
    int ggT(int , int );
    int kgV(int , int );

    public:

    RationalNumber(int zaehler=0, int nenner=1): m_zaehler(zaehler), m_nenner(nenner){}
    ~RationalNumber(){}

    bool isValid();
    bool isNaN();
    bool equal(RationalNumber &n);

    RationalNumber add(RationalNumber &n);
    bool lessThan(RationalNumber &e);
    RationalNumber sub(RationalNumber &e);
    RationalNumber mul(RationalNumber &e);
    RationalNumber div(RationalNumber &e);

    /** operator overloading**/

    /* const fehlen */

    RationalNumber operator+( RationalNumber& other) ;
    RationalNumber operator+( int other);
    RationalNumber operator+( double other);

    RationalNumber operator-( RationalNumber& other);
    RationalNumber operator-( int other);

    RationalNumber operator*( RationalNumber& other);
    RationalNumber operator*( int other);

    RationalNumber operator/( RationalNumber& other);
    RationalNumber operator/( int other);

    RationalNumber operator==( RationalNumber& other);
    RationalNumber operator==( int other);

    void printRN();
    int zaehler() const { return m_zaehler;}
    int nenner() const { return m_nenner;}

    void zaehler(int bzaehler) { m_zaehler=bzaehler; }
    void nenner(int bnenner) { m_nenner=bnenner;}

};
}


#endif // RATIONALNUMBER_H
