#include<iostream>
#include<vector>
using namespace std;

int main(){

    int n; cin >> n;

    vector<int>fibonacci = {0, 1, 2};

    for(int i{3}; i <= n; i++){
        int nextNum = fibonacci[i - 1] + fibonacci[i - 2];
        fibonacci.push_back(nextNum % 10007);
    }

    cout<<fibonacci[n]<<"\n";

    return 0;
}