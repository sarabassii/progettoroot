
#include <iostream>
#include "ParticleType.h"
#include "ResonanceType.h"
#include "Particle.h"

int main () {
    ParticleType myParticle("P", 10.5, 6);
    ResonanceType myResonanceType("R", 20, 7, 22);
    /*std::cout <<"Nome P: "<<myParticle.GetName()<<"\n"<<"Massa P: "<<myParticle.GetMass()<<"\n"<<"Carica P: "<<myParticle.GetCharge()<<"\n"<<std::endl;
    std::cout <<"Nome R: "<<myResonanceType.GetName()<<"\n"<<"Massa R: "<<myResonanceType.GetMass()<<"\n"<<"Carica R: "<<myResonanceType.GetCharge()<<"\n"<<"Width: "<<myResonanceType.GetWidth()<<std::endl;
    myParticle.PrintParticleType();
    myResonanceType.PrintParticleType();*/

    ParticleType * test[2];
    test[0]= new ParticleType("P", 10.5, 6);
    test[1]= new ResonanceType("R", 20, 7, 22);
    for (int i=0; i<2; i++){
        test[i]->PrintParticleType();
    }


    return 0;
}
