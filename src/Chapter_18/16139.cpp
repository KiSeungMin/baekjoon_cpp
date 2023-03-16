#include<iostream>
#include<vector>
#include<string>
#define sync_with_stdio(false)
using namespace std;

int main(){

    cin.tie(NULL); cout.tie(NULL);

    string input_str;
    cin>>input_str;

    int limit = input_str.length();
    const int alphabet_limit = 26;
    vector<int>alphabet_count(alphabet_limit, 0);

    vector<int>tmp_arr(limit, 0);
    vector<vector<int>>board(alphabet_limit, tmp_arr);      

    for(int i{0}; i < limit; i++){
        char s = input_str[i];
        int index = s - 'a';
        int count;

        if(alphabet_count[index] == 0){
            alphabet_count[index]++;
            count = alphabet_count[index];

            board[index][i] = count;
        }
        else if(alphabet_count[index] > 0){
            alphabet_count[index]++;
            count = alphabet_count[index];

            board[index][i] = count;

            // 현재 인덱스보다 작은 값들에 대해 현재 값 - 1 대입
            int j = i - 1;
            while(board[index][j] == 0){
                board[index][j] = count - 1;
                j--;
            }
        }
    }

    for(int i{0}; i < alphabet_limit; i++){
        if(alphabet_count[i] == 0)
            continue;

        int count = alphabet_count[i];
        int j = limit - 1;
        while(board[i][j] == 0){
            board[i][j] = count;
            j--;
        }
    }

    int M; cin>>M;
    for(int i{0}; i < M; i++){
        char alphabet;
        int start, end; 
        cin>>alphabet>>start>>end;

        int index = alphabet - 'a';

        if(start == 0){
            cout<<board[index][end]<<"\n";
        } else{
            cout<<board[index][end] - board[index][start - 1]<<"\n";
        }
    }

    return 0;
}