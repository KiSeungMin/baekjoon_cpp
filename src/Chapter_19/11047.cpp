#include<iostream>
#include<vector>
using namespace std;

int main(){

    int N, maxValue;
    cin>>N>>maxValue;

    vector<int>arr;

    for(int i{0}; i < N; i++){

        int num;
        cin>>num;

        arr.push_back(num);
    }

    int answer=0;

    for(int i{N-1}; i>=0; i--){

        answer = answer + maxValue/arr[i];

        maxValue=maxValue % arr[i];
    }

    cout<<answer<<endl;

    return 0;
}