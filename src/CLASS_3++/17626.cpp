#include<iostream>
#include<vector>
using namespace std;

int main(){

    int N; cin >> N;
    vector<int>answer_arr(N + 1, -1);
    
    vector<int>first;
    vector<int>second;

    for(int i{1}; i * i <= N; i++){
        answer_arr[i * i] =  1;
        first.push_back(i * i);
    }

    for(int i{0}; i < first.size(); i++){
        for(int j{0}; j < first.size(); j++){

            int num = first[i] + first[j];
            if(num <= N && answer_arr[num] == -1){
                answer_arr[num] = 2;
                second.push_back(num);
            }
        }
    }

    for(int i{0}; i < first.size(); i++){
        for(int j{0}; j < second.size(); j++){

            int num = first[i] + second[j];
            if(num <= N && answer_arr[num] == -1){
                answer_arr[num] = 3;
            }
        }
    }

    cout<<(answer_arr[N] == -1 ? 4 : answer_arr[N])<<"\n";

    return 0;
}