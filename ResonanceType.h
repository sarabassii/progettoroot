#ifndef RESONANCETYPE_H
#define RESONANCETYPE_H
#include "ParticleType.h"

class ResonanceType: public ParticleType{
    public: 
    ResonanceType ( const char* Name, const double Mass, const int Charge, const double Width); //costruttore parametrico (per non restituire mai alcun tipo)
    double GetWidth() const;//per accesso indiretto all'attributo dall'esterno
    void PrintParticleType () const; //metodo Print()
    private: 
    const double fWidth; 

};



#endif

