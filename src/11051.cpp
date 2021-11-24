#include<iostream>
#include<vector>
using namespace std;

// nCk = n-1Ck-1 + n-1Ck

int main(){

    int N, K;
    cin>>N>>K;

    vector<vector<int>>arr(N+1);
    
    for(int i{0}; i < N + 1; i++){
        arr[i].push_back(1);
        arr[i].push_back(i);
    }  

    for(int i{1}; i < N +1; i++){

        for(int j{0}; j <= i; j++){

            if(j==0){
                arr[i][j]=1;
                continue;
            }

            else if(j==1){
                arr[i][j]=i;
                continue;
            }

            else if(j < i){
                arr[i].push_back((arr[i-1][j-1] + arr[i-1][j]) % 10007);
                continue;
            }

            else if(j==i)
                arr[i].push_back(1);
        }
    }

    cout<<arr[N][K]<<endl;

    return 0;
}


