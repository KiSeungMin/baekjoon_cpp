#include<iostream>
#include<vector>
#define sync_with_stdio(NULL)
using namespace std;

const int ROW = 9;
const int COL = 9;

int max_value = -1;
int result_row = -1;
int result_col = -1;

void getInput(){

    for(int i{0}; i < ROW; i++){
        for(int j{0}; j < COL; j++){

            int input_num;
            cin>>input_num;

            if(input_num > max_value){
                max_value = input_num;

                result_row = i;
                result_col = j;
            }
        }
    }
}


void printAnswer(){

    cout<<max_value<<"\n"<<result_row + 1 << " " << result_col + 1 << "\n";
}

int main(){

    cin.tie(NULL);

    getInput();

    printAnswer();

    return 0;
}