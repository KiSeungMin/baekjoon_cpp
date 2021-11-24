#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int getMin(int a, int b);
int GCD(int a, int b);

int main(){

    int N;
    cin>>N;

    vector<int>arr;

    for(int i{0}; i < N; i++){
        int num;
        cin>>num;
        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());

    int gcd=arr[1]-arr[0];

    for(int i{1}; i < N; i++){
        
        for(int j{i-1}; j>=0; j--){
            gcd=getMin(GCD(arr[i] - arr[j], gcd), gcd);
        }
    }

    vector<int>answer;

    for(int i{2}; i <= sqrt(gcd); i++){

        if(gcd % i ==0){

            if(i == sqrt(gcd)){
                answer.push_back(i);
                continue;
            }

            answer.push_back(i);
            answer.push_back(gcd/i);
        }
    }

    answer.push_back(gcd);

    sort(answer.begin(), answer.end());

    for(auto v : answer)
        cout<<v<<" ";

    cout<<endl;

    return 0;
}

int getMin(int a, int b){

    if(a > b)
        return b;

    return a;
}

int GCD(int a, int b){

    if(b==0)
        return a;

    else
        return GCD(b, a % b);
}