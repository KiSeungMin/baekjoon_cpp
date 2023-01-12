#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int getMax(int a, int b);

int main(){

    int N;
    cin>>N;

    vector<int>arr;

    for(int i{0}; i < N; i++){
        
        int num;
        cin>>num;

        arr.push_back(num);
    }

    int answer=INT_MIN;

    vector<int>board(N, 0);
    board[0]=arr[0];

    for(int i{1}; i < N; i++){

        if(arr[i] + board[i-1] < 0){

            if(arr[i] > 0)
                board[i]=arr[i];
            
            else
                board[i]=0;
        }

        else
            board[i]=getMax(board[i-1] + arr[i], arr[i]);

        answer=getMax(answer, board[i]);
    }

    if(answer <= 0){

        answer=INT_MIN;

        for(int i{0}; i < N; i++){
            answer=getMax(answer, arr[i]);
        }
    }

    cout<<answer<<endl;

    return 0;
}

int getMax(int a, int b){

    if(a > b)
        return a;

    return b;
}