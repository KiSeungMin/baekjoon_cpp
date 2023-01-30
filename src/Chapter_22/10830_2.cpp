#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

int N;

vector<vector<int>> getMatrixDiv(vector<vector<int>>&matrix1, vector<vector<int>>& matrix2){
    vector<int>row(N, 0);
    vector<vector<int>>result_matrix(N, row);

    for(int i{0}; i < N; i++){
        for(int j{0}; j < N; j++){
            int result = 0;
            for(int k{0}; k < N; k++){
                result += matrix1[i][k] * matrix2[k][j];
            }
            result = result % 1000;
            result_matrix[i][j] = result;
        }
    }

    return result_matrix;
}

vector<vector<int>> getResult(vector<vector<int>>&matrix, long long exp){

    if(exp == 1)
        return matrix;

    vector<vector<int>> tmp_matrix = getResult(matrix, exp / 2);
    vector<vector<int>> result_matrix = getMatrixDiv(tmp_matrix, tmp_matrix);

    if(exp % 2 == 0)
        return result_matrix;

    else
        return getMatrixDiv(result_matrix, matrix);
}

void printVector(vector<vector<int>>& vec){

    for(int i{0}; i < vec.size(); i++){
        for(int j{0}; j <vec[i].size(); j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){

    cin.tie(NULL); cout.tie(NULL);

    long long B; cin>>N>>B;

    vector<vector<int>>input_matrix;
    for(int i{0}; i < N; i++){
        vector<int>row(N, 0);
        for(int j{0}; j < N; j++){
            cin>>row[j];
            row[j] %= 1000;
        }
        input_matrix.push_back(row);
    }

    vector<vector<int>>result_matrix;
    result_matrix = getResult(input_matrix, B);

    printVector(result_matrix);

    return 0;
}