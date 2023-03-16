#include<iostream>
#include<vector>
#define sync_with_stdio(false);
using namespace std;

bool checkEnd = false;
const int LIMIT = 9;
vector<vector<short>>answer;

void getAnswer(vector<vector<short>>& board, int row, int col);
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

void getAnswer(vector<vector<short>>& board, int row, int col){

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

        // checkBox
        int rowBox = row / 3;
        rowBox = rowBox * 3;
        int colBox = col / 3;
        colBox = colBox * 3;

        for(int i{rowBox}; i < rowBox + 3; i++){
            for(int j{colBox}; j < colBox + 3; j++){
                int num = board[i][j];

                if(num != 0)
                    checkPossibleNumbers[num - 1] = false;
            }
        }

        // checkCol
        for(int i{0}; i < LIMIT; i++){
            int num = board[row][i];

            if(num != 0)
                checkPossibleNumbers[num - 1] = false;
        }

        // checkRow
        for(int i{0}; i < LIMIT; i++){
            int num = board[i][col];

            if(num != 0)
                checkPossibleNumbers[num - 1] =false;
        }   


        vector<vector<short>> boardCopy = board;

        for(int i{0}; i < LIMIT; i++){
            if(checkPossibleNumbers[i] == true){

                boardCopy[row][col] = i + 1;

                if(col + 1 == LIMIT)
                    getAnswer(boardCopy, row + 1, 0);
                else
                    getAnswer(boardCopy, row, col + 1);
            }
        }
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
