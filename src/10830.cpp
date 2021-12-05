#include<iostream>
#include<vector>
using namespace std;

int main(){

    int N, B;

    cin>>N>>B;

    vector<vector<int>>matrix;

    for(int i{0}; i < N ; i++){
        vector<int>tmp;
        for(int j{0}; j < N; j++){
            int num;
            cin>>num;
            tmp.push_back(num);
        }
        matrix.push_back(tmp);
    }

    

    return 0;
}