#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

int main(){

    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin>>N>>K;

    vector<int>sum_arr(N + 1, 0);
    for(int i{1}; i <= N; i++){
        int input_num; cin>>input_num;

        sum_arr[i] = sum_arr[i - 1] + input_num;
    }

    int answer = -1000000000;
    for(int end{K}; end <= N; end++){

        if(sum_arr[end] - sum_arr[end - K] > answer)
            answer = sum_arr[end] - sum_arr[end - K];
    }

    cout<<answer<<"\n";

    return 0;
}