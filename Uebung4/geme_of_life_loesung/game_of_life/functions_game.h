#ifndef FUNCTIONS_GAME_H_
#define FUNCTIONS_GAME_H_

#include <cstdlib>
#include <Eigen/Dense>
#include <fstream>
#include <time.h>

using namespace Eigen;
using namespace std;

MatrixXi create_field2d(unsigned int ,unsigned int);
void init_field2d(MatrixXi &, const double);
void make_step(MatrixXi &, MatrixXi &);
void plot_field(MatrixXi const &,const unsigned int);

#endif /* FUNCTIONS_GAME_H_ */
