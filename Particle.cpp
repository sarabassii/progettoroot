#include "Particle.h"

#include <iostream>
#include <cmath>

int Particle::fNParticleType =
    0;  // per tracciare il numero di tipi di particelle
ParticleType* Particle::fParticleType[Particle::fMaxNumParticleType] = {};

Particle::Particle(const char* Name, double Px, double Py, double Pz)
    : fPx(Px), fPy(Py), fPz(Pz) {
  fIndex = FindParticle(Name);
};

int Particle::FindParticle(const char* NameInput) {
  for (int i = 0; i < fMaxNumParticleType; i++) {
    if (fParticleType[i]->GetName() == NameInput) {
      return i;
    }
  }

  std::cout << "No matches founf fpr the name in input";
  return -1;
}

int Particle::GetIndex() { return fIndex; }

void Particle::AddParticleType(const char* Name, const double Mass,
                               const int Charge, const double Width) {
  // Ciclo for per controllare se quella particella esiste già
  if (fNParticleType == fMaxNumParticleType) {
    std::cout << "Not enough space to add another particle";
  } else if (Width == 0) {
    fParticleType[fNParticleType] = new ParticleType(Name, Mass, Charge);
    fNParticleType++;
  } else {
    fParticleType[fNParticleType] =
        new ResonanceType(Name, Mass, Charge, Width);
    fNParticleType++;
  }
}

void Particle::SetIndex(int index) {
  if (index >= fNParticleType) {
    std::cout << "Invalid index.\n";
    std::exit(EXIT_FAILURE);
  }

  fIndex = index;
}

void Particle::SetIndex(const char* Name) { fIndex = FindParticle(Name); }

void Particle::PrintArray() {
  for (int i = 0; i < fNParticleType; i++) {
    fParticleType[i]->PrintParticleType();
  }
}

void Particle::PrintParticleData() {
  std::cout << "FIndex: " << fIndex << '\n';
  std::cout << "Px: " << fPx << '\n';
  std::cout << "Py: " << fPy << '\n';
  std::cout << "Pz: " << fPz << '\n';
}

double Particle::GetPx() const {return fPx;}
double Particle::GetPy() const{return fPy;}
double Particle::GetPz() const{return fPx;}
double Particle::GetMassI() const {return fParticleType[fIndex]->GetMass();}

double Particle::GetEnergy() const {
    const double mass=GetMassI();
    return std::sqrt(mass * mass + fPx * fPx + fPy * fPy + fPz * fPz);
}

double Particle::InvMass(const Particle& particle) const {
    const double sumEnergy{GetEnergy() + particle.GetEnergy()};
	const double sumPx{fPx + particle.fPx};
	const double sumPy{fPy + particle.fPy};
	const double sumPz{fPz + particle.fPz};

	return std::sqrt(sumEnergy * sumEnergy - sumPx * sumPx - sumPy * sumPy - sumPz * sumPz);
}
