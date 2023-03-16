#include<iostream>
#include<vector>
#include<algorithm>
#define sync_with_stdio(false)
using namespace std;

int N;
int answer1, answer2;
int result = 2000000010;
vector<int>input_arr;

void getInput(){

    cin >> N;

    for(int i{0}; i < N; i++){
        int num; cin >> num;
        input_arr.push_back(num);
    }

    sort(input_arr.begin(), input_arr.end());
}

void getAnswer(){

    int start = 0;
    int end = N - 1;
    int num1 = input_arr[start];
    int num2 = input_arr[end];

    while(start < end){

        if(abs(num1 + num2) < result){
            result = abs(num1 + num2);
            answer1 = num1;
            answer2 = num2;
        }

        if(abs(num1) > abs(num2)){
            start++;
            num1 = input_arr[start];
        } else if(abs(num1) < abs(num2)){
            end--;
            num2 = input_arr[end];
        } else{
            return;
        }
    }
}

int main(){

    getInput();

    getAnswer();

    cout<<answer1<<" "<<answer2<<"\n";

    return 0;
}