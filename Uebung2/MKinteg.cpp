#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

double area(double r, int count)
{
  int in=0;
  double x,y;
  for(int i=0;i<count;i++)
  {
    x=double(rand())/double(RAND_MAX)*r-r;
    y=double(rand())/double(RAND_MAX)*r-r;
    if(x*x+y*y<=r*r) in++;
  }
  return double(in)/double(count)*4.0*r*r;
}

int main()
{
  srand((unsigned)time(NULL));
  //test output
  cerr<<rand()<<endl;

  double r=1;
  cout<<"area of a round with radius = "<<r<<" is: "<<area(r,1000000)<<endl;
  return 0;
}
