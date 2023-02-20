#include<iostream>
#include<vector>
using namespace std;

int getMax(int a, int b, int c){

    int max = 0;

    if(a > max)
        max = a;

    if(b > max)
        max = b;

    if(c > max)
        max = c;

    return max;
}

void getAnswer(int N, vector<vector<int>>&board){

    if(N == 1){
        cout<<getMax(board[0][0], board[1][0], 0)<<"\n";
        return;
    }

    board[0][1] += board[1][0];
    board[1][1] += board[0][0];

    if(N == 2){
        cout<<getMax(board[0][1], board[1][1], 0)<<"\n";
        return;
    }

    int answer = 0;

    for(int i{2}; i < N; i++){

        board[0][i] += getMax(board[1][i - 1], board[0][i - 2], board[1][i - 2]);
        board[1][i] += getMax(board[0][i - 1], board[0][i - 2], board[1][i - 2]);

        answer = getMax(board[0][i], board[1][i], answer);
    }

    cout<<answer<<"\n";
}

void getInput(){

    int N; cin >> N;

    vector<vector<int>>input_arr;
    for(int i{0}; i < 2; i++){
        vector<int>tmp;
        for(int j{0}; j < N; j++){
            int num; cin >> num;
            tmp.push_back(num);
        }
        input_arr.push_back(tmp);
    }

    getAnswer(N, input_arr);
}

int main(){

    int T; cin >> T;
    for(int t{0}; t < T; t++){
        getInput();
    }

    return 0;
}