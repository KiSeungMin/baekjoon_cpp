#include<iostream>
#include<set>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

int main(){

    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin>>N>>M;

    set<string> input_set;
    for(int i{0}; i < N; i++){
        string input_str;
        cin>>input_str;

        input_set.insert(input_str);
    }

    int answer = 0;
    vector<string>result_arr;

    for(int i{0}; i < M; i++){
        string input_str;
        cin>>input_str;

        if(input_set.find(input_str) != input_set.end()){
            answer++;
            result_arr.push_back(input_str);
        }
    }

    cout<<answer<<"\n";
    for(string str : result_arr)
        cout<<str<<"\n";

    return 0;
}