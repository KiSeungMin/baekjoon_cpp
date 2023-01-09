#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
#define sync_with_stdio(false)
using namespace std;

// 최빈값은 영어로 mode 이다.

int N;
int sum{0};
int count_mode{0};
vector<int>count_num_arr(8001, 0);
vector<int>input_arr;

void getInput(){

    cin>>N;

    for(int i{0}; i < N; i++){
        int input_num;
        cin>>input_num;

        input_arr.push_back(input_num);

        sum += input_num;
        count_num_arr[input_num + 4000] ++;
        
        if(count_num_arr[input_num + 4000] > count_mode){
            count_mode = count_num_arr[input_num + 4000];
        }
    }
}

int getMode(){

    int mode_value = 0;
    bool second_value_now = false;

    for(int i{0}; i < 8001; i++){

        if(count_num_arr[i] == count_mode){

            mode_value = i - 4000;

            if(second_value_now){
                return mode_value;
            }

            second_value_now = true;
        }
    }

    return mode_value;
}


int main(){

    cin.tie(NULL);

    getInput();

    sort(input_arr.begin(), input_arr.end());

    double average = round(sum / static_cast<double>(N));

    if(average == -0)
        average = 0;
    
    int median = input_arr[N / 2];

    int mode = getMode();

    int range = input_arr[N - 1] - input_arr[0];

    cout<<average<<"\n"<<median<<"\n"
    <<mode<<"\n"<<range<<"\n";

    return 0;
}