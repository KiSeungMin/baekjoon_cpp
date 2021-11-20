#include<iostream>
#include<vector>
using namespace std;

int N;
const long long mod=1000000000;
vector<vector<long long>>board;

int main(){

    cin>>N;
    
    vector<long long>tmp(N, 0);
    board.push_back(tmp);

    tmp[0]=1;

    for(int i{0}; i<9; i++){
        board.push_back(tmp);
    }

    for(int col{0}; col < N - 1; col++){
        
        for(int row{0}; row<=9; row++){

            if(row==0)
                board[1][col+1]=(board[1][col+1] + board[row][col]) % mod;

            else if(row==9)
                board[8][col+1]=(board[8][col+1] + board[row][col]) % mod;

            else{
                board[row-1][col+1] =(board[row-1][col+1] + board[row][col]) % mod;
                board[row+1][col+1]=(board[row+1][col+1] + board[row][col]) % mod;
            }
        }
    }

    long long answer=0;

    for(int i{0}; i<=9; i++){
        answer=(answer + board[i][N-1]) % mod;
    }

    cout<<answer<<endl;

    return 0;
}