#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(int a, int b);

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    vector<int>board(1000001, 0);

    vector<int>arr;
    for(int i{0}; i < N; i++){
        int num;
        cin>>num;

        if(board[num] == 0){
            arr.push_back(num);
            board[num]=i;
        }
    }

    

    return 0;
}