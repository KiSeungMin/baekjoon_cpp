#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){

    int T;
    cin>>T;

    for(int i{0}; i < T; i++){

        int N, M;
        cin>>N>>M;

        queue<pair<int, int>> que;

        // 점수 별로 몇 개의 작업이 있는지 저장하는 벡터
        vector<int>score(9, 0);

        for(int j{0}; j < N; j++){

            int num;
            cin>>num;

            score[num-1]++;

            //  첫 번째 인수는 작업의 우선순위, 두 번째 인수는 작업의 인덱스
            pair<int,int>tmp={num, j};
            que.push(tmp);
        }

        int max=0;
        for(int j{8}; j>=0; j--){
            if(score[j] > 0){
                max=j+1;
                break;
            }
        }

        int answer=0;

        while(true){

            // 현재 작업의 우선순위가 우선순위 최댓값이라면

            if(que.front().first == max){

                // 찾고자하는 인덱스 값이라면
                if(que.front().second == M){

                    cout<<answer+1<<endl;
                    break;
                } 

                // 아닐 경우 큐에서 제거하고 우선순위 최댓값 재설정
                else{

                    answer++;
                    score[que.front().first-1]--;
                    que.pop();

                    for(int j{max-1}; j >=0; j--){

                        if(score[j] > 0){
                            max = j+1;
                            break;
                        }
                    }
                }
            }

            // 작업의 우선순위가 우선순위 최댓값이 아니면 큐의 최하위로 이동
            else{
                que.push(que.front());
                que.pop();
            }
        }
    }

    return 0;
}