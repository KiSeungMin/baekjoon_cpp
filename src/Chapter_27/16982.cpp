#include<iostream>
#include<vector>
#include<queue>
#define sync_with_stdio(false)
using namespace std;

const int LIMIT = 100;

vector<int>result_arr;
vector<int>index_arr;

void getInput(){

    cin.tie(NULL); cout.tie(NULL);

    for(int i{0}; i <= LIMIT; i++){
        result_arr.push_back(0);
        index_arr.push_back(i);
    }

    int stair , snake; cin >> stair >> snake;

    for(int i{0}; i < stair + snake; i++){
        int start, end; cin >> start >> end;
        index_arr[start] = end;
    }
}

void BFS(int count, queue<int> q){

    queue<int>next_queue;

    while(!q.empty()){

        int front = q.front();
        q.pop();

        for(int i{1}; i <= 6; i++){
            int index = index_arr[front + i];

            if(index > LIMIT)
                continue;

            if(result_arr[index] == 0){

                if(index == LIMIT){
                    cout<<count<<"\n";
                    return;
                }

                result_arr[index] = count;
                next_queue.push(index);
            }
        }
    }

    BFS(count + 1, next_queue);
}

int main(){
    getInput();

    queue<int>q; q.push(1);
    BFS(1, q);
}