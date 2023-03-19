#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int start, goal;

int getAnswer(int round, queue<int> que){

    if(que.empty()){
        return -1;
    }

    queue<int>next_que;

    while(!que.empty()){
        int num_now = que.front(); que.pop();
        int next_num = num_now * 2;

        if(next_num == goal){
            return round + 1;
        } else if(next_num < goal){
            //check[next_num] = true;
            next_que.push(next_num);
            /*
            if(check[next_num] == false){
                check[next_num] = true;
                next_que.push(next_num);
            }
            */
        }

        next_num = num_now * 10 + 1;
        if(next_num == goal){
            return round + 1;
        } else if(next_num < goal){
            /*
            if(check[next_num] == false){
                check[next_num] = true;
                next_que.push(next_num);
            }
            */
            //check[next_num] = true;
            next_que.push(next_num);
        }
    }

    //return getAnswer(round + 1, next_que, check);
    return getAnswer(round + 1, next_que);
}

int main(){

    cin >> start >> goal;
    //vector<bool>check(goal / 2 + 1, false);
    queue<int> q;
    q.push(start);

    //cout<<getAnswer(1, q, check)<<endl;
    cout<<getAnswer(1, q)<<endl;

    return 0;
}