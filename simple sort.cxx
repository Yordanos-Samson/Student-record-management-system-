#include<iostream>
using namespace std;
int sorta(int a[]);
int main(int argc, char *argv[])
{
	int a [4]={5,8,9,1};
	sorta(a);
		for(int i=0;i<=4-1;i++)
		{ cout<<a[i];}
	
	return 0;
}
int sorta(int a[]){
	for(int i=0;i<=4-2;i++)
	{
		for(int j=i+1;j<=4-1;j++)
		{
			if(a[i]>a[j])
			{
				int t;
				t= a[i];
				a[i]=a[j];
				a[j]=t;
				
			}
		}
	}
}