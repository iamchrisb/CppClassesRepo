#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

//namespace rnum {
class RationalNumber {
    private:

    int getDigits(double);
    int pow(int , int powindex);
    RationalNumber cancel() const;

    int m_zaehler;
    int m_nenner;

    RationalNumber checkNeg() const;

    public:

    RationalNumber(int zaehler=0, int nenner=1): m_zaehler(zaehler), m_nenner(nenner){}
    ~RationalNumber(){}

    bool isValid() const;
    bool isNaN() const;
    bool equal(const RationalNumber &n) const;

    RationalNumber add(const RationalNumber &n) const;
    bool lessThan(RationalNumber &e);
    RationalNumber sub(const RationalNumber &e) const;
    RationalNumber mul(const RationalNumber &e) const;
    RationalNumber div(const RationalNumber &e) const;

    /** operator overloading**/

    /* const fehlen */

    RationalNumber operator+(const RationalNumber& other) const ;
    RationalNumber operator+(const int other) const;
    RationalNumber operator+( double other) ;

    RationalNumber operator-(const RationalNumber& other) const;
    RationalNumber operator-(const int other) const;

    RationalNumber operator*(const RationalNumber& other) const;
    RationalNumber operator*(const int other) const;

    RationalNumber operator/(const RationalNumber& other) const;
    RationalNumber operator/(const int other) const;

    bool operator==(const RationalNumber& other) const;
    bool operator==(const int other) const;

    void printRN();

    int zaehler() { return m_zaehler; }
    int zaehler() const { return m_zaehler;}
    int nenner() { return m_nenner; }
    int nenner() const { return m_nenner;}

    void zaehler(int bzaehler) { m_zaehler=bzaehler; }
    void nenner(int bnenner) { m_nenner=bnenner;}

};
//}


#endif // RATIONALNUMBER_H
