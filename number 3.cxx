#include <iostream>

using namespace std;
//c++ code to built a ethiopian house

int main()
{
    int space=4,star=1,checker=1;
    if(checker==1)
    {
        for(int i=1;i<=5;i++)
          {
              for(int j=1;j<=space;j++)
              cout<<"  ";
              for(int k=1;k<=star;k++)
              cout<<" *";
              cout<<endl;
              space-=1;
              star+=2;
          }
    }
    checker++;
    if(checker==2)
    {
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=2;j++)
            cout<<"  ";
            for(int k=1;k<=5;k++)
            cout<<" *";
            
            cout<<endl;
        }
    }
}