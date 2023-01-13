#include<iostream>
#include<map>
#define sync_with_stdio(false)
using namespace std;

int main(){

    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin>>N>>M;

    map<string, int>find_by_name;
    map<int, string>find_by_index;

    for(int i{1}; i <= N; i++){
        string input_str;
        cin>>input_str;
        int index{i};

        find_by_name.insert({input_str, index});
        find_by_index.insert({index, input_str});
    }

    for(int i{0}; i < M; i++){
        string name;
        cin>>name;

        if(name[0] - '0' >= 0 && name[0] - '0' <= 9){
            int index = stoi(name);
            cout<<find_by_index[index]<<"\n";

            continue;
        }

        cout<<find_by_name[name]<<"\n";
    }
}