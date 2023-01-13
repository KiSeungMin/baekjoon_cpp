#include<iostream>
#include<set>
#define sync_with_stdio(false)
using namespace std;

int main(){

    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin>>N>>M;

    int answer = N + M;

    set<int>input_set;
    for(int i{0}; i < N; i++){
        int input_num; cin>>input_num;
        input_set.insert(input_num);
    }

    for(int i{0}; i < M; i++){
        int compare_num; cin>>compare_num;
        if(input_set.find(compare_num) != input_set.end()){
            answer -= 2;
        }
    }

    cout<<answer<<"\n";

    return 0;
}