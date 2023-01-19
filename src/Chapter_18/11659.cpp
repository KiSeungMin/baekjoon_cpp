#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

int main(){

    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin>>N>>M;

    vector<int>input_arr(N + 1, 0);
    vector<int>sum_arr(N + 1, 0);
    for(int i{1}; i <= N; i++){
        cin>>input_arr[i];

        sum_arr[i] = sum_arr[i - 1] + input_arr[i];
    }
        
    for(int j{0}; j < M; j++){
        int start, end;
        cin>>start>>end;

        cout<<sum_arr[end] - sum_arr[start - 1]<<"\n";
    }


    return 0;
}