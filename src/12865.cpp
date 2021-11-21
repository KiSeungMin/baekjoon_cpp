#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int N, weight;

    cin>>N>>weight;

    vector<vector<double>>arr;

    for(int i{0}; i<N; i++){

        vector<double>tmp;

        double num1;
        double num2;

        cin>>num1>>num2;

        tmp.push_back(num2/num1);
        tmp.push_back(num1);
        tmp.push_back(num2);

        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());

    vector<pair<int, int>board;

    for(int i{0}; i < N; i++){

        for(int j{0}; j < i; j++){

            
        }
    }
   
    return 0;
}
