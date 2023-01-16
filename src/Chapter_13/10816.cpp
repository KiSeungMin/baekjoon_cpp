#include<iostream>
#include<vector>
#include<algorithm>
#define sync_with_stdio(false);
using namespace std;


int main(){

    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N;

    vector<int>arr(20000001, 0);

    for(int i{0}; i < N; i++){

        int num;
        cin>>num;
        arr[num + 10000000]++;
    }

    int M;
    cin>>M;

    vector<int>board;

    for(int i{0}; i < M; i++){

        int num;
        cin>>num;

        board.push_back(num);
    }

    for(int i{0}; i < M; i++){
        cout<<arr[board[i] + 10000000]<<" ";
    }

    cout<<"\n";

}

