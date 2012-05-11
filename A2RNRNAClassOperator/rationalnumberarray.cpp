#include <iostream>
#include "rationalnumberarray.h"
#include "rationalnumber.h"
#include <stdlib.h>
#include <stdio.h>

namespace rnum {
/**
  * Erzeugt ein RationalnumberArray und gibt den Pointer darauf zurueck
  **/
RationalNumberArray::RationalNumberArray(int capacity=5)
    : m_data(new RationalNumber[capacity]),
      m_size(0),
      m_capacity(capacity)
      //m_error(0)
{}

//Copy Constructor
RationalNumberArray::RationalNumberArray(const RationalNumberArray& r ) {
    for (int i = 0; i < r.m_size; ++i) {
        m_data[i] = r.m_data[i];
    }
}

/**
  *Löscht rna durch durch Speicherfreigabe
  **/
RationalNumberArray::~RationalNumberArray(){
    delete[] m_data;
}


/*
RationalNumberArray* rnaCreate(int capacity){
    //Pointer auf RNA
    RationalNumberArray *rna = (RationalNumberArray*) malloc(sizeof(RationalNumberArray));

    rna->rnaCallbackFunction=0;
    //Wenn bei der Speicherreservierung etwas schief lief
    if(rna == 0){
        rna->error= OutOfMemory;
        if(rna->rnaCallbackFunction!=0){
            rna->rnaCallbackFunction;
        }
    }
    //Pointer auf RN zum Zugriff auf die einzelnen Elemente
    rna->data=(RationalNumber*) malloc( capacity * sizeof(RationalNumber) );
    //Wenn bei der Speicherreservierung etwas schief lief
    if(rna->data == 0){
        rna->error= OutOfMemory;
        if(rna->rnaCallbackFunction!=0){
            rna->rnaCallbackFunction;
        }
    }
    //Werte setzen
    rna->capacity = capacity;
    rna->size = 0;

    return rna;
}
*/

/**
  * Vergroeßert oder verkleinert rna bis capacity
  **/

void RationalNumberArray::resize(unsigned int i){
    //Wenn Werte vom Benutzer weggeschmissen
    RationalNumber * rn_temp = new RationalNumber[i];

    for (int var = 0; var < i; ++var) {
        rn_temp[i] = m_data[i];
    }

    m_data = rn_temp;
    delete[] rn_temp;
}

/**
  *Gibt die belegte Groeße von rna zurueck
  **/

int RationalNumberArray::getSize(){
    return m_size;
}

/**
  *Gibt die Kapazitaet von rna zurueck
  **/

int RationalNumberArray::getCapacity(){
    return m_capacity;
}

/**
  *Fuegt ein Element an rna an
  **/
/*
void push(RationalNumber& rn){
    //Nicht wenn rn 0 oder NAN ist
    if(rn==0|| rn.isNaN()){
        //Fehler setzen
        rna->error= NoRN;
        if(rna->rnaCallbackFunction!=0){
            rna->rnaCallbackFunction;
        }
    }else{
        //Berechnung der freien Stellen, wenn 0 dann Kapazitaet erhoehen
        int count = rna->capacity-rna->size;
        if(count == 0){
            rnaResize(rna, 2*rna->capacity+1);
        }
        //ans Ende anfuegen
        rna->data[rna->size++] = *rn;
        //Flag ob Wert von Benutzer eingetragen
        rna->data[rna->size].fromUser = true;
    }
}
*/
/**
  *Fuegt in rna eine RationalNumber(RN) ein an position
  **/
/*
void rnaSet(RationalNumberArray* rna, RationalNumber* rn, int position){
    //Nicht wenn rn 0 oder NAN ist
    if(rn==0 || rnIsNaN(*rn)){
        //Fehler setzen
        rna->error= NoRN;
        if(rna->rnaCallbackFunction!=0){
            rna->rnaCallbackFunction;
        }
    }else{
        //Groeße erhoehen, falls position außerhalb von der aktuellen Kapazitaet
        if(rna->capacity < position){
            rnaResize(rna, 2*rna->capacity+1);
            //Auffuellen der Werte bis zur (exclude)Position mit 0,1
            for(int i=rna->size; i<position;i++){
                if(rna->data[i].fromUser == false){
                    rna->data[i].zaehler= 0;
                    rna->data[i].nenner= 1;
                    //Flag ob nicht vom Benutzer
                    rna->data[i].fromUser= false;
                }
            }
        }
        //rn an position setzen
        rna->data[position] = *rn;
        //Flag ob vom Benutzer
        rna->data[position].fromUser = true;
        //size erhoehen
        rna->size = position+1;
    }
}
*/
/**
  * Gibt den Pointer auf die RationalNumber an Position zurueck
  **/
/*
RationalNumber* rnaGet(RationalNumberArray* rna, int position){
    //Wenn position außerhalb der Kapazitaet Fehler setzen und 0 zurueckgeben
    if(position>rna->size){
        rna->error= OutOfBounds;
        if(rna->rnaCallbackFunction!=0){
            rna->rnaCallbackFunction;
        }
        return 0;
    }
    return &(rna->data[position]);
}
*/
/**
  *Löscht Werte aus dem RationalNumberArray von fromPosition bis tillPosition
  **/
/*
void rnaRemove(RationalNumberArray *rna, int fromPosition, int tillPosition){
    int temp = fromPosition;
    //Überschreiben der zu löschenden Werte durch lineare Verschiebung der Werte nach der tillPosition
    for(int i= tillPosition; i< rna->size;i++){
        rna->data[temp] = rna->data[i];
        temp=temp+1;
    }
    //zum Verkleinern der Size ausrechnen um wieviel diese kleiner wird
    int count = tillPosition-fromPosition;
    rna->size = rna->size - count;
    //Wenn die Kapazitaet im Verhältnis zur eigentlich vergebenen Größe zu hoch ist diese verkleinern
    if(rnaCapacity(rna)>2*rna->size+1){
        rnaResize(rna, rnaCapacity(rna)/2);
    }
}
*/
/**
  *Error setzen und pointer darauf zurueckgeben
  **/
/*
errorTypes* rnaError(RationalNumberArray *rna){
    return &(rna->error);
}
*/
/**
  *Diese Methode dient dazu, dass wenn ein Fehler auftritt ein Callback stattfinden kann,
  *unter der Vorraussetzung, dass eine Methode geschrieben wurde, die dann ausgefuehrt werden soll.
  *Diese Methode wäre die auf der der Callback stattfindet.
  **/
/*
void rnaErrorCallback(RationalNumberArray* rna, void (*rnaCallbackFunction)(RationalNumberArray*)){
    rna->rnaCallbackFunction = rnaCallbackFunction;
}
*/
}
