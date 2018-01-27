#ifndef _VERLET
#define _VERLET
#include "particle.h"

extern void init_verlet(particle *const p, const int nmax);
extern void update_positions(particle *const p,const int nmax, const double dt);
extern void update_velocities(particle *const p, const int nmax, const double dt);

#endif
