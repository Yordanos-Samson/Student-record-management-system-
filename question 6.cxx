#include <iostream>

using namespace std;
//c++ code to built a ethiopian house

int main()
{
    float mid,final;
    cout<<"enter final"<<endl;
    cin>>final;
    while(final>60||final<0)
    cin>>final;
    cout<<"enter mid"<<endl;
    cin>>mid;
    while(mid>40||mid<0)
    cin>>mid;
    cout<<endl;
    float total;
    total=mid+final;
    if(total>90)
    cout<<"A+";
        else if(total>90 && total<=85)
    cout<<"A";
    else if(total>80 && total<=85)
    cout<<"A-";
        else if(total>75 && total<=80)
    cout<<"B+";
        else if(total>70 && total<=75)
    cout<<"B";
        else if(total>65 && total<=70)
    cout<<"B-";
        else if(total>50 && total<=65)
    cout<<"C";
        else if(total>40 && total<=50)
    cout<<"D";
        else
        cout<<"F";
}