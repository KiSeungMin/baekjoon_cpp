#include<iostream>
#include<vector>
using namespace std;

int N;
vector<vector<int>>board;

int compareSmall(int a, int b);

int main(){

    cin>>N;
    for(int i{0}; i<N; i++){
        
        vector<int>tmp={};

        for(int j{0}; j<3; j++){

            int number;
            cin>>number;

            tmp.push_back(number);
        }

        board.push_back(tmp);
    }

    for(int i{1}; i<N; i++){

        for(int j{0}; j<3; j++){

            switch(j){

                case 0:
                    board[i][j] += compareSmall(board[i-1][1], board[i-1][2]); 
                    break;

                case 1:
                    board[i][j] += compareSmall(board[i-1][0], board[i-1][2]); 
                    break;

                case 2:
                    board[i][j] += compareSmall(board[i-1][0], board[i-1][1]); 
                    break;
            }
        }
    }

    int answer=100000000;

    for(int i{0}; i<3; i++){
      
        if(board[N-1][i] < answer)
            answer=board[N-1][i];
    }

    cout<<answer<<endl;
    return 0;
}

int compareSmall(int a, int b){

    if( a >= b )
        return b;

    return a;
}

