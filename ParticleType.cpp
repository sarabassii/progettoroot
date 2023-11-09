

#include <iostream>
#include "ParticleType.h"

ParticleType::ParticleType(const char* Name, const double Mass, const int Charge)
    : fName(Name), fMass(Mass), fCharge(Charge){};

void ParticleType::PrintParticleType() const {std::cout
                                       << "\nNome: " << fName <<"\n"<< "Massa: "
                                       << fMass <<"\n"<<"Carica: " << fCharge<<std::endl;}
const char* ParticleType::GetName() const {return fName;}
double ParticleType::GetMass() const{return fMass;}
int ParticleType::GetCharge() const{return fCharge;}

double ParticleType::GetWidth() const {return 0;}
