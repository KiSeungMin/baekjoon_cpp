#include<iostream>
#include<vector>
using namespace std;

int N; 
long long T;
vector<long long>arr1;
vector<long long>arr2;

int main(){

    cin >> T;
    cin >> N;

    for(int i{0}; i < N; i++){
        long long num; cin >> num;

        if(i == 0){
            arr1.push_back(num);
            continue;
        }
            
        arr1.push_back(num + arr1[arr1.size() - 1]);
    }

    for(int i{0}; i < N; i++){
        long long num; cin >> num;

        if(i == 0){
            arr2.push_back(num);
            continue;
        }

        arr2.push_back(num + arr2[arr2.size() - 1]);
    }

    

    return 0;
}