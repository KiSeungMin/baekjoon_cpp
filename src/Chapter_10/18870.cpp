#include<iostream>
#include<vector>
#include<algorithm>
#define sync_with_stdio(false)
using namespace std;

bool compare(pair<int, int>& value1, pair<int, int>& value2){

    int num1 = value1.first;
    int num2 = value2.first;

    return num1 < num2;
}

int main(){

    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<pair<int, int>> input_arr;

    for(int i{0}; i < N; i++){
        pair<int, int> input_value;
        
        cin>>input_value.first;
        input_value.second = i;

        input_arr.push_back(input_value);
    }

    sort(input_arr.begin(), input_arr.end(), compare);

    vector<int>result(N, 0);
    int count = 0;

    for(int i{0}; i < N; i++){
        int value = input_arr[i].first;
        int index = input_arr[i].second;

        if(i > 0){
            if(value == input_arr[i - 1].first){
                result[index] = count;
            } else{
                count++;
                result[index] = count;
            }
        } else{
            result[index] = 0;
        }
    }

    for(int i{0}; i < N; i++){
        cout<<result[i]<<" ";
    }
    cout<<"\n";

    return 0;
}