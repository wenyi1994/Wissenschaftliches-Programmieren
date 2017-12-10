#include <iostream>
#include <cassert>

using namespace std;

int main()
{
    int i;
    for(;;)
    {
        cin >> i;
        assert(i!=0);
        cout << "i = " << i<<endl;
    }

    return 0;
}