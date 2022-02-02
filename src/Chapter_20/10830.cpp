#include<iostream>
#include<vector>
using namespace std;

int N;
long long B;
vector<vector<int>>matrix;
vector<vector<vector<int>>>board;

vector<vector<int>> getMatrix(vector<vector<int>> arr1, vector<vector<int>> arr2);

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>B;

    vector<vector<int>>tmp;
    for(int i{0}; i < 50; i++){
        board.push_back(tmp);
    }

    for(int i{0}; i < N ; i++){
        vector<int>tmp;
        for(int j{0}; j < N; j++){
            int num;
            cin>>num;
            tmp.push_back(num);
        }
        matrix.push_back(tmp);
    }

    board[0] = matrix;
    for(int i{1}; i < 50; i++){
        board[i] = getMatrix(board[i-1], board[i-1]);
    }

    vector<int>tmp2(N, 0);
    vector<vector<int>>arr(N, tmp2);

    for(int i{0}; i < N; i++){
        arr[i][i] = 1;
    }

    long long pow =1;
    vector<long long>powArr;

    for(int i{0}; i < 50; i++){
        powArr.push_back(pow);
        pow=pow*2;
    }

    for(int i{49}; i >= 0; i--){

        if(powArr[i] <= B){

            arr = getMatrix(arr, board[i]);
            B -= powArr[i];
        }
    }


    for(int i{0}; i < N; i++){
        
        for(int j{0}; j < N; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}

vector<vector<int>> getMatrix(vector<vector<int>> arr1, vector<vector<int>> arr2){

    vector<int>tmp(N, 0);
    vector<vector<int>>res(N, tmp);

    for(int row1{0}; row1 < N; row1++){

        for(int col2{0}; col2 < N; col2++){

            for(int i{0}; i < N; i++){

                res[row1][col2] += (arr1[row1][i] * arr2[i][col2]) % 1000;
                res[row1][col2] = res[row1][col2] % 1000; 
            }
        }
    }

    return res;
}