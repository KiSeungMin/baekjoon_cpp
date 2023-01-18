#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

int main(){

    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin>>N>>K;

    vector<pair<int, int>>input_arr;
    for(int i{0}; i < N; i++){
        int weight, value;
        cin>>weight>>value;

        pair<int, int>input_pair = {weight, value};
        input_arr.push_back(input_pair);
    }

    int answer = 0;
    vector<int>value_arr(K + 1, 0);
    for(int i{0}; i < N; i++){

        int weight{input_arr[i].first};
        int value{input_arr[i].second};

        for(int j{K - weight}; j >= 0; j--){
            if(value_arr[j + weight] < value_arr[j] + value)
                value_arr[j + weight] = value_arr[j] + value;
        }
    }

    for(auto i : value_arr){
        if(i > answer)
            answer = i;
    }

    cout<<answer<<"\n";

    return 0;
}