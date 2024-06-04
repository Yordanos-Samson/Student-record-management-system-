#include<iostream>
using namespace std;
int sorta(int a[]);
int main(int argc, char *argv[])
{
	int a [4]={5,8,9,1};
	sorta(a);
		for(int i=3;i>=0;i--)
		{ cout<<a[i];}
	
	return 0;
}
int sorta(int a[]){
	for(int i=4-2;i>=0;i--)
	{
		for(int j=4-1;j<=i;j++)
		{
			if(a[j]>a[j+1])
			{
				int t;
				t= a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				
			}
		}
	}
}