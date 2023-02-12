#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int LIMIT = 100000;
int start, goal;

void BFS(queue<int>& q, vector<bool>&checked, int answer){

    queue<int>next_que;

    while(!q.empty()){
        int front = q.front(); q.pop();

        if(checked[front])
            continue;

        checked[front] = true;

        if(front == goal){
            cout<<answer<<"\n";
            return;
        }

        if(front < goal && front != 0){
            if(front * 2 <= LIMIT && checked[front * 2] == false){
                q.push(front * 2);
            }
        }

        if(front + 1 <= LIMIT && checked[front + 1] == false)
            next_que.push(front + 1);
        
        if(front - 1 >= 0 && checked[front - 1] == false)
            next_que.push(front - 1);
    }

    BFS(next_que, checked, answer + 1);
}

int main(){

    cin >> start >> goal;    

    queue<int>que;
    que.push(start);

    vector<bool>checked(LIMIT + 1, false);

    BFS(que, checked, 0);

    return 0;
}