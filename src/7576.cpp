#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;
int result=0;
int answer = 0;

void DFS(queue<int>& node, vector<vector<short>>& arr);

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>M>>N;

    vector<vector<short>>arr;

    for(int i{0}; i < N; i++){

        vector<short>tmp;
        for(int j{0}; j < M; j++){

            short num;
            cin>>num;

            if(num == 0)
                result++;

            tmp.push_back(num);
        }
        arr.push_back(tmp);
    }

    if(result == 0){

        cout<<0<<"\n";
        return 0;
    }

    queue<int>node;

    for(int i{0}; i < N; i++){

        for(int j{0}; j < M; j++){

            if(arr[i][j] == 1)
                node.push(i*M + j);
        }
    }

    DFS(node, arr);

    if(result == 0)
        cout<<answer<<"\n";

    else
        cout<<-1<<"\n";

    return 0;
}

void DFS(queue<int>& node, vector<vector<short>>& arr){

    int size = node.size();

    for(int k{0}; k < size; k++){

        int start = node.front();
        node.pop();

        int row = start / M;
        int col = start % M;

        if(row == 0){

            if(arr[row + 1][col] == 0){

                arr[row + 1][col] = 1;
                result --;

                node.push((row + 1) * M + col);
            }

            if(col  != M -1 ){
                
                if(arr[row][col + 1] == 0){

                    arr[row][col + 1] = 1;
                    result --;

                    node.push(row* M + col + 1);
                }
            }

            if(col != 0){

                if(arr[row][col - 1] == 0){

                    arr[row][col-1] = 1;
                    result--;

                    node.push(row * M + col -1);
                }
            }

            continue;
        }

        else if(row == N - 1){

            if(arr[row-1][col] == 0){

                arr[row-1][col]=1;
                result--;

                node.push((row-1)*M + col);
            }

            if(col != M - 1){

                if(arr[row][col + 1] == 0){

                    arr[row][col + 1]=1;
                    result--;

                    node.push(row * M + col + 1);
                }
            }

            if(col != 0){

                if(arr[row][col - 1] == 0){

                    arr[row][col-1]=1;
                    result --;

                    node.push(row * M + col -1);
                }
            }

            continue;
        }

        else{

            if(arr[row - 1][col] == 0){

                arr[row-1][col]=1;
                result--;

                node.push((row-1) * M + col);
            }

            if(arr[row + 1][col] == 0){

                arr[row + 1][col] = 1;
                result --;

                node.push((row + 1) * M + col);
            }

            if(col != 0){

                if(arr[row][col - 1] == 0){

                    arr[row][col - 1]=1;
                    result--;

                    node.push(row * M  + col -1);
                }
            }
            
            if (col != M -1){

                if(arr[row][col + 1] == 0){

                    arr[row][col + 1]=1;
                    result--;

                    node.push(row * M + col + 1);
                }
            }

            continue;
        }
    }

    answer ++;

    if(result == 0)
        return;

    if(node.size() == 0)
        return;

    DFS(node, arr);
}