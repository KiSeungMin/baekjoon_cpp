#include<iostream>
#include<vector>
using namespace std;

int main(){

    int T;
    cin>>T;

    int N=30;

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
                arr[i].push_back(arr[i-1][j-1] + arr[i-1][j]);
                continue;
            }

            else if(j==i)
                arr[i].push_back(1);
            
        }
    }

    for(int i{0}; i < T; i++){
        int num1, num2;
        cin>>num1>>num2;

        cout<<arr[num2][num1]<<endl;
    }

    return 0;
}
