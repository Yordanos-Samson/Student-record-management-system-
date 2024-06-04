#include<iostream>
using namespace std;
int sorta(int a[]);
int main(int argc, char *argv[])
{
	int a [4]={5,8,9,1};
	sorta(a);
		for(int i=4-1;i>=0;i--)
		{ cout<<a[i];}
	
	return 0;
}
int sorta(int a[]){
	int min;
	for(int i=0;i<=4-2;i++)
	{
		min=i;
		for(int j=i+1;j<=4-1;j++)
		{
				if(a[j]<a[min])
				min=j;
				
		}
			if(min!=i)
			{
				int t;
				t= a[i];
				a[i]=a[min];
				a[i]=t;
				
			}
		
	}
}