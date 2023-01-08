#include<iostream>
#include<vector>
#define sync_with_stdio(NULL)
using namespace std;

int row, col;
vector<vector<int>>matrix1;
vector<vector<int>>matrix2;
vector<vector<int>>result_matrix;

void getInput(){

    cin>>row>>col;

    for(int i{0}; i < row; i++){

        vector<int>col_matrix;

        for(int j{0}; j < col; j++){

            int input_num;
            cin>>input_num;

            col_matrix.push_back(input_num);
        }

        matrix1.push_back(col_matrix);
    }

    for(int i{0}; i < row; i++){

        vector<int>col_matrix;

        for(int j{0}; j < col; j++){

            int input_num;
            cin>>input_num;

            col_matrix.push_back(input_num);
        }

        matrix2.push_back(col_matrix);
    }
}

void makeAnswer(){

    for(int i{0}; i < row; i++){
        vector<int>col_matrix(col, 0);
        result_matrix.push_back(col_matrix);    
    }

    for(int i{0}; i < row; i++){
        for(int j{0}; j < col; j++){
            result_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void printAnswer(){

    for(int i{0}; i < row; i++){
        for(int j{0}; j < col; j++){
            cout<<result_matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){

    cin.tie(NULL);

    getInput();

    makeAnswer();

    printAnswer();

    return 0;
}