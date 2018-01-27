#ifndef _LINKED_LIST
#define _LINKED_LIST

extern void init_linked_list(const double L[], const double rcut,const int ntot);
extern void setup_neighbour_list(const particle *p, const int ntot);
extern void print_neighour_list();
extern void force_calculation_neighbour(particle *p, const int ntot,
					void force(particle *p1, particle *p2));

#endif
