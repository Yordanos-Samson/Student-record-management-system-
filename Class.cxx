#include <iostream>
using namespace std;
int n1, n2, n3=20;
int mult ( ) {
    int a, b;
    cin>>a>>n1;
    b=a*n1;
    cout <<"Product" <<b;
}
int main( ) {
    int c;
    cin >>n2;
    c = n3 + n2;
    mult ( ); // function call
    cout <<"Addition" <<c;
    return 0;
}