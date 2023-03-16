#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

void getIncrease(vector<int>& input_arr, vector<int>& increase_arr);
void getDecrease(vector<int>& input_arr, vector<int>& decrease_arr);

int N;

int main(){

    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    vector<int>input_arr(N, 0);
    for(int i{0}; i < N; i++)
        cin>>input_arr[i];

    vector<int>increase_arr(N, 0);
    vector<int>decrease_arr(N, 0);

    getIncrease(input_arr, increase_arr);
    getDecrease(input_arr, decrease_arr);

    int answer = 0;
    for(int i{0}; i < N; i++){

        int result = increase_arr[i] + decrease_arr[i] - 1;

        if(result > answer)
            answer = result;
    }

    cout<<answer<<"\n";

    return 0;
}

void getIncrease(vector<int>& input_arr, vector<int>& increase_arr){

    for(int i{0}; i < N; i++){

        int result = 0;

        for(int j{0}; j < i; j++){
            if(input_arr[j] < input_arr[i] && increase_arr[j] > result)
                result = increase_arr[j];
        }            

        increase_arr[i] = ++result;
    }

}

void getDecrease(vector<int>& input_arr, vector<int>& decrease_arr){

    for(int i{N - 1}; i >= 0; i--){

        int result = 0;

        for(int j{N - 1}; j > i; j--){

            if(input_arr[j] < input_arr[i] && decrease_arr[j] > result)
                result = decrease_arr[j];
        }

        decrease_arr[i] = ++result;
    }
}