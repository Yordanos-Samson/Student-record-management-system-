#include <iostream>

using namespace std;
int factorial(int);

int main()
{
    int n;           
    cout<<"enter a number"<<endl;
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
   
   //by recursive function
  
  int sum1=0;
  for(int i=1;i<=n;i++)
  {
  sum1+=factorial(i);
  }
  cout<<endl<<sum1;
}
int factorial(int x)
{
    if(x==1)
    return 1;
    else 
    return x*factorial(x-1);
}