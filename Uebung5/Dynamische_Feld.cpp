#include <iostream>

using namespace std;

int main()
{
    int **b;
    b = new int*[3];
    b[0] = new int[3*5];

    for(int i = 1; i<3; i++)
    {
        b[i] = b[0] + i * 5;
    }

    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<5; j++)
        b[i][j] = i + j;
    }

    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<5; j++)
        {
            cout << "b["<<i<<"]["<<j<<"] = "<<b[i][j]<<" ";
        }
        cout<<endl;
    }

    delete[] b[0];
    delete[] b;

    return 0;
}