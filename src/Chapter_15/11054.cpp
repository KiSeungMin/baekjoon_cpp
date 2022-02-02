#include<iostream>
#include<vector>
using namespace std;

int main(){

    int N;
    cin>>N;

    vector<int>arr(N, 0);
    for(int i{0}; i<N; i++){
        int num;
        cin>>num;

        arr[i]=num;
    }

    vector<int>tmp(2, 1);
    vector<vector<int>>board;

    for(int i{0}; i<N; i++){
        board.push_back(tmp);
    }

    int answer=1;

    for(int i{0}; i < N; i++){

        int big=0;

        for(int j{0}; j < i; j++){

            if(arr[i] > arr[j] && board[j][0] > big)
                big=board[j][0];
        }

        board[i][0] += big;
    }

    for(int i{N-1}; i>=0; i--){
        
        int small=0;

        for(int j{N-1}; j > i; j--){

            if(arr[i] > arr[j] && board[j][1] > small)
                small=board[j][1];
        }

        board[i][1]+=small;

        if(board[i][0] + board[i][1] -1 > answer)
            answer=board[i][0]+board[i][1] -1;
    }

    cout<<answer<<endl;

    return 0;
}