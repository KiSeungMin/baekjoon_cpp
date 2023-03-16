#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;

void getAnswer(int index, vector<int>&result, vector<int>&numbers){

    if(result.size() == M){
        for(auto element : result){
            cout<<element<<" ";
        }
        cout<<"\n";
        return;
    }

    int before = -1;
    for(int i{index}; i < N; i++){

        if(numbers[i] == before)
            continue;

        result.push_back(numbers[i]);
        getAnswer(i, result, numbers);
        result.pop_back();
        before = numbers[i];
    }
}

int main(){

    cin >> N >> M;
    vector<int>numbers(N, 0);

    for(int i{0}; i < N; i++){
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());

    int before = -1;
    vector<int>result;
    for(int i{0}; i < N; i++){

        if(numbers[i] == before)
            continue;

        result.push_back(numbers[i]);
        getAnswer(i, result, numbers);
        result.pop_back();
        before = numbers[i];
    }

    return 0;
}