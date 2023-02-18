#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

int answer = 0;
int row, col;
vector<vector<int>>board;

void getInput(){

    cin >> row >> col;

    for(int i{0}; i < row; i++){
        vector<int>tmp(col, 0);
        for(int j{0}; j < col; j++){
            cin >> tmp[j];
        }
        board.push_back(tmp);
    }
}

bool checkIndex(int row_now, int col_now, int row_before, int col_before){

    if(row_now == row_before && col_now == col_before)
        return false;

    if(row_now >= 0 && row_now < row){
        if(col_now >= 0 && col_now < col)
            return true;
    }

    return false;
}

void getAnswer(int row_now, int col_now, int row_before, int col_before, int count, int result){

    result += board[row_now][col_now];

    if(count == 3){
        if(result > answer)
            answer = result;

        return;
    }

    int row_next = row_now - 1;
    int col_next = col_now;

    if(checkIndex(row_next, col_next, row_before, col_before))
        getAnswer(row_next, col_next, row_now, col_now, count + 1, result);

    row_next = row_now;
    col_next = col_now - 1;

    if(checkIndex(row_next, col_next, row_before, col_before))
        getAnswer(row_next, col_next, row_now, col_now, count + 1, result);

    row_next = row_now;
    col_next = col_now + 1;

    if(checkIndex(row_next, col_next, row_before, col_before))
        getAnswer(row_next, col_next, row_now, col_now, count + 1, result);

    row_next = row_now + 1;
    col_next = col_now;

    if(checkIndex(row_next, col_next, row_before, col_before))
        getAnswer(row_next, col_next, row_now, col_now, count + 1, result);

    if(count == 0){

        int resultCopy = result;

        if(col_now > 0 && col_now < col - 1){
            
            resultCopy += board[row_now][col_now - 1];
            resultCopy += board[row_now][col_now + 1];
            if(row_now > 0){
                resultCopy += board[row_now - 1][col_now];
                if(resultCopy > answer)
                    answer = resultCopy;

                resultCopy -= board[row_now -1 ][col_now];
            }

            if(row_now < row - 1){
                resultCopy += board[row_now + 1][col_now];
                if(resultCopy > answer)
                    answer = resultCopy;
            }
        }

        resultCopy = result;

        if(row_now > 0 && row_now < row - 1){
            
            resultCopy += board[row_now - 1][col_now];
            resultCopy += board[row_now + 1][col_now];

            if(col_now > 0){
                resultCopy += board[row_now][col_now - 1];
                if(resultCopy > answer)
                    answer = resultCopy;

                resultCopy -= board[row_now][col_now - 1];
            }

            if(col_now < col - 1){
                resultCopy += board[row_now][col_now + 1];
                if(resultCopy > answer)
                    answer = resultCopy;
            }
        }
    }
}

int main(){

    getInput();

    for(int i{0}; i < row; i++){
        for(int j{0}; j < col; j++){
            getAnswer(i, j, -1, -1, 0, 0);
        }
    }

    cout<<answer<<"\n";

    return 0;
}