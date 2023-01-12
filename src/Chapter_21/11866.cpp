#include<iostream>
#include<queue>
#define sync_with_stdio(false)
using namespace std;

int main(){

    cout.tie(NULL);
    cin.tie(NULL);

    int N,K;
    cin>>N>>K;

    queue<int>que;

    cout<<"<";

    for(int i{1}; i <= N; i++){
        que.push(i);
    }

    while(que.size() > 0){

        for(int i{0}; i < K-1; i++){
            que.push(que.front());
            que.pop();
        }

        if(que.size() == N)
            cout<<que.front();

        else
            cout<<", "<<que.front();

        que.pop();
    }

    cout<<">"<<"\n";

    return 0;
}