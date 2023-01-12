#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int getMin(int a, int b);

int main(){

    int N;
    cin>>N;

    // N == INF -> ? , N == 1 -> 0 , N == 2 -> 1, N == 3 -> 2
    vector<int>result(N + 1, 0);
    result[1]=0;
    result[2]=1;
    result[3]=1;

    for(int i{4}; i <= N; i++){
        
        int answer=INT_MAX;
        
        if(i % 3 == 0)
            answer=getMin(answer, result[i/3]);

        if(i % 2 == 0)
            answer=getMin(answer, result[i/2]);

        answer=getMin(answer, result[i-1]);

        result[i]=answer + 1;
    }

    cout<<result[result.size()-1]<<endl;

    return 0;
}

int getMin(int a, int b){

    if(a < b)
        return a;

    return b;
}