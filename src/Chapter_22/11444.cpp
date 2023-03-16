#include<iostream>
#include<vector>
using namespace std;

const int mod = 1000000007;
long long N;

vector<vector<long long>> getMatrix(vector<vector<long long>>arr1, vector<vector<long long>> arr2);

 int main(){

    cin>>N;

    if(N==0){
        cout<<0<<endl;
        return 0;
    }

    vector<long long>powNow;
    long long pow =1;
    while(pow <= N){
        powNow.push_back(pow);
        pow*=2;
    }

    vector<vector<long long>> arr = {{0, 1}, {1, 1}};
    vector<vector<vector<long long>>> board;

    for(int i{0}; i < powNow.size(); i++){
        board.push_back(arr);
        arr = getMatrix(arr, arr);
    }

    vector<vector<long long>>answer = {{1, 0}, {0, 1}};

    if(N % 2 ==1){
        answer = {{0, 1}, {1, 1}};
        N-=1;
    }

    for(size_t i{powNow.size()-1}; i >=1; i--){

        if(powNow[i] <= N){
            answer = getMatrix(answer, board[i]);
            N -= powNow[i];
        }
    }

    vector<vector<long long>>tmp={{0}, {1}};
    answer = getMatrix(answer, tmp);

    cout<<answer[0][0];

     return 0;
 }


 vector<vector<long long>> getMatrix(vector<vector<long long>>arr1, vector<vector<long long>> arr2){

     vector<long long>tmp (arr2[0].size(), 0);
     vector<vector<long long>> res(arr2.size(), tmp);

    for(int row1{0}; row1 < arr1.size(); row1++){

        for(int col2{0}; col2 < arr2[0].size(); col2++){

            for(int i{0}; i < arr1[0].size(); i++){

                res[row1][col2] += (arr1[row1][i] * arr2[i][col2]) % mod;
                res[row1][col2] = res[row1][col2] % mod; 
            }
        }
    }

    return res;
 }
