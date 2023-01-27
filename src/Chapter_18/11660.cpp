#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

int getResult(vector<vector<int>>&input_arr, int row1, int col1, int row2, int col2);

int main(){

    cin.tie(NULL); cout.tie(NULL);
    int N, M; cin>>N>>M;

    vector<int>row(N + 1, 0);
    vector<vector<int>>input_arr(N + 1, row);

    for(int i{1}; i <= N; i++){
        for(int j{1}; j <= N; j++){
            int input_num; cin>>input_num;
            input_arr[i][j] = input_arr[i][j - 1] + input_num;
        }
    }

    for(int i{0}; i < M; i++){
        int row1, col1, row2, col2;
        cin>>row1>>col1>>row2>>col2;

        cout<<getResult(input_arr, row1, col1, row2, col2)<<"\n";
    }

    return 0;
}

int getResult(vector<vector<int>>&input_arr, int row1, int col1, int row2, int col2){

    int result = 0;

    for(int row{row1}; row <= row2; row++){
        result += input_arr[row][col2] - input_arr[row][col1 - 1];
    }

    return result;
}