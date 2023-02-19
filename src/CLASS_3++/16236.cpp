#include<iostream>
#include<vector>
#include<queue>
#define sync_with_stdio(false)
using namespace std;

int N;
int row, col, answer{0};
vector<int>fishes(7, 0);
vector<vector<int>>board;

void getInput(){
    cin.tie(NULL);
    cin >> N;

    for(int i{0}; i < N; i++){
        vector<int>tmp(N, 0);
        for(int j{0}; j < N; j++){
            int num; cin >> num;
            
            if(num == 9){
                row = i; col = j;
                num = 0;
            }

            tmp[j] = num;
            fishes[num]++;
        }
        board.push_back(tmp);
    }
}

bool checkIndexBound(int row_next, int col_next, int size_now){

    if(row_next >= 0 && row_next <= N - 1){
        if(col_next >= 0 && col_next <= N - 1){
            if(size_now >= board[row_next][col_next]){
                return true;
            }
        }
    }

    return false;
}

bool checkEat(int row_next, int col_next, int size_now){

    if(board[row_next][col_next] > 0 && board[row_next][col_next] < size_now){
        return true;
    }

    return false;
}

bool checkEnd(int size_now){

    if(size_now >= 7)
        size_now = 7;

    for(int i{1}; i < size_now; i++){
        if(fishes[i] > 0)
            return false;
    }

    return true;
}

int main(){

    getInput();

    int answer = 0;
    int size = 2;
    int exp = 0;
    int time = 0;
    if(checkEnd(size)){
        cout<<0<<"\n";
        return 0;
    }

    priority_queue<pair<int, int>>empty_pq;
    priority_queue<pair<int, int>>move_list;
    priority_queue<pair<int, int>>move_next_list;
    move_list.push({row * -1, col * -1});

    vector<vector<bool>>empty_vec;
    vector<vector<bool>>visited;
    for(int i{0}; i < N; i++){
        vector<bool>tmp(N, false);
        empty_vec.push_back(tmp);
        visited.push_back(tmp);
    }
    visited[row][col] = true;

    while(true){
        while(!move_list.empty()){
            int row_now = move_list.top().first * -1;
            int col_now = move_list.top().second * -1;
            move_list.pop();

            if(checkEat(row_now, col_now, size)){

                if(++exp == size){
                    exp = 0;
                    size++;
                }
            
                fishes[board[row_now][col_now]]--;
                board[row_now][col_now] = 0;
                answer += time;
                time = 0;
                if(checkEnd(size)){
                    cout<<answer<<"\n";
                    return 0;
                }

                while(!move_list.empty())
                    move_list.pop();
            
                while(!move_next_list.empty())
                    move_next_list.pop();

                visited = empty_vec;
            
                visited[row_now][col_now] = true;

                move_list.push({row_now * -1, col_now * -1});
                continue;
            }

            vector<pair<int, int>>move_next = {{row_now - 1, col_now}, {row_now, col_now - 1}, {row_now, col_now + 1}, {row_now + 1, col_now}};

            int row_next, col_next;
            for(auto next : move_next){
                row_next = next.first;
                col_next = next.second;

                if(checkIndexBound(row_next, col_next, size)){
                    if(visited[row_next][col_next] == false){
                        move_next_list.push({row_next * -1, col_next * -1});
                        visited[row_next][col_next] = true;
                    }
                }
            }
        }

        if(move_next_list.empty()){
            cout<<answer<<"\n";
            return 0;
        }

        time++;
        move_list = move_next_list;
        move_next_list = empty_pq;
    }

    return 0;
}