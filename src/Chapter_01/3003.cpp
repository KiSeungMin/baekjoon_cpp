#include<iostream>
#include<vector>
using namespace std;

const int N = 6;

int main(){

    vector<int>input_arr;
    for(int i{0}; i < N; i++){
        int num;
        cin>>num;

        input_arr.push_back(num);
    }

    const vector<int>goal_arr = {1, 1, 2, 2, 2, 8};

    vector<int>result_arr = {0, 0, 0, 0, 0, 0};

    for(int i{0}; i < N; i++){
        result_arr[i] = goal_arr[i] - input_arr[i];
    }

    for(auto i : result_arr){
        cout<<i<<" ";
    }

    return 0;
}