#include "particle.h"
#include "verlet.h"

//VERLET::

void init_verlet(particle *const p, const int nmax){
  // setze alle Kräfte auf Null:
  for(int i=0;i<nmax;i++)
    for(int n=0;n<dim;n++)
      p[i].f[n]=0.;
}

void update_positions(particle *const p,const int nmax, const double dt){
  double a;
  for(int i=0;i<nmax;i++){
    a= 0.5*dt/p[i].m;
    for(int n = 0; n<dim; n++){
      p[i].pos[n] += dt * (p[i].vel[n]+ a*p[i].f[n]);
      p[i].fold[n] = p[i].f[n];
    }
  }
}

void update_velocities(particle *const p, const int nmax, const double dt){
  double a;
  for(int i=0;i<nmax;i++){
    a= 0.5*dt/p[i].m;
    for(int n=0;n<dim;n++)
      p[i].vel[n] += a * (p[i].f[n]+p[i].fold[n]);
  }
}
