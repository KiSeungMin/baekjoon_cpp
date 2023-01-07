#include<iostream>
using namespace std;

int main(){

    int cost_sum;
    cin>>cost_sum;

    int N; 
    cin>>N;

    int result_sum = 0;

    for(int i{0}; i < N; i++){
        int cost, amount;
        cin>>cost>>amount;

        int result = cost * amount;
        result_sum += result;
    }

    string result = cost_sum == result_sum ? "Yes" : "No";
    cout<<result<<"\n";

    return 0;
}