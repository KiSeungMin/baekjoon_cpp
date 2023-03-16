#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<int>input_arr;

void getAnswer(int index, vector<int>& result_arr){

    if(result_arr.size() == M){
        for(auto i : result_arr){
            cout<<i<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i{index}; i < N; i++){
        result_arr.push_back(input_arr[i]);
        getAnswer(i, result_arr);
        result_arr.pop_back();
    }
}

int main(){

    cin >> N >> M;

    for(int i{0}; i < N; i++){
        int num; cin >> num;
        input_arr.push_back(num);
    }

    sort(input_arr.begin(), input_arr.end());

    for(int i{0}; i < N; i++){
        vector<int>tmp;
        tmp.push_back(input_arr[i]);
        getAnswer(i, tmp);
    }

    return 0;
}