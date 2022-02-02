#include<iostream>
#include<vector>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> matrix1;
    vector<vector<int>> matrix2;

    int row1, col1;
    int row2, col2;

    cin>>row1>>col1;

    for(int i{0}; i < row1; i++){
        vector<int>tmp;
        for(int j{0}; j < col1; j++){
            int num;
            cin>>num;
            tmp.push_back(num);
        }
        matrix1.push_back(tmp);
    }

    cin>>row2>>col2;

    for(int i{0}; i < row2; i++){
        vector<int>tmp;
        for(int j{0}; j < col2; j++){
            int num;
            cin>>num;
            tmp.push_back(num);
        }
        matrix2.push_back(tmp);
    }

    vector<vector<int>>answer;

    for(int i{0}; i < row1; i++){

        
        vector<int>tmp;

        for(int x{0}; x < col2; x++){

            int result=0;

            for(int j{0}; j < col1; j++){
                result += matrix1[i][j] * matrix2[j][x];
            }

            tmp.push_back(result);
        }

        answer.push_back(tmp);
    }

    for(int i{0}; i <answer.size(); i++){

        for(int j{0}; j < answer[i].size(); j++){

            cout<<answer[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}