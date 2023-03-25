#include<iostream>
#include<iomanip>
using namespace std;

int main(){

    int A, B;
    cin>>A>>B;

    double result = A / static_cast<double> (B);

    cout<<setprecision(10)<<fixed<<result<<endl;

    return 0;
}