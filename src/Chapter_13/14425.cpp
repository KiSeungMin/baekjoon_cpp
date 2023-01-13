#include<iostream>
#include<string>
#include<vector>
#include<set>
#define sync_with_stdio(false)
using namespace std;

int main(){

    cin.tie(NULL);

    int N, M;
    cin>>N>>M;

    set<string>input_set;
    vector<string>find_arr;

    for(int i{0}; i < N; i++){
        string input_str;
        cin>>input_str;
        input_set.insert(input_str);
    }

    int answer = 0;
    for(int i{0}; i < M; i++){
        string input_str;
        cin>>input_str;
        
        if(input_set.find(input_str) != input_set.end())
            answer++;
    }

    cout<<answer<<"\n";

    return 0;
}