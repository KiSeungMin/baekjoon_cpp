#include<iostream>
#include<vector>
#define sync_with_stdio(NULL)
using namespace std;

const int LIMIT = 100;

int answer = 0;
int case_amount;
vector<vector<bool>>is_block_checked;
vector<vector<int>>input_arr;

void getInput(){

    cin>>case_amount;

    for(int i{0}; i < case_amount; i++){

        vector<int>temp_arr = {0, 0};
        cin>>temp_arr[0]>>temp_arr[1];

        input_arr.push_back(temp_arr);
    }

    
    for(int i{0}; i < LIMIT; i++){
        vector<bool>temp_arr(LIMIT, false);
        is_block_checked.push_back(temp_arr);
    }
}

void getAnswer(){
    
    for(int i{0}; i < case_amount; i++){
        
        int col_start = input_arr[i][0];
        int row_start = input_arr[i][1];

        for(int row{row_start}; row < row_start + 10; row++){
            for(int col{col_start}; col < col_start + 10; col++){
            
                if(is_block_checked[row][col] == false){
                    is_block_checked[row][col] = true;
                    answer++;
                }
            }
        }
    }
}

int main(){

    cin.tie(NULL);

    getInput();

    getAnswer();

    cout<<answer<<"\n";

    return 0;
}