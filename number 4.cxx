#include <iostream>
using namespace std;
 int main()
{
    int i,j,k;
    char c='f';
    int n=6;
 
    for(i=0;i<=n;i++)
    {
       for(k=1;k<=i;k++)
       {
           cout<<c<<" ";
           c++;
       }
       cout<<endl;
    }
return 0;
}
	