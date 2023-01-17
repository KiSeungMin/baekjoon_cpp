#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

int getAnswer(int x, int y, int z);

const int LIMIT = 21;

vector<vector<vector<int>>>result_board;

int main(){

    cin.tie(NULL);
    cout.tie(NULL);

    vector<int>row(LIMIT, -1);
    vector<vector<int>>row_col(LIMIT, row);
    for(int i{0}; i < LIMIT; i++){
        result_board.push_back(row_col);
    }
    result_board[0][0][0] = 1;

    int input1{1}, input2{1}, input3{1};
    cin>>input1>>input2>>input3;

    while(input1 != -1 || input2 != -1 || input3 != -1){

        int result = getAnswer(input1, input2, input3);

        cout<<"w(" << input1 <<", "<<input2<<", "<<input3<<") = " << result <<"\n";

        cin>>input1>>input2>>input3;
    }

    return 0;
}

int getAnswer(int x, int y, int z){

    if(x <= 0 || y <= 0 || z <= 0)
        return 1;

    else if(x >= LIMIT || y >= LIMIT || z >= LIMIT)
        return getAnswer(LIMIT - 1, LIMIT - 1, LIMIT - 1);

    if(result_board[x][y][z] != -1)
        return result_board[x][y][z];

    int result;

    if(x < y && y < z){
        result = getAnswer(x, y, z - 1) + getAnswer(x, y - 1, z - 1) - getAnswer(x, y - 1, z);
        result_board[x][y][z] = result;
    }

    else{
        result = getAnswer(x - 1, y , z) + getAnswer(x - 1, y - 1, z) + getAnswer(x - 1, y, z - 1) - getAnswer(x - 1, y - 1, z - 1);
        result_board[x][y][z] = result;
    } 

    return result;
}