#include<iostream>
#include<vector>
using namespace std;

// board[i][j][k] = w(i-diff, j-diff, k-diff)
// w(a, b, c) = board[a+diff][b+diff][c+diff]
// board[0][0][0]=w(-50,-50,-50)
// board[100][100][100]=w(50, 50, 50)
// board[50][50][50]=w(0,0,0)

const int diff=50;
const int N=101;
int cnt=N*N*N;

int main(){

    vector<long long>tmp1(N, -1);
    vector<vector<long long>>tmp2(N, tmp1);
    vector<vector<vector<long long>>>board(N, tmp2);

    for(int i{0}; i<N; i++){
        
        for(int j{0}; j<N; j++){

            for(int k{0}; k<N; k++){

                if(i - diff <=0  || j - diff <= 0 || k - diff <= 0){

                    board[i][j][k]=1;
                    cnt--;
                }
            }
        }
    }

    while(cnt > 0){

        for(int i{0}; i<N; i++){

            for(int j{0}; j<N; j++){
                
                for(int k{0}; k<N; k++){

                    if(board[i][j][k] != -1)
                        continue;

                    else if(i - diff > 20 || j - diff > 20 || k - diff > 20){
                        
                        if(board[diff+20][diff+20][diff+20] != -1){
                            
                            board[i][j][k]=board[diff+20][diff+20][diff+20];
                            cnt--;
                        }
                        continue;
                    }

                    else if(i < j && j < k){

                        if( board[i][j][k-1] != -1 && board[i][j-1][k-1] != -1 && board[i][j-1][k] != -1){
                            board[i][j][k]=board[i][j][k-1] + board[i][j-1][k-1] - board[i][j-1][k];
                            cnt--;
                            continue;
                        }

                        continue;
                    }

                    else{
                        if(board[i-1][j][k] != -1 && board[i-1][j-1][k] != -1 && board[i-1][j][k-1] != -1 && board[i-1][j-1][k-1] != -1){
                            board[i][j][k]=board[i-1][j][k] + board[i-1][j-1][k] + board[i-1][j][k-1] - board[i-1][j-1][k-1];
                            cnt--;
                        }
                    }
                }
            }
        }
    }

    int a=0;
    int b=0;
    int c=0;

    cin>>a>>b>>c;

    while(a != -1 || b != -1 || c != -1){

        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<board[a+diff][b+diff][c+diff]<<endl;

        cin>>a>>b>>c;
    }
    return 0;
}