#ifndef PARTICLETYPE_H
#define PARTICLETYPE_H

class ParticleType{
    public: 
    ParticleType (const char* Name, const double Mass, const int Charge); //costruttore parametrico (per non restituire mai alcun tipo)
    const char* GetName ()const;        //per accesso indiretto all'attributo dall'esterno
    double GetMass()const;
    int GetCharge()const;
    virtual void PrintParticleType () const;             //metodo Print(), virtualizazzione, devo CHIAMARE il print e devo aggiungerci un virtual
    
    private: 
    const char* fName;
    const double fMass;
    const int fCharge;

};





#endif
