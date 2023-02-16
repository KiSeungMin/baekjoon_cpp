#include<iostream>
#include<vector>
using namespace std;

int N, row, col;

int getAnswer(int num_start, int num_end, int row_start, int row_end, int col_start, int col_end){
    if(num_start == num_end)
        return num_start;

    int size = (num_end - num_start + 1) / 4;
    int row_center = (row_start + row_end) / 2;
    int col_center = (col_start + col_end) / 2;

    if(row <= row_center){

        if(col <= col_center){
            return getAnswer(num_start, num_start + size - 1, row_start, row_center, col_start, col_center);
        }
        else if(col > col_center){
            return getAnswer(num_start + size, num_start + size * 2 - 1, col_center + 1, col_end, row_start, row_center);
        }
    }

    else if(row > row_center){
        
        if(col <= col_center){
            return getAnswer(num_start + size * 2, num_start + size * 3 - 1, row_center + 1, row_end, col_start, col_center);
        }
        else if(col > col_center){
            return getAnswer(num_start + size * 3, num_start + size * 4 - 1, row_center + 1, row_end, col_center + 1, col_end);
        }
    }

    return 0;
}

int getNum(int num, int repeat){
    int result = 1;

    for(int i{1}; i <= repeat; i++){
        result *= num;
    }
    
    return result;
}

int main(){
    cin >> N >> row >> col;
    
    cout<<getAnswer(0, getNum(4, N) - 1, 0, getNum(2, N) - 1, 0, getNum(2, N) - 1);
}