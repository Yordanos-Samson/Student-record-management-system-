#include <iostream>

using namespace std;
int factorial(int);

int main()
{
    int n;           
    cout<<"enter a number upto which the operation is done"<<endl;
    cin>>n;
    
    //by using loop
   int sum=0;
   for(int j=1;j<=n;j++)
   {
  int  fact=1;
    for(int i=1;i<=j;i++)
    {
        fact*=i;
    }
    sum+=fact;
    
   }
   cout<<sum;
}