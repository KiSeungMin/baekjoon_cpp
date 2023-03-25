#include<iostream>
#include<string>
using namespace std;

int main(){

    int N;
    cin>>N;

    string input_str;
    cin>>input_str;

    int sum = 0;

    for(size_t i{0}; i < input_str.length(); i++){
        sum += input_str[i] - '0';
    }

    cout<<sum<<"\n";

    return 0;
}