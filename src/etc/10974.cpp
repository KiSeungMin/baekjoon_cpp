#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

int N;
vector<bool>checked;
vector<int>arr;
vector<int>result;

void getAnswer(int len){

    if(len == N){
        for(auto num : result){
            cout<<num<<" ";
        }
        cout<<"\n";

        return;
    }

    for(int i{1}; i <= N; i++){
        if(checked[i - 1])
            continue;

        else{
            result.push_back(i);
            checked[i - 1] = true;
            getAnswer(len + 1);
            result.pop_back();
            checked[i - 1] = false;
        }
    }
}

int main(){

    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i{1}; i <= N; i++){
        arr.push_back(i);
        checked.push_back(false);
    }

    getAnswer(0);

    return 0;
}