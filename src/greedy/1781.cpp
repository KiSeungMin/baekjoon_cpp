#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define sync_with_stdio(false)
using namespace std;

int N;
vector<long long>board;

int main(){

    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    priority_queue<pair<int, int>>pq;

    for(int i{0}; i < N; i++){
        int limit, value;
        cin >> limit >> value;

        pq.push({value, limit});
        board.push_back(0);
    }
    board.push_back(0);

    long long answer = 0;

   for(int i{0}; i < N; i++){
        long long value_now = pq.top().first;
        int limit_now = pq.top().second;
        pq.pop();

        for(int j{limit_now}; j >= 1; j--){
            if(value_now > board[j]){
                board[j] = value_now;
                break;
            }
        }
   }

    for(auto result : board){
        //cout<<result<<" ";
        answer += result;
    }
    cout<<"\n";

    cout<<answer<<"\n";

    return 0;
}