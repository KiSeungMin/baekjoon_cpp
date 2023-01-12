#include<iostream>
#include<vector>
using namespace std;

int N;
vector<vector<int>>board;

int compare(int a, int b);

int main(){

    cin>>N;

    for(int i{0}; i<N; i++){
        
        vector<int>tmp;

        for(int j{0}; j<i+1; j++){

            int num;
            cin>>num;

            tmp.push_back(num);
        }

        board.push_back(tmp);
    }

    for(int i{N-2}; i>=0; i--){

        for(int j{0}; j < i+1; j++){

            board[i][j] += compare(board[i+1][j], board[i+1][j+1]);
        }
    }

    cout<<board[0][0]<<endl;

    return 0;
}

int compare(int a, int b){

    if(a >= b)
        return a;

    return b;   
}
