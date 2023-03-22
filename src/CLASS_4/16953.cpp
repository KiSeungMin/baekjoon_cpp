#include<iostream>
#include<vector>
#include<queue>
using namespace std;

long long start, goal;

int getAnswer(int round, queue<long long> que){

    if(que.empty()){
        return -1;
    }

    queue<long long>next_que;

    while(!que.empty()){
        long long num_now = que.front(); que.pop();
        long long next_num = num_now * 2;

        if(next_num == goal){
            return round + 1;
        } else if(next_num < goal){
            next_que.push(next_num);
        }

        next_num = num_now * 10 + 1;
        if(next_num == goal){
            return round + 1;
        } else if(next_num < goal){
            next_que.push(next_num);
        }
    }

    return getAnswer(round + 1, next_que);
}

int main(){

    cin >> start >> goal;
    queue<long long> q; q.push(start);

    cout<<getAnswer(1, q)<<endl;

    return 0;
}