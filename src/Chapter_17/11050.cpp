#include<iostream>
#include<vector>
using namespace std;

int nCk(int a, int b);

int main(){

    int N, K;
    cin>>N>>K;

    if(K > N-K)
        cout<<nCk(N, N-K);

    else
        cout<<nCk(N, K);

    return 0;
}

int nCk(int a, int b){

    int up=1;
    int down=1;

    for(int i{0}; i < b; i++){
        up = up*(a-i);
    }

    for(int i{1}; i <=b; i++){
        down=down*i;
    }

    return up/down;
}
