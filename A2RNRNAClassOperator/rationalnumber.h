#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

namespace rnum {
class RationalNumber {
    private:

    int m_zaehler;
    int m_nenner;
    bool m_fromUser;

    RationalNumber checkNeg();
    int ggT(int , int );
    int kgV(int , int );

    public:
    RationalNumber(){}
    RationalNumber(int zaehler=0, int nenner=1): m_zaehler(zaehler), m_nenner(nenner){}
    ~RationalNumber(){}

    public:

    bool isValid();
    bool isNaN();
    bool equal(RationalNumber &n);

    RationalNumber add(RationalNumber &n);
    bool lessThan(RationalNumber &e);
    RationalNumber sub(RationalNumber &e);
    RationalNumber mul(RationalNumber &e);
    RationalNumber div(RationalNumber &e);

    void printRN();
    int zaehler() const { return m_zaehler;}
    int nenner() const { return m_nenner;}

};
}


#endif // RATIONALNUMBER_H
