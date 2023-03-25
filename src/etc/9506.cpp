#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printAnswer(int num){

    int result = 1;
    vector<int>result_arr;

    for(int i{2}; i * i <= num; i++){
        if(num % i == 0){
            result += i;
            result +=(num / i);

            result_arr.push_back(i);
            result_arr.push_back(num / i);
        }
    }

    if(result == num){
        sort(result_arr.begin(), result_arr.end());
        cout<<num<<" = 1";
        for(auto num : result_arr){
            cout<<" + "<<num;
        }
    }

    else{
        cout<<num<<" is NOT perfect.";
    }

    cout<<endl;
}

int main(){

    int N; cin >> N;
    while(N != -1){

        printAnswer(N);        
        cin >> N;
    }
}