#include<iostream>
#include<string>
using namespace std;

const int sqrt = 31;
const long long mod = 1234567891;

long long getSqrt(long long num, int repeat){
    long long result = 1;
    for(int i{0}; i < repeat; i++){
        result *= num;
        result %= mod;
    }

    return result;
}

long long getHash(string str, int length){

    long long result = 0;

    for(int i{0}; i < length; i++){
        result += (str[i] - 'a' + 1) * getSqrt(sqrt, i);
        result %= mod;
    }

    return result;
}

int main(){

    int length; cin >> length;
    string input_str; cin >> input_str;

    cout<<getHash(input_str, length)<<"\n";
}