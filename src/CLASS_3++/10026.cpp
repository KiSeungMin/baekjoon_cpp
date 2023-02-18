#include<iostream>
#include<vector>
using namespace std;

int N;

void DFS(int row, int col, vector<string>& input_strs, vector<vector<bool>>& isChecked){

    isChecked[row][col] = true;

    int next_row = row;
    int next_col = col - 1;

    if(next_col >= 0 && input_strs[row][col] == input_strs[next_row][next_col] && isChecked[next_row][next_col] == false){
        DFS(next_row, next_col, input_strs, isChecked);
    }

    next_row = row - 1;
    next_col = col;

    if(next_row >= 0 && input_strs[row][col] == input_strs[next_row][next_col] && isChecked[next_row][next_col] == false){
        DFS(next_row, next_col, input_strs, isChecked);
    }

    next_row = row + 1;
    next_col = col;
    if(next_row < N && input_strs[row][col] == input_strs[next_row][next_col] && isChecked[next_row][next_col] == false){
        
        DFS(next_row, next_col, input_strs, isChecked);
    }

    next_row = row;
    next_col = col + 1;

    if(next_col < N && input_strs[row][col] == input_strs[next_row][next_col] && isChecked[next_row][next_col] == false){
        DFS(next_row, next_col, input_strs, isChecked);
    }
}

int getAnswer(vector<string>&input_strs, vector<vector<bool>>& isChecked){

    int answer = 0;

    for(int i{0}; i < N; i++){
        for(int j{0}; j < N; j++){
            if(isChecked[i][j] == false){
                answer++;
                DFS(i, j, input_strs, isChecked);
            }
        }
    }

    return answer;
}

int main(){

    vector<string>input_strs;
    vector<string>input_strs_cpy;

    cin >> N;
    for(int i{0}; i < N; i++){
        string str;
        cin >> str;

        input_strs.push_back(str);
        input_strs_cpy.push_back(str);
    }

    for(int i{0}; i < N; i++){
        for(int j{0}; j < N; j++){
            if(input_strs_cpy[i][j] == 'G')
                input_strs_cpy[i][j] = 'R';
        }
    }
    
    vector<vector<bool>>is_checked;
    vector<vector<bool>>is_checked_cpy;
    for(int i{0}; i < N; i++){
        vector<bool>tmp(N, false);
        is_checked.push_back(tmp);
        is_checked_cpy.push_back(tmp);
    }

    cout<<getAnswer(input_strs, is_checked)<<" ";
    cout<<getAnswer(input_strs_cpy, is_checked_cpy)<<"\n";

    return 0;
}

