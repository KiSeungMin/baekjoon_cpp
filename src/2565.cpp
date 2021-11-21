#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int getMax(int a, int b);

int main(){

    vector<pair<int,int>>arr;

    int N;
    cin>>N;

    for(int i{0}; i<N; i++){
        
        int num1;
        int num2;

        cin>>num1>>num2;

        pair<int, int>tmp={num1, num2};

        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());

    int answer=0;

    vector<int>board(N, 1);

    for(int i{0}; i<N; i++){

        int res=0;

        for(int j{i-1}; j >= 0; j--){
             
            if(arr[i].second > arr[j].second){
                 res=getMax(res, board[j]);
            }
        }

        board[i] = board[i] + res;

        answer=getMax(answer, board[i]);
    }

    cout<<N - answer<<endl;

    return 0;
}

int getMax(int a, int b){

    if(a>b)
        return a;

    return b;
}