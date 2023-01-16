#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

void getAnswer(vector<int>arr, int index);

int limit, length;

int main(){

    cin.tie(NULL);
    cout.tie(NULL);

    cin>>limit>>length;

    vector<int>arr(length, 0);
    for(int i{1}; i <= limit; i++){
        arr[0] = i;
        getAnswer(arr, 1);
    }

    return 0;
}

void getAnswer(vector<int>arr, int index){

    if(index == length){
        for(auto i : arr)
            cout<<i<<" ";
        cout<<"\n";

        return;
    }

    for(int i{arr[index - 1] + 1}; i <= limit; i++){
        arr[index] = i;
        getAnswer(arr, index + 1);
    }
}