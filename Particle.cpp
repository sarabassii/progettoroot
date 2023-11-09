#include <iostream>
#include <cmath>  // for M_PI
#include <cstdlib> //for RAND_MAX
#include "Particle.h"



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

int Particle::Decay2body(Particle &dau1,Particle &dau2) const {
  if(GetMassI() == 0.0){
    printf("Decayment cannot be preformed if mass is zero\n");
    return 1;
  }
double massMot = GetMassI();
  double massDau1 = dau1.GetMassI();
  double massDau2 = dau2.GetMassI();

  if(fIndex > -1){ // add width effect

    // gaussian random numbers

    float x1, x2, w, y1;
    
    double invnum = 1./RAND_MAX;
    do {
      x1 = 2.0 * rand()*invnum - 1.0;
      x2 = 2.0 * rand()*invnum - 1.0;
      w = x1 * x1 + x2 * x2;
    } while ( w >= 1.0 );
    
    w = sqrt( (-2.0 * log( w ) ) / w );
    y1 = x1 * w;

    massMot += fParticleType[fIndex]->GetWidth() * y1;

  }
   if(massMot < massDau1 + massDau2){
    printf("Decayment cannot be preformed because mass is too low in this channel\n");
    return 2;
  }
  
  double pout = sqrt((massMot*massMot - (massDau1+massDau2)*(massDau1+massDau2))*(massMot*massMot - (massDau1-massDau2)*(massDau1-massDau2)))/massMot*0.5;

  double norm = 2*M_PI/RAND_MAX;

  double phi = rand()*norm;
  double theta = rand()*norm*0.5 - M_PI/2.;
  dau1.SetP(pout*sin(theta)*cos(phi),pout*sin(theta)*sin(phi),pout*cos(theta));
  dau2.SetP(-pout*sin(theta)*cos(phi),-pout*sin(theta)*sin(phi),-pout*cos(theta));

  double energy = sqrt(fPx*fPx + fPy*fPy + fPz*fPz + massMot*massMot);

  double bx = fPx/energy;
  double by = fPy/energy;
  double bz = fPz/energy;

  dau1.Boost(bx,by,bz);
  dau2.Boost(bx,by,bz);

  return 0;
}

void Particle::Boost(double bx, double by, double bz)
{

  double energy = GetEnergy();

  //Boost this Lorentz vector
  double b2 = bx*bx + by*by + bz*bz;
  double gamma = 1.0 / sqrt(1.0 - b2);
  double bp = bx*fPx + by*fPy + bz*fPz;
  double gamma2 = b2 > 0 ? (gamma - 1.0)/b2 : 0.0;

  fPx += gamma2*bp*bx + gamma*bx*energy;
  fPy += gamma2*bp*by + gamma*by*energy;
  fPz += gamma2*bp*bz + gamma*bz*energy;
}

