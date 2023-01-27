#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

int N;
int countTrue;
int countFalse;
vector<vector<bool>>input_arr;

void init(){

    cin>>N;

    vector<bool>row(N + 1 , false);
    input_arr.push_back(row);

    for(int i{0}; i < N; i++){
        for(int j{1}; j <= N; j++){
            int input_num;
            cin>>input_num;
            row[j] = (input_num == 1);
        }
        input_arr.push_back(row);
    }
}

bool checkTile(int rowStart, int rowEnd, int colStart, int colEnd){

    bool flag = input_arr[rowStart][colStart];

    for(int i{rowStart}; i <= rowEnd; i++){
        for(int j{colStart}; j <= colEnd; j++){
            if(input_arr[i][j] != flag)
                return false;
        }
    }

    if(flag == true)
        countTrue++;

    else
        countFalse++;

    return true;
}

void getAnswer(int rowStart, int rowEnd, int colStart, int colEnd){

    if(checkTile(rowStart, rowEnd, colStart, colEnd))
        return;

    int rowCenter = (rowStart + rowEnd) / 2;
    int colCenter = (colStart + colEnd) / 2;

    getAnswer(rowStart, rowCenter, colStart, colCenter);
    getAnswer(rowStart, rowCenter, colCenter + 1, colEnd);
    getAnswer(rowCenter + 1, rowEnd, colStart, colCenter);
    getAnswer(rowCenter + 1, rowEnd, colCenter + 1, colEnd);
}

int main(){

    cin.tie(NULL); cout.tie(NULL);

    init();

    getAnswer(1, N, 1, N);

    cout<<countFalse<<"\n"<<countTrue<<"\n";

    return 0;
}