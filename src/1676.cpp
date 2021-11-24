#include<iostream>
#include<vector>
using namespace std;

int main(){

    int N;
    cin>>N;

    vector<long long>arr(N+1, 0);

    arr[0]=1;
    arr[1]=1;

    int answer=0;

    for(int i{2}; i<=N; i++){
        arr[i]=(arr[i-1]*i);
        
        while(arr[i] % 10 ==0){
            arr[i]/=10;
            answer++;
        }

        arr[i]=arr[i] % 1000000;

        //cout<<i<<" : "<<arr[i]<<endl;
    }

    cout<<answer<<endl;

    return 0;
}