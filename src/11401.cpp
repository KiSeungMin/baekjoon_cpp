#include<iostream>
#include<vector>
using namespace std;

// nCk = n-1 C k-1 + n-1 C k 

const long long mod = 1000000007;

int main(){

    int N, K;
    cin>>N>>K;

    vector<long long>factorial;

    factorial.push_back(1);
    factorial.push_back(1);

    for(long long i{2}; i <= N; i++){

        long long result = factorial[i-1] * i;
        result = result % mod;
        factorial.push_back(result);
    }

    long long answer = factorial[N] / (((factorial[N-K]) * (factorial[K])) % mod);

    cout<<answer<<endl;
    
    return 0;
}


    /*
    vector<vector<int>>board;

    for(int i{0}; i < N + 1; i++){

        vector<int>tmp;

        if(i == 0){
            tmp.push_back(0);
            board.push_back(tmp);
            continue;
        }

        else if(i ==1){
            tmp.push_back(1);
            tmp.push_back(1);
            board.push_back(tmp);
            continue;
        }

        else{

            for(int j{0}; j <= K; j++){

                if(j == 0)
                    tmp.push_back(1);

                else if(j==1)
                    tmp.push_back(i);

                else if(j == i){
                    tmp.push_back(1);
                    board.push_back(tmp);
                    break;
                }

                else if(j == K){
                    int result=board[i-1][j-1] + board[i-1][j];
                    result=result % 1000000007;
                    tmp.push_back(result);
                    board.push_back(tmp);
                    break;
                }

                else{
                    int result = board[i-1][j-1] + board[i-1][j];
                    result=result % 1000000007;
                    tmp.push_back(result);
                }
            }
        }
    }
    cout<<board[N][K]<<endl;

    return 0;
}

*/