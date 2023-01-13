#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

const int LIMIT = 20000001;
const int gap = 10000000;

/*
    장부를 이용한 풀이
*/

int main(){

    cin.tie(NULL);
    cout.tie(NULL);

    vector<bool>is_num_present(LIMIT, false);
    
    int N; cin>>N;
    for(int i{0}; i < N; i++){
        int num; cin>>num;
        is_num_present[num + gap] = true;
    }

    int M; cin>>M;
    for(int i{0}; i < M; i++){
        int num; cin>>num;
        cout<<(is_num_present[num + gap] ? 1 : 0)<<" ";
    }

    return 0;
}