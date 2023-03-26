#include<iostream>
#include<vector>
#include<queue>
#define sync_with_stdio(false);
using namespace std;

int main(){

    cin.tie(NULL); cout.tie(NULL);

    int limit, size;
    cin >> limit >> size;

    vector<int>arr;
    for(int i{0}; i < size; i++){
        int num; cin >> num;
        arr.push_back(num);
    }

    vector<pair<int, int>> board;
    for(int i{0}; i < size; i++){
        int num_now = arr[i];
        
        int next_index = 100000000;
        for(int j{i + 1}; j < size; j++){
            if(arr[j] == num_now){
                next_index = j;
                break;
            }
        }

        board.push_back({next_index, num_now});
    }

    int answer = 0;
    vector<bool>check(size + 1, false);
    priority_queue<pair<int, int>>pq;
    for(int i{0}; i < size; i++){

        int size_now = pq.size();
        int next_index = board[i].first;
        int num_now = board[i].second;

        // 이미 꽂혀 있는 값의 인덱스 갱신
        if(check[num_now] == true){
            priority_queue<pair<int, int>>tmp;
            while(!pq.empty()){
                pair<int, int> top_now = pq.top();
                pq.pop();
                if(top_now.second == num_now){
                    top_now.first = next_index;
                }
                tmp.push(top_now);
            }
            pq = tmp;
            continue;
        }

        // 다음에 꽂을 인덱스가 가장 큰 값 제거
        if(size_now >= limit){
            int top_num = pq.top().second;
            pq.pop();
            check[top_num] = false;
            answer++;
        }

        pq.push({next_index, num_now});
        check[num_now] = true;
    }

    cout<<answer<<"\n";


    return 0;
}