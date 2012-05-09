#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

class RationalNumber {
    private:
    int m_zaehler;
    int m_nenner;
    bool m_fromUser;

    public:
    RationalNumber(int zaehler=0, int nenner=1): m_zaehler(zaehler), m_nenner(nenner){}
    public:
    bool rnIsValid();
    bool rnIsNaN();
    bool rnEqual(RationalNumber n, RationalNumber e);
    bool rnLessThan(RationalNumber n, RationalNumber e);
    RationalNumber rnAdd(RationalNumber n, RationalNumber e);
    RationalNumber rnSubtract(RationalNumber n, RationalNumber e);
    RationalNumber rnMultiply(RationalNumber n, RationalNumber e);
    RationalNumber rnDivide(RationalNumber n, RationalNumber e);

    int zaehler() const { return m_zaehler;}
    int nenner() const { return m_nenner;}

};



#endif // RATIONALNUMBER_H
