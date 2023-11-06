#include "ResonanceType.h"

#include <iostream>

ResonanceType::ResonanceType(const char* Name, const double Mass, const int Charge, const double Width)
    : ParticleType(Name, Mass, Charge), fWidth(Width) {}

void ResonanceType::PrintParticleType() const {
  ParticleType::PrintParticleType();
  std::cout << "Width: " << fWidth<<"\n";
}

double ResonanceType::GetWidth() const { return fWidth; }
