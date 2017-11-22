#include<iostream>
using namespace std;

long int fibo_table[100]={-1};

long int fibonacci_n(int n)
{
  if(fibo_table[n]>0) return fibo_table[n];
  if(n==0) return 0;
  if(n==1) return 1;
  fibo_table[n]=fibonacci_n(n-1)+fibonacci_n(n-2);
  return fibo_table[n];
}

double fibo_quoti(int n)  //f(n+1)/f(n)
{
  if(n==0) return 0;
  return double(fibonacci_n(n+1))/double(fibonacci_n(n));
}

int main()
{
  //test output
  cerr<<fibonacci_n(5)<<endl;
  cerr<<fibo_quoti(5)<<endl;
  
  long int sum=0;
  int count=50;
  cout<<"#   n    F(n)    F(n)/F(n-1)"<<endl;
  for(int i=1;i<count;i++)
  {
    cout<<"   "<<i<<"   "<<fibonacci_n(i)<<"   "<<fibo_quoti(i-1)<<endl;
    sum+=fibonacci_n(i-1);
  }
  cout<<"# sum of first "<<count<<" Fibonacci number: "<<sum<<endl;

  return 0;
}
