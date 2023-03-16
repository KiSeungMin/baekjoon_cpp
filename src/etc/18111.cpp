#include<iostream>
#include<vector>
using namespace std;

int row, col, rest, sum{0};
int min_height{257}, max_height{-1};
long long answer{200000000000}, answer_avg;
vector<vector<int>>input_arr;

void getInput(){
    cin >> row >> col >> rest;

    for(int i{0}; i < row; i++){
        vector<int>tmp(col , 0);
        for(int j{0}; j < col; j++){
            int num; cin >> num;
            sum += num;
            if(num < min_height)
                min_height = num;

            if(num > max_height)
                max_height = num;

            tmp[j] = num;
        }
        input_arr.push_back(tmp);
    }
}

void getAnswer(int avg){

    long long result = 0;

    for(int i{0}; i < row; i++){
        for(int j{0}; j < col; j++){
            int num = input_arr[i][j];

            if(num < avg){
                result += (avg - num);
            } else if(num > avg){
                result += (num - avg) * 2;
            }
        }
    }

    if(result <= answer){
        answer = result;
        answer_avg = avg;
    }
}

int main(){
    getInput();

    for(int height{min_height}; height <= max_height; height++){

        if(sum + rest >= height * row * col)
            getAnswer(height);

        else
            break;
    }

    cout<<answer<<" "<<answer_avg<<"\n";

    return 0;
}