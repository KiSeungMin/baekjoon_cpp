#include<iostream>
#include<vector>
using namespace std;

bool endSignal1=false;
bool endSignal2=false;
const int limit=9;
vector<vector<short>>sudoku;

void getAnswer(int row, int col, vector<vector<short>> sudokuCopy);

int main(){

    for(int i{0}; i<limit; i++){

        vector<short>tmp={};

        for(int j{0}; j<limit; j++){
            
            short num;
            cin>>num;

            tmp.push_back(num);
        }
        sudoku.push_back(tmp);
    }

    int row=0;
    int col=0;

    // find 0
    while(row<limit && col < limit && sudoku[row][col] > 0){

        col++;
        if(col == limit){
            row+=1;
            col=0;
        }
    }

    // if board has not 0
    if(row == limit){
        for(int i{0}; i<limit; i++){

            for(int j{0}; j<limit; j++){

                cout<<sudoku[i][j]<<" ";
            }
            cout<<endl;
        }
        return 0;
    }   

    cout<<endl;

    //getAnswer
    getAnswer(row, col, sudoku);

    // print sudoku
    for(int i{0}; i<limit; i++){

        for(int j{0}; j<limit; j++){
            cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

void getAnswer(int row, int col, vector<vector<short>> sudokuCopy){

    // check answer has find
    if(endSignal2 == true)
        return;

    // check the number can use
    vector<bool>possible(limit, true);

    //check row
    for(int i{0}; i<limit; i++){

        if(sudokuCopy[row][i] > 0)
            possible[sudokuCopy[row][i]-1]=false;
    }

    //check col
    for(int i{0}; i<limit; i++){

        if(sudokuCopy[i][col] > 0)
            possible[sudokuCopy[i][col]-1]=false;
    }

    //check box
    int rowIndex=row/3;
    int colIndex=col/3;

    rowIndex=rowIndex*3;
    colIndex=colIndex*3;

    for(int i{rowIndex}; i<rowIndex+3; i++){

        for(int j{colIndex}; j<colIndex+3;j++){

            if(sudokuCopy[i][j] > 0)
                possible[sudokuCopy[i][j]-1]=false;
        }
    }

    for(int i{0}; i<limit; i++){

        if(possible[i]){

            sudokuCopy[row][col]=i+1;

            int rowTmp=row;
            int colTmp=col;

            // find next 0
            while(rowTmp < limit && colTmp < limit && sudokuCopy[rowTmp][colTmp] > 0){
                colTmp++;
                if(colTmp==limit){
                    rowTmp++;
                    colTmp=0;
                }
            }

            // end to find answer
            if(rowTmp==limit){
                
                sudoku=sudokuCopy;
                if(endSignal1==false){
                    endSignal1=!endSignal1;
                    endSignal2=!endSignal2;
                }
                return;
            }

            else{
                getAnswer(rowTmp, colTmp, sudokuCopy);
            }
        }
    }
    return;
}
