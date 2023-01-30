#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

int N, M, K;
vector<vector<int>>matrix1;
vector<vector<int>>matrix2;
vector<vector<int>>result_matrix;

void getInput(){
    cin>>N>>M;

    vector<int>row1(M, 0);
    for(int i{0}; i < N; i++){
        for(int j{0}; j < M; j++){
            cin>>row1[j];
        }
        matrix1.push_back(row1);
    }

    cin>>M>>K;
    vector<int>row2(K, 0);
    for(int i{0}; i < M; i++){
        for(int j{0}; j < K; j++){
            cin>>row2[j];
        }
        matrix2.push_back(row2);
    }

    vector<int>row3(K, 0);
    for(int i{0}; i < N; i++){
        result_matrix.push_back(row3);
    }
}

void getResult(){
    for(int n{0}; n < N; n++){
        for(int k{0}; k < K; k++){
            for(int m{0}; m < M; m++){
                result_matrix[n][k] += matrix1[n][m] * matrix2[m][k];
            }
        }
    }
}

void printResult(){
    for(int n{0}; n < N; n++){
        for(int k{0}; k < K; k++){
            cout<<result_matrix[n][k]<<" ";
        }
        cout<<"\n";
    }
}

int main(){

    cin.tie(NULL); cout.tie(NULL);

    getInput();

    getResult();

    printResult();

    return 0;
}