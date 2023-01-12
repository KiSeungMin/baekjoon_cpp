#include<iostream>
#include<vector>
using namespace std;

int N;
vector<vector<int>>board;

int getMax(int a, int b);

int main(){

    int answer=0;

    cin>>N;
    vector<int>arr(N + 1, 0);

    for(int i{1}; i < N + 1; i++){
        int num;
        cin>>num;
        arr[i]=num;
    }

    vector<int>tmp(2, 0);

    for(int i{0}; i < N + 1; i++){
        board.push_back(tmp);
    }

    if(N==1){
        cout<<arr[1]<<endl;
        return 0;
    }

    // 첫 번째 열 : 이전 행의 두번째 열 값 + 현재 포도주
    // 두 번째 열 : 전전 행의 최대 열 + 현재 포도주

    board[0][0]=arr[0];
    board[0][1]=arr[0];
    board[1][0]=arr[1];
    board[1][1]=arr[1];

    for(int i{2}; i< N + 1; i++){
        
        board[i][0]=board[i-1][1]+arr[i];

        int res=0;
        for(int j{i-2}; j>=0; j--){
            res=getMax(res, board[j][0]);
            res=getMax(res, board[j][1]);
        }

        board[i][1]=res + arr[i];

        answer=getMax(answer, board[i][0]);
        answer=getMax(answer,board[i][1]);
    }

    cout<<answer<<endl;

    return 0;
}

int getMax(int a, int b){

    if(a > b)
        return a;

    return b;
}