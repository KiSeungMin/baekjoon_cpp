#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int N;
    cin>>N;

    vector<long long>arr;

    for(int i{0}; i < N; i++){

        long long num;
        cin>>num;

        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());

    long long answer=arr[0];

    for(int i{1}; i < N; i++){

        arr[i] +=arr[i-1];
        answer+=arr[i]; 
    }

    cout<<answer<<endl;

    return 0;
}