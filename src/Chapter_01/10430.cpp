#include<iostream>
using namespace std;

int main(){

    int A, B, C;
    cin>>A>>B>>C;

    int first_result = (A + B) % C;
    int second_result = ((A % C) + (B % C)) % C;
    int third_result = (A*B)%C;
    int fourth_result = ((A%C) * (B%C))%C;

    cout<<first_result<<"\n"
    <<second_result<<"\n"
    <<third_result<<"\n"
    <<fourth_result<<"\n";

    return 0;
}