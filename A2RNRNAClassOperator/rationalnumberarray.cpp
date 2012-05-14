#include <iostream>
#include "rationalnumberarray.h"
#include "rationalnumber.h"
#include <stdlib.h>
#include <stdio.h>

namespace rnum {
/**
  * Default Konstruktor des RationalNumberArrays
  **/
RationalNumberArray::RationalNumberArray(int capacity=5)
    : m_data(new RationalNumber[capacity]),
      m_size(0),
      m_capacity(capacity),
      m_error(NoError),
      rnaCallbackFunction(0)

{}

/**
  *Copy Konstruktor
  **/
RationalNumberArray::RationalNumberArray(const RationalNumberArray& r ) {
    for (int i = 0; i < r.m_size; ++i) {
        m_data[i] = r.m_data[i];
    }
    m_size = r.m_size;
    m_capacity = r.m_capacity;
    m_error = r.m_error;
}

/**
  *Dekonstruktor
  **/
RationalNumberArray::~RationalNumberArray(){
    delete[] m_data;
}

/**
  * Vergroeßert oder verkleinert rna bis capacity
  **/
void RationalNumberArray::resize(unsigned int i){
    //Wenn Werte vom Benutzer weggeschmissen
    RationalNumber * rn_temp = new RationalNumber[i];

    for (int var = 0; var < i; ++var) {
        rn_temp[var] = m_data[var];
    }
    delete[] m_data;
    m_data = rn_temp;

}

/**
  *Gibt die belegte Groeße von rna zurueck
  **/
int const RationalNumberArray::getSize(){
    return m_size;
}

/**
  *Gibt die Kapazitaet von rna zurueck
  **/
int const RationalNumberArray::getCapacity(){
    return m_capacity;
}

/**
  *Fuegt ein Element an rna an
  **/
void RationalNumberArray::append(RationalNumber& rn){
    //Nicht wenn rn 0 oder NAN ist
    if(rn.isNaN()){
        //Fehler setzen
        m_error = NoRN;
        if(rnaCallbackFunction!=0){
            rnaCallbackFunction(this);
        }
    }else{
        //Berechnung der freien Stellen, wenn 0 dann Kapazitaet erhoehen
        int count = m_capacity-m_size;
        if(count == 0){
            resize(2*m_capacity+1);
        }
        //ans Ende anfuegen
        m_data[m_size++] = rn;
    }
}

/**
  *Fuegt in rna eine RationalNumber(RN) ein an position
  **/

void RationalNumberArray::set(RationalNumber& rn, unsigned int position){
    //Nicht wenn rn 0 oder NAN ist
    //abfrage mit null angucken
    if(rn.isNaN()){
        //Fehler setzen
        m_error= NoRN;

        if(rnaCallbackFunction!=0){
            rnaCallbackFunction(this);
        }
    }else{
        //Groeße erhoehen, falls position außerhalb von der aktuellen Kapazitaet
        if(m_capacity < position){
            resize(2*(m_capacity+position)+1);
            //Auffuellen der Werte bis zur (exclude)Position mit 0,1
            for(int i=m_size; i<position;i++){
                m_data[i].zaehler(0);
                m_data[i].nenner(1);
            }
        }
        //rn an position setzen
        m_data[position] = rn;
        //size erhoehen
        m_size = position+1;
    }
}

/**
  * Gibt den Pointer auf die RationalNumber an Position zurueck
  **/
//Frank fragen referenz und rückgabe wenn fehler
RationalNumber RationalNumberArray::get(unsigned int position){
    //Wenn position außerhalb der Kapazitaet Fehler setzen und 0 zurueckgeben
    if(position>m_size){
        m_error= OutOfBounds;
        if(rnaCallbackFunction!=0){
            rnaCallbackFunction(this);
        }
        return RationalNumber(0,0);
    }
    return m_data[position];
}

/**
  *Löscht Werte aus dem RationalNumberArray von fromPosition bis tillPosition
  **/

void RationalNumberArray::remove(unsigned int fromPosition, unsigned int tillPosition){
    int temp = fromPosition;
    //Überschreiben der zu löschenden Werte durch lineare Verschiebung der Werte nach der tillPosition
    for(int i= tillPosition; i< m_size;i++){
        m_data[temp] = m_data[i];
        temp=temp+1;
    }
    //zum Verkleinern der Size ausrechnen um wieviel diese kleiner wird
    int count = tillPosition-fromPosition;
    m_size = m_size - count;
    //Wenn die Kapazitaet im Verhältnis zur eigentlich vergebenen Größe zu hoch ist diese verkleinern
    if(getCapacity()>2*m_size+1){
        resize(getCapacity()/2);
    }
}

/**
  *Error setzen und pointer darauf zurueckgeben
  **/

errorTypes& RationalNumberArray::error(){
    return m_error;
}

/**
  *Diese Methode dient dazu, dass wenn ein Fehler auftritt ein Callback stattfinden kann,
  *unter der Vorraussetzung, dass eine Methode geschrieben wurde, die dann ausgefuehrt werden soll.
  *Diese Methode wäre die auf der der Callback stattfindet.
  **/

void RationalNumberArray::rnaErrorCallback(void (*rnaCallbackFunction)(RationalNumberArray*)){
    this->rnaCallbackFunction = rnaCallbackFunction;
}
 /** THE = OPERATOR **/
RationalNumberArray& RationalNumberArray::operator =( const RationalNumberArray& rna) {
    for (int i = 0; i < rna.m_size; ++i) {
        m_data[i] = rna.m_data[i];
    }
    m_size = rna.m_size;
    m_capacity = rna.m_capacity;
    m_error = rna.m_error;
    return *this;
}

/** THE [] OPERATOR **/
const RationalNumber& RationalNumberArray::operator[](int i) const {
    return m_data[i];
}
}
