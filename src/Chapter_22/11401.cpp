#include<iostream>
#include<vector>
using namespace std;

unsigned long long mod = 1000000007;

int main(){

    int N, K;
    cin>>N>>K;

    if(K > N/2)
        K = N - K;

    unsigned long long num1 = 1;
    unsigned long long num2 = 1;

    for(int i{0}; i < K; i++){

        num1 = num1 * (N-i);

        if( (K - i > 0) && ( num1 % (K - i)  == 0) ){
            num1 = num1 / (K - i);
            num1 = num1 % mod;
            continue;
        }

        num2 = num2 * (K - i);

        if( (num2 > 0 ) && (num1 % num2 == 0)){
            num1 = num1 / num2;
            num1 = num1 % mod;
            num2 = 1;
        }

        num1 = num1 % mod;
        num2 = num2 % mod;

    }

    long long answer = num1;

    if(num2 > 0)
        answer = answer / num2;

    cout<< answer % mod;
    
    return 0;
}