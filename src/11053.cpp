#include<iostream>
#include<vector>
using namespace std;

int main(){

    int N;
    cin>>N;

    vector<int>arr;

    for(int i{0}; i<N; i++){
        int num;
        cin>>num;

        arr.push_back(num);
    }

    vector<int>board(N, 1);

    int answer=1;

    for(int i{1}; i<N; i++){

        int res=0;

        for(int j{0}; j<i; j++){

            if(arr[j] < arr[i] && board[j] > res)
                res=board[j];
        }

        board[i] += res;

        if(board[i] > answer)
            answer=board[i];
    }

    cout<<answer<<endl;

    return 0;
}