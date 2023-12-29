
#include <iostream>
#include "Particle.h"
#include "ParticleType.h"
#include "ResonanceType.h"

int main() {


  // ParticleType myParticle("P", 10.5, 6);
  // ResonanceType myResonanceType("R", 20, 7, 22);
  /*std::cout <<"Nome P: "<<myParticle.GetName()<<"\n"<<"Massa P:
  "<<myParticle.GetMass()<<"\n"<<"Carica P:
  "<<myParticle.GetCharge()<<"\n"<<std::endl; std::cout <<"Nome R:
  "<<myResonanceType.GetName()<<"\n"<<"Massa R:
  "<<myResonanceType.GetMass()<<"\n"<<"Carica R:
  "<<myResonanceType.GetCharge()<<"\n"<<"Width:
  "<<myResonanceType.GetWidth()<<std::endl; myParticle.PrintParticleType();
  myResonanceType.PrintParticleType();*/

  // ParticleType * test[2];
  // test[0]= new ParticleType("P", 10.5, 6);
  // test[1]= new ResonanceType("R", 20, 7, 22);
  // for (int i=0; i<2; i++){
  //     test[i]->PrintParticleType();
  // }
gRandom->SetSeed();

TH1F *histo = new TH1F 

  ParticleType pioneP("Pione P", 0.13957, 1);
  ParticleType pioneN("Pione N", 0.13957, -1);
  ParticleType kaoneP("Kaone P", 0.49367, 1);
  ParticleType kaoneN("Kaone N", 0.49367, -1);
  ParticleType protoneP("Protone P", 0.93827, 1);
  ParticleType protoneN("Protone N", 0.93827, -1);
  ResonanceType risonanza("Risonanza", 0.89166, 0, 0.050);

  return 0;
}
//ollistronzo