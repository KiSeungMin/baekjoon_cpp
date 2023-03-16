#include<iostream>
#include<vector>
using namespace std;

const int LIMIT = 8;

int main(){

    vector<int>input_arr(LIMIT, 0);

    for(int i{0}; i < LIMIT; i++){
        cin>>input_arr[i];
    }

    bool ascending = true;
    bool descending = true;

    for(int i{0}; i < LIMIT; i++){

        if(input_arr[i] != i + 1){
            ascending = false;
        }

        if(input_arr[i] + i != LIMIT){
            descending = false;
        }
    }

    if(ascending)
        cout<<"ascending\n";

    else if(descending)
        cout<<"descending\n";

    else
        cout<<"mixed\n";

    return 0;
}