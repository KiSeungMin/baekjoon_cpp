#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

int N;
int answer = 0;
vector<vector<int>>board;

bool checkIndex(int row, int col){
    if(row >= N || col >= N){
        return false;
    }

    if(board[row][col] == 1){
        return false;
    }

    return true;
}

void getAnswer(int row, int col, bool right, bool down){

    if(row == N - 1 && col == N - 1){
        answer++;
        return;
    }

    if(right){
        if(checkIndex(row, col + 1)){
            getAnswer(row, col + 1, true, false);
        }
    }

    if(down){
        if(checkIndex(row + 1, col)){
            getAnswer(row + 1, col , false, true);
        }
    }

    if(checkIndex(row + 1, col) && checkIndex(row, col + 1) && checkIndex(row + 1, col + 1)){
        getAnswer(row + 1, col + 1, true, true);
    }
}

int main(){

    cout.tie(NULL); cin.tie(NULL);
    cin >> N;

    for(int i{0}; i < N; i++){
        vector<int>tmp(N, 0);
        for(int j{0}; j < N; j++){
            cin >> tmp[j];
        }
        board.push_back(tmp);
    }

    getAnswer(0, 1, true, false);

    cout<<answer<<"\n";

    return 0;
}