#include<iostream>
#include<vector>
using namespace std;

int main(){

    int N; cin >> N;
    vector<int>answer  = {0, 1};
    for(int i{1}; i <= N - 1; i++){
        
        if(i % 2 == 1)
            answer.push_back((2 * answer[i] + 1) % 10007);
        else
            answer.push_back((2 * answer[i] - 1) % 10007);
    }

    cout<<answer[N]<<"\n";

    return 0;
}