#include<iostream>
#include<vector>
#include<algorithm>
#define sync_with_stdio(false)
using namespace std;

/*
    이진 탐색을 이용한 풀이
*/

int binary_search(vector<int>& arr, int goal_num, int start, int end){

    if(start > end)
        return 0;

    int center = (start + end) / 2;

    if(arr[center] == goal_num)
        return 1;

    else if(goal_num < arr[center])
        return binary_search(arr, goal_num, start, center - 1);

    return binary_search(arr, goal_num, center + 1, end);
}

int main(){

    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin>>N;

    vector<int>input_arr(N, 0);
    for(int i{0}; i < N; i++)
        cin>>input_arr[i];

    int M; cin>>M;
    vector<int>find_arr(M, 0);
    for(int i{0}; i < M; i++)
        cin>>find_arr[i];

    sort(input_arr.begin() , input_arr.end());
    for(int i{0}; i < M; i++)
        cout<<binary_search(input_arr, find_arr[i], 0, N - 1)<<" ";

    return 0;
}


