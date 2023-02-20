#include<iostream>
#include<map>
#define sync_with_stdio(false)
using namespace std;

int main(){

    cin.tie(NULL); cout.tie(NULL);

    int N, M; cin >> N >> M;
    map<string, string> input_map;

    for(int i{0}; i < N; i++){
        string key, password;
        cin >> key >> password;
        input_map.insert({key, password});
    }

    for(int i{0}; i < M; i++){
        string key; cin >> key;
        cout<<input_map[key]<<"\n";
    }

    return 0;
}