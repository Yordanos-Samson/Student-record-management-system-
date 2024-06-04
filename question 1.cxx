#include <iostream>

using namespace std;
//c++ code to built a ethiopian house

int main()
{
    for(int i=2;i<=100;i++)
    {
        for(int j=2;j<=i;j++)
        {
            if(i==j)
            cout<<j<<" ,";
            else
            {
                if(i%j==0)
                break;
            }
        }
    }
}