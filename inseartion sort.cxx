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
	for(int i=1;i<=5-2;i++)
	{
		for(int j=i;j>=4-3;j--)
		{
			if(a[j-1]>a[j])
			{
				int t;
				t= a[j];
				a[j]=a[j-1];
				a[j-1]=t;
				
			}
			else
			break;
		}
	}
}