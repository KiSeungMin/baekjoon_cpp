#include<iostream>
#include<vector>
using namespace std;

int main(){

    int N; cin>>N;
    int result1, result2;

    vector<int>pibo = {0, 1, 1};
    for(int i{3}; i <= N; i++){
        int nextNum = pibo[i - 1] + pibo[i - 2];
        pibo.push_back(nextNum);
    }

    result1 = pibo[N];
    result2 = N - 2;
    cout<<result1<<" "<<result2<<"\n";
}