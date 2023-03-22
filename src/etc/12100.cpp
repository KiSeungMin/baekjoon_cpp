#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

int N;
long long answer = 0;

void goNext(int level, vector<vector<long long>> board);

void goLeft(int level, vector<vector<long long>>board){

    for(int i{0}; i < N; i++){
        int limit = 0;
        for(int j{1}; j < N; j++){
            long long value = board[i][j];
            if(value == 0){
                continue;
            }

            if(value > answer)
                answer = value;

            int nextIndex = j - 1;
            while(nextIndex > limit && board[i][nextIndex] == 0){
                nextIndex--;
            }
    
            int curIndex = nextIndex + 1;
            board[i][j] = 0;
            board[i][curIndex] = value;

            if(board[i][nextIndex] == 0){
                board[i][nextIndex] = value;
                board[i][curIndex] = 0;
            } else if(board[i][nextIndex] == value){
                board[i][nextIndex] *= 2;
                board[i][curIndex] = 0;
                
                limit = curIndex;

                if(value * 2 > answer)
                    answer = value * 2;
            }
        }
    }

    if(level == 5)
        return;

    goNext(level + 1, board);
}

void goRight(int level, vector<vector<long long>>board){
    
    for(int i{0}; i < N; i++){
        int limit = N - 1;
        for(int j{N - 2}; j >= 0; j--){
            long long value = board[i][j];

            if(value == 0){
                continue;
            }

            if(value > answer)
                answer = value;

            int nextIndex = j + 1;
            while(nextIndex < limit && board[i][nextIndex] == 0){
                nextIndex++;
            }

            int curIndex = nextIndex - 1;
            board[i][j] = 0;
            board[i][curIndex] = value;

            if(board[i][nextIndex] == 0){
                board[i][nextIndex] = value;
                board[i][curIndex] = 0;
            } else if(board[i][nextIndex] == value){
                board[i][nextIndex] *= 2;
                board[i][curIndex] = 0;

                limit = curIndex;

                if(value * 2 > answer)
                    answer = value * 2;
            }
        }
    }

    if(level == 5)
        return;

    goNext(level + 1, board);
}

void goUp(int level, vector<vector<long long>>board){
    
    for(int j{0}; j < N; j++){
        int limit = 0;
        for(int i{1}; i < N; i++){
            
            long long value = board[i][j];

            if(value == 0){
                continue;
            }

            if(value > answer)
                answer = value;

            int nextIndex = i - 1;
            while(nextIndex > limit && board[nextIndex][j] == 0){
                nextIndex--;
            }

            int curIndex = nextIndex + 1;
            board[i][j] = 0;
            board[curIndex][j] = value;

            if(board[nextIndex][j] == 0){
                board[nextIndex][j] = value;
                board[curIndex][j] = 0;
            } else if(board[nextIndex][j] == value){
                board[nextIndex][j] *= 2;
                board[curIndex][j] = 0;

                limit = curIndex;

                if(value * 2 > answer)
                    answer = value * 2;
            }
        }
    }

    if(level == 5)
        return;

    goNext(level + 1, board);
}

void goDown(int level, vector<vector<long long>>board){

    for(int j{0}; j < N; j++){
        int limit = N - 1;
        for(int i{N - 2}; i >= 0; i--){
            long long value = board[i][j];

            if(value == 0){
                continue;
            }

            if(value > answer)
                answer = value;

            int nextIndex = i + 1;
            while(nextIndex < limit && board[nextIndex][j] == 0){
                nextIndex++;
            }

            int curIndex = nextIndex - 1;
            board[i][j] = 0;
            board[curIndex][j] = value;

            if(board[nextIndex][j] == 0){
                board[nextIndex][j] = value;
                board[curIndex][j] = 0;
            } else if(board[nextIndex][j] == value){
                board[nextIndex][j] *= 2;
                board[curIndex][j] = 0;

                limit = curIndex;

                if(value * 2 > answer)
                    answer = value * 2;
            }
        }
    }
    
    if(level == 5)
        return;

    goNext(level + 1, board);
}

void goNext(int level, vector<vector<long long>> board){

    goLeft(level, board);
    goRight(level, board);
    goUp(level, board);
    goDown(level, board);
}

int main(){

    cin.tie(NULL);

    cin >> N;
    vector<vector<long long>>board;

    for(int i{0}; i < N; i++){
        vector<long long>tmp;

        for(int j{0}; j < N; j++){
            long long num; cin >> num;
            tmp.push_back(num);
        }
        board.push_back(tmp);
    }

    goNext(1, board);

    cout<<answer<<"\n";

    return 0;
}