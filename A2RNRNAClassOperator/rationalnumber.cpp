#include <iostream>
#include "rationalnumber.h"
#include <stdio.h>

#include <string>
#include <sstream>

using namespace std;

/**
  * Diese Methode ueberprueft ob eine RationalNumber negativ oder positiv ist.
  * Sind Zaehler und Nenner negativ so wird n positiv gemacht
  * Ist die Negation im Nenner so wird sie zum Zaehler getauscht.
  **/
namespace rnum {

RationalNumber RationalNumber::checkNeg(){

    if(m_zaehler<0 && m_nenner<0){
        RationalNumber rn(m_zaehler*-1, m_nenner*-1);
        return rn;
    }
    if(m_zaehler>0 && m_nenner<0){
        RationalNumber rn(m_zaehler*-1, m_nenner*-1);
        return rn;
    }
    RationalNumber rn(m_zaehler,m_nenner);
    return rn;
}
/**
  * Diese Methode berechnet den groeßten gemeinsamen Teiler zweier nenner
  **/
int RationalNumber::ggT(int nenner1, int nenner2){
    if(nenner2 == 0){
        return nenner1;
    }
    return ggT(nenner2, nenner1%nenner2);
}
/**
  * Diese Methode berechnet das kleinste gemeinsame Vielfache zweier nenner
  **/
int RationalNumber::kgV(int nenner1, int nenner2){
    return (nenner1*nenner2)/ggT(nenner1, nenner2);
}
/**
  * Diese Methode ueberprueft ob eine RationalNumber valide ist. Dazu darf der Nenner nicht 0 sein.
  **/
bool RationalNumber::isValid(){
    if(nenner() == 0){
        return false;
    }
    return true;
}
/**
  * Diese Methode ueberprueft ob eine RationalNumber Not a Number also keine RationalNumber ist.
  **/
bool RationalNumber::isNaN(){
    if(isValid()){
        return false;
    }
    return true;
}

/**
  * Diese Methode ueberprueft ob zwei RationalNumbers gleich sind, also auch den gleichen Wert haben.
  **/
bool RationalNumber::equal(RationalNumber &e){
    //Ueberpruefung der Rationalnumbers e
    checkNeg();
    e.checkNeg();
    if(!isValid() || !e.isValid()){
        //cout << "false, da mind. einer der Brueche nicht dem Schemata eines Bruches entspricht" << endl;
        return false;
    }
    if(m_nenner == e.nenner()){
        return m_zaehler== e.zaehler();
    }
    int hN = kgV(m_nenner, e.nenner());
    return m_zaehler*(hN/m_nenner) == e.zaehler()*(hN / e.nenner());
}
/**
  * Diese Methode checked ob n kleiner e ist.
  **/

bool RationalNumber::lessThan(RationalNumber &e){
    checkNeg();
    e.checkNeg();
    //Ueberpruefung der Rationalnumbers e und n
    if(!isValid() || !e.isValid()){
        //cout << "false, da mind. einer der Brueche nicht dem Schemata eines Bruches entspricht" << endl;
        return false;
    }
    if(m_nenner == e.nenner()){
        return m_zaehler < e.zaehler();
    }
    int hN= kgV(m_nenner, e.nenner());
    return m_zaehler*(hN/m_nenner) < e.zaehler()*(hN/e.nenner());
}

/**
  * Diese Methode addiert zwei RationalNummers
  **/
RationalNumber RationalNumber::add(RationalNumber &n){
    //Ueberpruefung der Rationalnumbers n
    if(!isValid() || !n.isValid()){
        //cout << "0,0 , da mind. einer der Brueche nicht dem Schemata eines Bruches entspricht" << endl;
        RationalNumber rn(0,0);
        return rn;

    }
    n = n.checkNeg();
    checkNeg();

    if(n.nenner() == m_nenner){
        RationalNumber rn ( n.zaehler() + m_zaehler , n.nenner() );
        return rn;
    }
    int hN = kgV( m_nenner , n.nenner());
    RationalNumber rn (m_zaehler * (hN / m_nenner) + (n.zaehler() * (hN / n.nenner())),hN);
    return rn;
}
/**
  * Diese Methode subtrahiert zwei RationalNumbers
  **/

RationalNumber RationalNumber::sub(RationalNumber &e){
    //Ueberpruefung der Rationalnumbers e und n
    if(!isValid() || !e.isValid()){
        //cout << "0,0 , da mind. einer der Brueche nicht dem Schemata eines Bruches entspricht" << endl;
        RationalNumber rn (0,0);
        return rn;
    }
    e = e.checkNeg();
    checkNeg();
    if(m_nenner == e.nenner()){
        RationalNumber rn (m_zaehler-e.zaehler(), m_nenner);
        return rn;
    }
    int hN= kgV(m_nenner, e.nenner());
    RationalNumber rn ((m_zaehler*(hN/m_nenner)) - (e.zaehler()*(hN/e.nenner())),hN);
    return rn;
}

/**
  * Diese Methode multipliziert zwei RationalNumbers
  **/

RationalNumber RationalNumber::mul(RationalNumber &e){
    //Ueberpruefung der Rationalnumbers e und n
    if(!isValid() || !e.isValid()){
        //cout << "0,0 , da mind. einer der Brueche nicht dem Schemata eines Bruches entspricht" << endl;
        RationalNumber rn(0,0);
        return rn;
    }

    checkNeg();
    e = e.checkNeg();

    RationalNumber rn (m_zaehler*e.zaehler(),m_nenner*e.nenner());
    return rn;
}

/**
  * Diese Methode dividiert zwei RationalNumbers
  **/
RationalNumber RationalNumber::div(RationalNumber &e){
    //Ueberpruefung der Rationalnumbers e und n
    if(!isValid() || !e.isValid()){
        //0,0 , da mind. einer der Brueche nicht dem Schemata eines Bruches entspricht
        RationalNumber rn (0,0);
        return rn;
    }

    RationalNumber rn (e.nenner(),e.zaehler());
    return mul(rn);
}
void RationalNumber::printRN(){
    printf("%d / %d" , m_zaehler , m_nenner);
}

/** operator overloading **/

RationalNumber RationalNumber::operator +( RationalNumber & n){
    //Ueberpruefung der Rationalnumbers n
    if(!isValid() || !n.isValid()){
        //cout << "0,0 , da mind. einer der Brueche nicht dem Schemata eines Bruches entspricht" << endl;
        RationalNumber rn(0,0);
        return rn;

    }
    n = n.checkNeg();
    checkNeg();

    if(n.nenner() == m_nenner){
        RationalNumber rn ( n.zaehler() + m_zaehler , n.nenner() );
        return rn;
    }
    int hN = kgV( m_nenner , n.nenner());
    RationalNumber rn (m_zaehler * (hN / m_nenner) + (n.zaehler() * (hN / n.nenner())),hN);
    return rn;
}

RationalNumber RationalNumber::operator +(int i) {
    RationalNumber e(i , 1);
    //Ueberpruefung der Rationalnumbers e und n
    if(!isValid() || !e.isValid()){
        //cout << "0,0 , da mind. einer der Brueche nicht dem Schemata eines Bruches entspricht" << endl;
        RationalNumber rn (0,0);
        return rn;
    }
    e = e.checkNeg();
    checkNeg();
    if(m_nenner == e.nenner()){
        RationalNumber rn (m_zaehler-e.zaehler(), m_nenner);
        return rn;
    }
    int hN= kgV(m_nenner, e.nenner());
    RationalNumber rn ((m_zaehler*(hN/m_nenner)) - (e.zaehler()*(hN/e.nenner())),hN);
    return rn;
}

RationalNumber RationalNumber::operator+( double other){
    int dPow = getDigits(other);
    int nD = pow(10 , dPow);
    RationalNumber rn(other*nD , nD);
    rn.printRN();
    return add(rn);
}

RationalNumber RationalNumber::operator -(RationalNumber& e){
    //Ueberpruefung der Rationalnumbers e und n
    if(!isValid() || !e.isValid()){
        //cout << "0,0 , da mind. einer der Brueche nicht dem Schemata eines Bruches entspricht" << endl;
        RationalNumber rn (0,0);
        return rn;
    }
    e = e.checkNeg();
    checkNeg();
    if(m_nenner == e.nenner()){
        RationalNumber rn (m_zaehler-e.zaehler(), m_nenner);
        return rn;
    }
    int hN= kgV(m_nenner, e.nenner());
    RationalNumber rn ((m_zaehler*(hN/m_nenner)) - (e.zaehler()*(hN/e.nenner())),hN);
    return rn;
}

RationalNumber RationalNumber::operator -(const int i){

    RationalNumber e(i , 1);

    if(!isValid() || !e.isValid()){
        //cout << "0,0 , da mind. einer der Brueche nicht dem Schemata eines Bruches entspricht" << endl;
        RationalNumber rn (0,0);
        return rn;
    }
    e = e.checkNeg();
    checkNeg();
    if(m_nenner == e.nenner()){
        RationalNumber rn (m_zaehler-e.zaehler(), m_nenner);
        return rn;
    }
    int hN= kgV(m_nenner, e.nenner());
    RationalNumber rn ((m_zaehler*(hN/m_nenner)) - (e.zaehler()*(hN/e.nenner())),hN);
    return rn;
}

RationalNumber RationalNumber::operator *(RationalNumber& e){
    //Ueberpruefung der Rationalnumbers e und n
    if(!isValid() || !e.isValid()){
        //cout << "0,0 , da mind. einer der Brueche nicht dem Schemata eines Bruches entspricht" << endl;
        RationalNumber rn(0,0);
        return rn;
    }

    checkNeg();
    e = e.checkNeg();

    RationalNumber rn (m_zaehler*e.zaehler(),m_nenner*e.nenner());
    return rn;
}

RationalNumber RationalNumber::operator *(const int i){
    //Ueberpruefung der Rationalnumbers e und n

    RationalNumber e(i,1);

    if(!isValid() || !e.isValid()){
        //cout << "0,0 , da mind. einer der Brueche nicht dem Schemata eines Bruches entspricht" << endl;
        RationalNumber rn(0,0);
        return rn;
    }

    checkNeg();
    e = e.checkNeg();

    RationalNumber rn (m_zaehler*e.zaehler(),m_nenner*e.nenner());
    return rn;
}

RationalNumber RationalNumber::operator /(RationalNumber& e){
    //Ueberpruefung der Rationalnumbers e und n
    if(!isValid() || !e.isValid()){
        //0,0 , da mind. einer der Brueche nicht dem Schemata eines Bruches entspricht
        RationalNumber rn (0,0);
        return rn;
    }

    RationalNumber rn (e.nenner(),e.zaehler());
    return mul(rn);
}

RationalNumber RationalNumber::operator /(const int i){
    //Ueberpruefung der Rationalnumbers e und n

    RationalNumber e(i,1);

    if(!isValid() || !e.isValid()){
        //0,0 , da mind. einer der Brueche nicht dem Schemata eines Bruches entspricht
        RationalNumber rn (0,0);
        return rn;
    }

    RationalNumber rn (e.nenner(),e.zaehler());
    return mul(rn);
}

RationalNumber RationalNumber::operator ==(RationalNumber& e){
    //Ueberpruefung der Rationalnumbers e
    checkNeg();
    e.checkNeg();
    if(!isValid() || !e.isValid()){
        //cout << "false, da mind. einer der Brueche nicht dem Schemata eines Bruches entspricht" << endl;
        return false;
    }
    if(m_nenner == e.nenner()){
        return m_zaehler== e.zaehler();
    }
    int hN = kgV(m_nenner, e.nenner());
    return m_zaehler*(hN/m_nenner) == e.zaehler()*(hN / e.nenner());
}

RationalNumber RationalNumber::operator ==(const int i){
    //Ueberpruefung der Rationalnumbers e

    RationalNumber e(i,1);

    checkNeg();
    e.checkNeg();
    if(!isValid() || !e.isValid()){
        //cout << "false, da mind. einer der Brueche nicht dem Schemata eines Bruches entspricht" << endl;
        return false;
    }
    if(m_nenner == e.nenner()){
        return m_zaehler== e.zaehler();
    }
    int hN = kgV(m_nenner, e.nenner());
    return m_zaehler*(hN/m_nenner) == e.zaehler()*(hN / e.nenner());
}

int RationalNumber::getDigits(double d) {
    stringstream ss;
    string s;
    size_t pos;

    ss<<d;
    s = (ss.str());
    pos = s.find(".");
    s = s.substr(pos);
    return s.length()-1;
}

int RationalNumber::pow(int i , int powindex){
    int stay = i;
    powindex--;
    while(powindex != 0){
        stay *= i;
        powindex--;
    }
    return stay;
}

}
