#include <iostream>
#include  <cmath>
using namespace std;

int main(){
    double v1,v2,v3;

    // Vergleich von Fliesszahlen

    for(int i=0;i<10;i++){
        v1=pow(10,i)*1e16;
        v2=v1;
        unsigned int nc { 0};
        v3 =0.;
        while(v2==v1){
            v3+=10.e2;  // Inkrement erhöhen
            v2+=v3;

            nc++;
            //
            if(nc==0){
                cout<<"break ";
                break;
            }
        }
        cout<<"nc="<<nc  <<" v2="<<v2<<" v1="<<v1<<endl;
    }
    return 0 ;
}



