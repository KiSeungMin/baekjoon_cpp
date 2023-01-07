#include<iostream>
using namespace std;

int main(){

    int A, B;
    cin>>A>>B;

    int plus_result = A + B;
    int minus_result = A - B;
    int multi_result = A * B;
    int division_result = A / B;
    int remainder_result = A % B;

    cout<<plus_result<<"\n"<<minus_result<<"\n"<<multi_result<<"\n"
    <<division_result<<"\n"<<remainder_result<<endl;

    return 0;
}