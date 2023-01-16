#include<iostream>
#include<vector>
#define sync_with_stdio(false);
using namespace std;

bool checkEnd = false;
const int LIMIT = 9;
vector<vector<short>>answer;

void getAnswer(vector<vector<short>>board, int row, int col);
void checkBox(vector<vector<short>>&board, vector<bool>& checkPossibleNumbers, int row, int col);
void checkRow(vector<vector<short>>&board, vector<bool>& checkPossibleNumbers, int row, int col);
void checkCol(vector<vector<short>>&board, vector<bool>& checkPossibleNumbers, int row, int col);
void printAnswer();

int main(){
    cin.tie(NULL);
    cout.tie(NULL);

    vector<short>row(LIMIT, 0);
    vector<vector<short>>board(LIMIT, row);

    for(int i{0}; i < LIMIT; i++){
        for(int j{0}; j < LIMIT; j++){
            cin>>board[i][j];
        }
    }

    getAnswer(board, 0, 0);

    printAnswer();

    return 0;
}

void getAnswer(vector<vector<short>>board, int row, int col){

    if(checkEnd == true)
        return;

    if(row == LIMIT){
        answer = board;
        checkEnd = true;
        return;
    }

    if(board[row][col] != 0){
        if(++col == LIMIT){
            ++row;
            col = 0;
        }
        getAnswer(board, row, col);
    }

    else{
        vector<bool> checkPossibleNumbers(LIMIT, true);
        checkBox(board, checkPossibleNumbers, row, col);
        checkRow(board, checkPossibleNumbers, row, col);
        checkCol(board, checkPossibleNumbers, row, col);

        for(int i{0}; i < LIMIT; i++){
            if(checkPossibleNumbers[i] == true){

                board[row][col] = i + 1;

                if(col + 1 == LIMIT)
                    getAnswer(board, row + 1, 0);
                else
                    getAnswer(board, row, col + 1);
            }
        }
    }
}

void checkBox(vector<vector<short>>&board, vector<bool>& checkPossibleNumbers, int row, int col){
    int rowBox = row / 3;
    rowBox = rowBox * 3;
    int colBox = col / 3;
    colBox = colBox * 3;

    int num = 0;

    for(int i{rowBox}; i < rowBox + 3; i++){
        for(int j{colBox}; j < colBox + 3; j++){
            num = board[i][j];

            if(num != 0)
                checkPossibleNumbers[num - 1] = false;
        }
    }
}


void checkRow(vector<vector<short>>&board, vector<bool>& checkPossibleNumbers, int row, int col){

    for(int i{0}; i < LIMIT; i++){
        int num = board[row][i];

        if(num != 0)
            checkPossibleNumbers[num - 1] = false;
    }
}

void checkCol(vector<vector<short>>&board, vector<bool>& checkPossibleNumbers, int row, int col){

    for(int i{0}; i < LIMIT; i++){
        int num = board[i][col];

        if(num != 0)
            checkPossibleNumbers[num - 1] =false;
    }
}

void printAnswer(){
    for(int i{0}; i < LIMIT; i++){
        for(int j{0}; j < LIMIT; j++){
            cout<<answer[i][j]<<" ";
        }
        cout<<"\n";
    }
}
