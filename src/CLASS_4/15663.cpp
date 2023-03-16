#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;

void getAnswer(vector<int>&result, vector<int>&numbers, vector<bool>&visited){

    if(result.size() == M){
        for(auto element : result){
            cout<<element<<" ";
        }
        cout<<"\n";
        return;
    }

    int before = -1;
    for(int i{0}; i < N; i++){

        if(numbers[i] == before || visited[i])
            continue;

        result.push_back(numbers[i]);
        visited[i] = true;
        getAnswer(result, numbers, visited);
        result.pop_back();
        visited[i] = false;
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

    vector<bool>visited(N, false);

    int before = -1;
    vector<int>result;
    for(int i{0}; i < N; i++){

        if(numbers[i] == before)
            continue;

        result.push_back(numbers[i]);
        visited[i] = true;
        getAnswer(result, numbers, visited);
        result.pop_back();
        visited[i] = false;
        before = numbers[i];
    }

    return 0;
}