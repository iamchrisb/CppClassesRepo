#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

namespace rnum {
class RationalNumber {
    private:

    int getDigits(const double) const;
    int pow(int , int powindex) const;
    RationalNumber cancel() const;

    int m_zaehler;
    int m_nenner;

    RationalNumber checkNeg() const;
    RationalNumber fromDouble(const double) const;
    double toDouble(RationalNumber) const;

    RationalNumber add(const RationalNumber &n) const;
    bool lessThan(const RationalNumber &e) const;
    RationalNumber sub(const RationalNumber &e) const;
    RationalNumber mul(const RationalNumber &e) const;
    RationalNumber div(const RationalNumber &e) const;

    public:

    RationalNumber(int i);
    RationalNumber(double d);
    RationalNumber(int zaehler=0, int nenner=1): m_zaehler(zaehler), m_nenner(nenner){}
    ~RationalNumber(){}

    bool isValid() const;
    bool isNaN() const;
    bool equal(const RationalNumber &n) const;


    /** operator overloading**/

    /** arithmetic **/

    RationalNumber operator+(const RationalNumber& other) const ;
    RationalNumber operator+(const int other) const;
    RationalNumber operator+(const double other) const;

    RationalNumber operator -() const;
    RationalNumber operator-(const RationalNumber& other) const;
    RationalNumber operator-(const int other) const;
    RationalNumber operator-(const double other) const;

    RationalNumber operator*(const RationalNumber& other) const;
    RationalNumber operator*(const int other) const;
    RationalNumber operator*(const double other) const;

    RationalNumber operator/(const RationalNumber& other) const;
    RationalNumber operator/(const int other) const;
    RationalNumber operator/(const double other) const;

    /** compare **/

    bool operator==(const RationalNumber& other) const;
    bool operator==(const int other) const;
    bool operator==(const double other) const;

    bool operator<=(const RationalNumber& other) const;
    bool operator<=(const int other) const;
    bool operator<=(const double other) const;

    bool operator>=(const RationalNumber& other) const;
    bool operator>=(const int other) const;
    bool operator>=(const double other) const;

    bool operator<(const RationalNumber& other) const;
    bool operator<(const int other) const;
    bool operator<(const double other) const;

    RationalNumber operator=( int other) ;
    RationalNumber operator=( double other) ;

    RationalNumber operator+=(const RationalNumber other) const;
    RationalNumber operator+=(const int other) const;
    RationalNumber operator+=(const double other) const;

    RationalNumber operator-=(const RationalNumber other) const;
    RationalNumber operator-=(const int other) const;
    RationalNumber operator-=(const double other) const;

    RationalNumber operator*=(const RationalNumber other) const;
    RationalNumber operator*=(const int other) const;
    RationalNumber operator*=(const double other) const;

    RationalNumber operator/=(const RationalNumber other) const;
    RationalNumber operator/=(const int other) const;
    RationalNumber operator/=(const double other) const;

    void printRN();

    int zaehler() { return m_zaehler; }
    int zaehler() const { return m_zaehler;}
    int nenner() { return m_nenner; }
    int nenner() const { return m_nenner;}

    void zaehler(int bzaehler) { m_zaehler=bzaehler; }
    void nenner(int bnenner) { m_nenner=bnenner;}

};
}


#endif // RATIONALNUMBER_H
