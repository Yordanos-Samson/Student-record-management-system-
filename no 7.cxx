#include <iostream>

using namespace std;
int average();
int main()
{
    average();
    return 0;
}
int average()
{
		float m,sum=0;
		float ave;
		float mark[8];
		cout<<"please enter the marks one after the other"<<endl;
   for(int m=0;m<8;m++)
    {
    	cin>>mark[m];
    	while(mark[m]<0||mark[m]>100)
    	{
    		cout<<"please enter the correct mark"<<endl;
    		cin>>mark[m];
    	}
    
    	sum=sum+mark[m];
    }
    ave=(sum)/8.0;  // ave symbolize average value
    cout<<"The average mark is "<<ave;
}