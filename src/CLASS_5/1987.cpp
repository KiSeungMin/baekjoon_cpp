#include<iostream>
#include<vector>
using namespace std;

int row_limit, col_limit;
vector<bool>check(26, false);
vector<vector<char>>board;
int answer = 0;

bool canMove(int row_next, int col_next){

    if(row_next >= 0 && row_next < row_limit && col_next >= 0 && col_next < col_limit){

        char c_next = board[row_next][col_next];
        int index_next = static_cast<int>(c_next - 'A');

        if(check[index_next] == false){
            return true;
        }
    }

    return false;
}

void DFS(int row_now, int col_now, int dist){

    char c_now = board[row_now][col_now];
    int index_now = static_cast<int>(c_now - 'A');
    check[index_now] = true;

    vector<pair<int , int>> next_points = {{row_now - 1, col_now}, {row_now + 1, col_now}, {row_now ,col_now - 1}, {row_now, col_now + 1}};
    for(auto next_point : next_points){

        int row_next = next_point.first;
        int col_next = next_point.second;

        if(canMove(row_next, col_next)){
            DFS(row_next, col_next, dist + 1);
        }
    }
    check[index_now] = false;

    if(dist > answer){
        answer = dist;
    }
}

int main(){

    cin >> row_limit >> col_limit;
    for(int i{0}; i < row_limit; i++){
        string str; cin >> str;

        vector<char>tmp;
        for(int j{0}; j < col_limit; j++){
            tmp.push_back(str[j]);
        }
        board.push_back(tmp);
    }

    DFS(0, 0, 1);
    cout<<answer<<endl;

    return 0;
}