#include<iostream>
#include<queue>
using namespace std;

int main(){

    int N;
    cin>>N;

    queue<int>que;

    if(N%2 != 0){
        que.push(N);
    }

    for(int i{2}; i <= N; i=i+2){
        que.push(i);
    }

    while(que.size() > 1){
        que.pop();
        que.push(que.front());
        que.pop();
    }

    cout<<que.front()<<endl;

    return 0;
}