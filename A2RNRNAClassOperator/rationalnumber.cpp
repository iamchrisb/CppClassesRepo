#include <iostream>
#include "rationalnumber.h"


/**
  * Diese Methode ueberprueft ob eine RationalNumber negativ oder positiv ist.
  * Sind Zaehler und Nenner negativ so wird n positiv gemacht
  * Ist die Negation im Nenner so wird sie zum Zaehler getauscht.
  **/
RationalNumber rnCheckNeg(RationalNumber n){
    //
    if(n.zaehler<0 && n.nenner<0){
        RationalNumber rn = {n.zaehler*-1, n.nenner*-1};
        return rn;
    }
    if(n.zaehler>0 && n.nenner<0){
        RationalNumber rn = {n.zaehler*-1, n.nenner*-1};
        return rn;
    }
    return n;
}
/**
  * Diese Methode berechnet den groeßten gemeinsamen Teiler zweier nenner
  **/
int ggT(int nenner1, int nenner2){
    if(nenner2 == 0){
        return nenner1;
    }
    return ggT(nenner2, nenner1%nenner2);
}
/**
  * Diese Methode berechnet das kleinste gemeinsame Vielfache zweier nenner
  **/
int kgV(int nenner1, int nenner2){
    return (nenner1*nenner2)/ggT(nenner1, nenner2);
}
/**
  * Diese Methode ueberprueft ob eine RationalNumber valide ist. Dazu darf der Nenner nicht 0 sein.
  **/
bool RationalNumber::rnIsValid(){
    if(nenner == 0){
        return false;
    }
    return true;
}
/**
  * Diese Methode ueberprueft ob eine RationalNumber Not a Number also keine RationalNumber ist.
  **/
bool RationalNumber::rnIsNaN(){
    if(this.rnIsValid()){
        return false;
    }
    return true;
}
/**
  * Diese Methode ueberprueft ob zwei RationalNumbers gleich sind, also auch den gleichen Wert haben.
  **/
bool RationalNumber::rnEqual(RationalNumber e){
    //Ueberpruefung der Rationalnumbers e und n
    if(!this.rnIsValid() || !e.rnIsValid()){
        //cout << "false, da mind. einer der Brueche nicht dem Schemata eines Bruches entspricht" << endl;
        return false;
    }
    if(nenner == nenner){
        return zaehler==zaehler;
    }
    int hN= kgV(this.nenner, e.nenner);
    return zaehler*(hN/nenner) == zaehler*(hN/nenner);
}
/**
  * Diese Methode checked ob n kleiner e ist.
  **/
bool RationalNumber::rnLessThan(RationalNumber e){
    this = rnCheckNeg(this);
    e = rnCheckNeg(e);
    //Ueberpruefung der Rationalnumbers e und n
    if(!this.rnIsValid() || !e.rnIsValid()){
        //cout << "false, da mind. einer der Brueche nicht dem Schemata eines Bruches entspricht" << endl;
        return false;
    }
    if(nenner == e.nenner){
        return zaehler < e.zaehler;
    }
    int hN= kgV(n.nenner, e.nenner);
    return n.zaehler*(hN/n.nenner) < e.zaehler*(hN/e.nenner);

}
/**
  * Diese Methode addiert zwei RationalNummers
  **/
RationalNumber RationalNumber::rnAdd(RationalNumber n, RationalNumber e){
    //Ueberpruefung der Rationalnumbers e und n
    if(!rnIsValid(n) || !rnIsValid(e)){
        //cout << "0,0 , da mind. einer der Brueche nicht dem Schemata eines Bruches entspricht" << endl;
        RationalNumber rn = {0,0};
        return rn;

    }
    n = rnCheckNeg(n);
    e = rnCheckNeg(e);
    if(n.nenner == e.nenner){
        RationalNumber rn= {n.zaehler+e.zaehler, n.nenner};
        return rn;
    }
    int hN= kgV(n.nenner, e.nenner);
    RationalNumber rn= {(n.zaehler*(hN/n.nenner)) + (e.zaehler*(hN/e.nenner)),hN};
    return rn;
}
/**
  * Diese Methode subtrahiert zwei RationalNumbers
  **/
RationalNumber RationalNumber::rnSubtract(RationalNumber n, RationalNumber e){
    //Ueberpruefung der Rationalnumbers e und n
    if(!rnIsValid(n) || !rnIsValid(e)){
        //cout << "0,0 , da mind. einer der Brueche nicht dem Schemata eines Bruches entspricht" << endl;
        RationalNumber rn = {0,0};
        return rn;
    }
    n = rnCheckNeg(n);
    e = rnCheckNeg(e);
    if(n.nenner == e.nenner){
        RationalNumber rn = {n.zaehler-e.zaehler, n.nenner};
        return rn;
    }
    int hN= kgV(n.nenner, e.nenner);
    RationalNumber rn = {(n.zaehler*(hN/n.nenner)) - (e.zaehler*(hN/e.nenner)),hN};
    return rn;
}
/**
  * Diese Methode multipliziert zwei RationalNumbers
  **/
RationalNumber RationalNumber::rnMultiply(RationalNumber n, RationalNumber e){
    //Ueberpruefung der Rationalnumbers e und n
    if(!rnIsValid(n) || !rnIsValid(e)){
        //cout << "0,0 , da mind. einer der Brueche nicht dem Schemata eines Bruches entspricht" << endl;
        RationalNumber rn = {0,0};
        return rn;
    }

    n = rnCheckNeg(n);
    e = rnCheckNeg(e);

    RationalNumber rn = {n.zaehler*e.zaehler,n.nenner*e.nenner};
    return rn;
}
/**
  * Diese Methode dividiert zwei RationalNumbers
  **/
RationalNumber RationalNumber::rnDivide(RationalNumber n, RationalNumber e){
    //Ueberpruefung der Rationalnumbers e und n
    if(!rnIsValid(n) || !rnIsValid(e)){
        //0,0 , da mind. einer der Brueche nicht dem Schemata eines Bruches entspricht
        RationalNumber rn = {0,0};
        return rn;
    }

    RationalNumber rn = {e.nenner,e.zaehler};
    return rnMultiply(n,rn);
}



