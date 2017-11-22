#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
  double hw;
  float nsteps;
  const double PI = 3.14159;
 
  cout<<"#Plotten einer Sinuskurve  f(x) = sin(x)"<<endl;
  cout<<"#----------------------------------------"<<endl;
  cout<<"#Anzahl der sinus Halbwellen (= Vielfaches von PI): "<<endl;
  cin >> hw;
  
  bool check_hw=true;
  string input_string;
  while(check_hw)
  {
    if(cin.fail())
      {
        cin.clear();
        cin >> input_string;
        cout<<"#Error: Eingabe soll eine Zahl sein, Vielfaches neu einzugeben: "<<endl;
        cin >> hw;
        continue;
      }
    if (hw<=0)
      {
        cout<<"#Error: Eingabe muss >0, Vielfaches neu einzugeben: "<<endl;
        cin >> hw;
        continue;
      }
    check_hw=false;
  }

  cout <<"#Anzahl der Stuetzstellen: "<<endl;
  cin >> nsteps;

  bool check_nsteps=true;
  while(check_nsteps)
  {
    if(cin.fail())
    {
      cin.clear();
      cin >> input_string;
      cout<<"#Error: Eingabe ist keine positive Ganzzahl, neu einzugeben: "<<endl;
      cin >> nsteps;
      continue;
    }
    if(nsteps>(int)nsteps)
    {
      cout<<"#Error: Eingabe ist keine positive Ganzzahl, neu einzugeben: "<<endl;
      cin >> nsteps;
      continue;
    }
    if(nsteps<=0)
    {
      cout<<"#Error: Eingabe ist keine positive Ganzzahl, neu einzugeben: "<<endl;
      cin >> nsteps;
      continue;
    }
    check_nsteps=false;
  }

  const double maxx = hw * PI;
  const double deltax = maxx/nsteps;

  cout<<"#Der x-Bereich liegt jetzt zwischen 0 und " <<maxx<<endl
      <<"#Diskretisierung durch "<< nsteps<< " Stuetzstellen "
      <<endl<<endl
      << "  #x    f(x) "<<endl;

 
  double x = 0.0;
  
  for ( int i = 0; i< nsteps; i++){
    const double f = sin(x);
    cout << x<< "  " << f << endl;
    x = x + deltax;
  }
  
  return 0;
}
