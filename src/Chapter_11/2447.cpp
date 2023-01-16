#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

int N;
vector<vector<bool>> result;

void recursion(int row_start,int row_end, int col_start, int col_end){

    // 박스 크기가 1이면 재귀함수 종료
    if(row_start == row_end || col_start == col_end)
        return;

    // gap : 현재 박스를 3등분한 크기
    int gap = (row_end - row_start + 1) / 3;

    // 빈칸(false)으로 칠할 행과 열
    int empty_row = row_start + gap;
    int empty_col = col_start + gap;

    for(int row{empty_row}; row < empty_row + gap; row++){
        for(int col{empty_col}; col < empty_col + gap; col++){
            result[col][row] = false;
        }
    }

    // 박스를 9등분하여 다음 재귀함수 진행
    for(int i{0}; i <= 2; i++){
        for(int j{0}; j <= 2; j++){
            int next_row = row_start + (gap * i);
            int next_col = col_start + (gap * j);
            recursion(next_row, next_row + gap - 1, next_col, next_col + gap - 1);
        }
    }
}

int main(){

    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    vector<bool>tmp(N + 1, true);

    for(int i{0}; i < N + 1; i++){
        result.push_back(tmp);
    }

    recursion(1, N, 1, N);

    for(int i{1}; i <= N; i++){
        for(int j{1}; j <= N; j++){
            cout<< (result[i][j] ? "*" : " ") ;
        }
        cout<<"\n";
    }
}