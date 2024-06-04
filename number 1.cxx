#include <iostream>

using namespace std;
//c++ code to built a ethiopian house

int main()
{
    int x,y;
    cout<<"please enter the lower limit"<<endl;;
    cin>>x;
    cout<<"please enter the upper limit"<<endl;
    cin>>y;
    for(int i=x;i<=y;i++)
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