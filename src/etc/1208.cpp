#include<iostream>
#include<vector>
using namespace std;

const int center = 4000000;
const int limit = 8000001;
vector<long long>board(limit, 0);

int main(){

    int N, goal;
    cin >> N >> goal;

    int start_index = center;
    int end_index = center;

    for(int i{0}; i < N; i++){
        int num; cin >> num;

        if(num < 0){
            for(int index{start_index}; index <= end_index; index++){

                if(board[index] != 0){
                    board[index + num] += board[index];
                }
            }

            start_index += num;
        }
        else if(num >= 0){
            for(int index{end_index}; index >= start_index; index--){

                if(board[index] != 0){
                    board[index + num] += board[index];
                }
            }

            end_index += num;
        }

        board[center + num]++;
    } 

    cout<<board[center + goal]<<endl;

    return 0;
}