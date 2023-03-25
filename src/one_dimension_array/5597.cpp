#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

const int N = 28;
const int LIMIT = 30;

int main(){

    cin.tie(NULL);

    vector<bool> is_number_checked(LIMIT, false);

    for(int i{0}; i < N; i++){
        int num;
        cin>>num;

        is_number_checked[num - 1] = true;
    }

    for(int i{0}; i < LIMIT; i++){
        if(!is_number_checked[i])
            cout<<i+1<<"\n";
    }

    return 0;
}