#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct data{
    unsigned int val1;
    int val2;
};

int main(){
    srand(time(NULL));

    vector <data> Contain;
    data m_data[10];
    for(int i=0;i<10;i++){
        m_data[i].val1 = i;
        m_data[i].val2 = rand();
        Contain.push_back(m_data[i]);
    }
    cout<<"==== for with auto ===="<<endl;
    for(auto x: Contain){
        cout<<x.val1<<" "<<x.val2<<endl;
    }
    cout<<"====== for_each ======="<<endl;
    for_each(Contain.begin(),Contain.end(),[](data x){cout<<x.val1<<" "<<x.val2<<endl;});

    cout<<"======= sort() ========"<<endl;
    sort(Contain.begin(),Contain.end(),[](data x,data y)->bool{return x.val2<y.val2;});
    for_each(Contain.begin(),Contain.end(),[](data x){cout<<x.val1<<" "<<x.val2<<endl;});

    cout<<"==== change value ====="<<endl;
    for_each(Contain.begin(),Contain.end(),[](data &x){x.val2 = x.val1 * x.val1;});
    for_each(Contain.begin(),Contain.end(),[](data x){cout<<x.val1<<" "<<x.val2<<endl;});

    int val{42};
    cout<<"== re-allocate val2 ==="<<endl;
    for_each(Contain.begin(),Contain.end(),[=](data &x){x.val2 = val;});
    for_each(Contain.begin(),Contain.end(),[](data x){cout<<x.val1<<" "<<x.val2<<endl;});

    cout<<"== re-allo with val++ =="<<endl;
    for_each(Contain.begin(),Contain.end(),[&](data &x){x.val2 = val; val++;});
    for_each(Contain.begin(),Contain.end(),[](data x){cout<<x.val1<<" "<<x.val2<<endl;});
    cout<<"after for-loop val = "<<val<<endl;

    return 0;
}