#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

int N;
vector<vector<bool>>input_arr;

void init(){

    cin>>N;

    vector<bool>row(N + 1 , false);
    input_arr.push_back(row);

    for(int i{0}; i < N; i++){

        string input_str;
        cin>>input_str;

        for(int j{0}; j <= N; j++){
            row[j + 1] = (input_str[j] == '1');
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

    cout<<(flag == true ? 1 : 0);

    return true;
}

void getAnswer(int rowStart, int rowEnd, int colStart, int colEnd){

    if(checkTile(rowStart, rowEnd, colStart, colEnd))
        return;

    cout<<"(";

    int rowCenter = (rowStart + rowEnd) / 2;
    int colCenter = (colStart + colEnd) / 2;

    getAnswer(rowStart, rowCenter, colStart, colCenter);
    getAnswer(rowStart, rowCenter, colCenter + 1, colEnd);
    getAnswer(rowCenter + 1, rowEnd, colStart, colCenter);
    getAnswer(rowCenter + 1, rowEnd, colCenter + 1, colEnd);

    cout<<")";
}

int main(){

    cin.tie(NULL); cout.tie(NULL);

    init();

    getAnswer(1, N, 1, N);

    return 0;
}