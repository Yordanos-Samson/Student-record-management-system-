#include <iostream>

using namespace std;
//c++ 

int main()
{
    int space=3,star=1,count=1;
    for(int i=1;i<=7;i++)
    {
        for(int j=1;j<=space;j++)
        cout<<" ";
        for(int k=1;k<=star;k++)
        cout<<"*";
        cout<<endl;
        count++;
        if(count<=4)
        {
            space-=1;
            star+=2;
        }
        else
        {
            space+=1;
            star-=2;
        }
    }
}