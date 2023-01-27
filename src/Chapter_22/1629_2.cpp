#include<iostream>
using namespace std;

long long getAnswer(long long num, long long exp, long long mod){

    num = num % mod;

    if(exp == 1)
        return num;

    long long result = getAnswer(num, exp / 2, mod);
    result %= mod;

    result = result * result;
    result %= mod;

    if(exp % 2 == 1){
        result *= num;
        result %= mod;
    }

    return result;
}

int main(){

    long long num, exp, mod;
    cin>>num>>exp>>mod;

    cout<<getAnswer(num, exp, mod)<<"\n";

    return 0;
}