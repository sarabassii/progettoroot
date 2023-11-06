#ifndef PARTICLE_H
#define PARTICLE_H
#include "ParticleType.h"
#include "ResonanceType.h"

class Particle {
 public:
  // Fare check costruttore
  Particle(
      const char* Name, double fPx = 0, double fPy = 0,
      double fpZ = 0);  // forse mettere static e forse mettere dimensione array
  int GetIndex();
  static void AddParticleType(const char* Name, const double Mass,
                              const int Charge, const double Width);
  void SetIndex(int index);
  void SetIndex(const char* index);
  static void PrintArray();
  void PrintParticleData();
  double GetPx() const;
  double GetPy() const;
  double GetPz() const;
  double GetMassI() const;
  double GetEnergy() const;
  double InvMass(const Particle& particle) const;
  void SetP(double px, double py, double pz) {
    fPx = px;
    fPy = py;
    fPz = pz;
  }

 private:
  static const int fMaxNumParticleType = 10;
  static ParticleType*
      fParticleType[fMaxNumParticleType];  // dimensione dell'array
  static int fNParticleType;
  int fIndex;  // ci salviamo la posizione della particella nell'array
  double fPx;
  double fPy;
  double fPz;
  static int FindParticle(const char* Name);
};

#endif
