#include<iostream>
#include<vector>
#include<algorithm>
#define sync_with_stdio(NULL)
using namespace std;

const int N = 5;

int main(){

    cin.tie(NULL);

    int sum = 0;
    vector<int>input_arr(N, 0);

    for(int i{0}; i < N; i++){
        cin>>input_arr[i];
        sum += input_arr[i];
    }

    sort(input_arr.begin(), input_arr.end());

    int average = sum / N;

    cout<<average<<"\n";
    cout<<input_arr[N / 2]<<"\n";

    return 0;
}