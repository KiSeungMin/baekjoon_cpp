#include<iostream>
#include<vector>
#include<queue>
#define sync_with_stdio(false);
using namespace std;

int row_limit , col_limit;
vector<vector<bool>>checked;
vector<vector<bool>>checked_broken;
vector<vector<bool>>arr;

bool canMove(int row, int col){
    if(row >= 0 && row < row_limit && col >= 0 && col < col_limit){
        return true;
    }

    return false;
}

int getAnswer(queue<vector<int>>& q){

    int dist = 1;
    while(!q.empty()){

        int size = static_cast<int>(q.size());

        for(int i{0}; i < size; i++){
            vector<int> front = q.front(); q.pop();
            int row_now = front[0];
            int col_now = front[1];
            int is_broken = front[2];

            if(row_now == row_limit - 1 && col_now == col_limit - 1){
                return dist;
            }

            vector<pair<int, int>> next_point = {{row_now - 1, col_now}, {row_now + 1, col_now}, {row_now, col_now - 1}, {row_now, col_now + 1}};

            for(auto next : next_point){
                int row_next = next.first;
                int col_next = next.second;
                bool can_move = canMove(row_next, col_next);

                if(can_move){

                    if(is_broken){
                        if(arr[row_next][col_next] == false){
                            if(checked_broken[row_next][col_next] == false){
                                checked_broken[row_next][col_next] = true;
                                q.push({row_next, col_next, 1});
                            }
                        }
                    }

                    else{
                        if(arr[row_next][col_next] == true){
                            if(checked_broken[row_next][col_next] == false){
                                checked_broken[row_next][col_next] = true;
                                q.push({row_next, col_next, 1});
                            }
                        }
                        else{
                            if(checked[row_next][col_next] == false){
                                checked[row_next][col_next] = true;
                                q.push({row_next, col_next, 0});
                            }
                        }
                    }
                }
            }
        }
        dist++;        
    }

    if(q.empty()){
        return -1;
    }
    else{
        return dist;
    }
}

int main(){
    cin.tie(NULL);
    cin >> row_limit >> col_limit;
  
    for(int i{0}; i < row_limit; i++){
        string str; cin >> str;
        vector<bool>tmp;
        for(int j{0}; j < col_limit; j++){
            tmp.push_back(str[j] == '1' ? true : false);
        }
        arr.push_back(tmp);
    }

    for(int i{0}; i < row_limit; i++){
        vector<bool>tmp(col_limit, false);
        checked.push_back(tmp);
        checked_broken.push_back(tmp);
    }

    checked[0][0] = true;
    queue<vector<int>> q;
    q.push({0, 0, 0});

    cout<<getAnswer(q)<<"\n";

    return 0;
}