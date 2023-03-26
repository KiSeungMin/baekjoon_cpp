#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#define sync_with_stdio(false)
using namespace std;

int main(){

    cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    vector<int>arr;
    vector<int>board(1000001, 0);
    for(int i{0}; i < N; i++){
        int num; cin >> num;
        arr.push_back(num);
        board[num]++;
    }

    //stack<pair<int, int>> s;
    priority_queue<pair<int, int>>pq;
    vector<int>answer(N, -1);
    for(int i{0}; i < N; i++){
        
        int num_now = arr[i];
        int value_now = board[num_now];
        int index_now = i;

        if(!pq.empty()){

            while(!pq.empty()){
                int top_value = -1 * pq.top().first;
                int top_index = pq.top().second;

                if(value_now > top_value){
                    answer[top_index] = num_now;
                    pq.pop();
                }
                else{
                    break;
                }
            }
        }

        pq.push({-1 * value_now, index_now});
    }

    for(auto result : answer){
        cout<<result<<" ";
    }
    cout<<"\n";

    return 0;
}